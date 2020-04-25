import sys
sys.path.append('/root/Onlinejudge-c/')
from judger import *
import threading,time,pymysql,random

class InContestUser():
    def __init__(self,ICU_id,uid):
        self.ICU_id   = ICU_id          # int
        self.user_id  = uid             # int
        self.user_name= "user1"         # string
        self.score    = 0               # int
        self.penalty  = 0               # int
        self.solved   = {}              # dic(int,int)
        self.attemped = {}              # dic()
    
    def toString(self):
        return "\t".join([self.user_name,str(self.score),str(self.penalty)])

class InContestProblem():
    def __init__(self,ICP_id,pro_id,pro_title,pro_des):
        self.ICP_id    = ICP_id         # int
        self.pro_id    = pro_id         # int
        self.title     = pro_title      # string
        self.des       = pro_des        # string
        self.submit    = 0              # int
        self.solved    = 0              # int
    
    def show(self):
        return "\n".join([str(self.ICP_id),self.title,"submit: "+str(self.submit)+"\t solved: "+str(self.solved),self.des])+"\n"

    def toString(self):
        return "\t".join([str(self.ICP_id+1),str(self.title),str(self.submit),str(self.solved)])
    
class InContestStatus():
    def __init__(self,ICS_id,ICP_id,ICU_id,result,lang):
        self.ICS_id = ICS_id       # int
        self.ICP_id = ICP_id       # int
        self.ICU_id = ICU_id       # int
        self.time   = str(time.localtime().tm_hour)+":"+str(time.localtime().tm_min)+":"+str(time.localtime().tm_sec)
        self.result = result       # string
        self.lang   = lang         # string

    def toString(self):
        return "\t".join([str(self.ICS_id),str(self.ICP_id),str(self.ICU_id),str(self.time),self.lang,self.result])+"\n"


class Contest(threading.Thread):
    def __init__(self,contest_id,contest_owner,contest_group,contest_start_time,contest_length,contest_title,contest_type,contest_status,contest_problem):
        threading.Thread.__init__(self) 
        self.contest_id         = contest_id        # int
        self.contest_owner      = contest_owner     # int
        self.contest_group      = contest_group     # int
        self.start_time         = contest_start_time# int
        self.contest_length     = contest_length    # int
        self.contest_title      = contest_title     # string
        self.contest_type       = contest_type      # string
        self.contest_status     = contest_status    # string
        self.participent        = {}                # list(ICU)
        self.problem            = {}                # list(ICP)
        self.status             = []                # list(ICS)
        for ICP_id,pro_id in enumerate(contest_problem.split("::")):
            self.problem[ICP_id] = InContestProblem(ICP_id,pro_id,"problem1","1+1 = ? ")
    
    def run(self):
        print("contest:"+self.contest_title+" is running now! "+str(time.localtime().tm_hour)+":"+str(time.localtime().tm_min)+":"+str(time.localtime().tm_sec))
        #print(self.toString())
    
    def submit_code(self,uid,ICP_id,code,lang):
        if(uid not in self.participent.keys()):
            self.participent[uid] = InContestUser(len(self.participent.keys()),0)
        result = Judger.judge(self.problem[ICP_id].pro_id,code)
        if(ICP_id not in self.participent[uid].solved.keys()):
            if(ICP_id not in self.participent[uid].attemped.keys()):
                self.participent[uid].attemped[ICP_id] = 1
            else:
                self.participent[uid].attemped[ICP_id] += 1
            self.participent[uid].penalty += int(time.time())-self.start_time
            if(result == 'AC'):
                self.participent[uid].solved[ICP_id] = self.participent[uid].attemped.pop(ICP_id)
                self.problem[ICP_id].solved += 1
                self.participent[uid].score += 1
            else:
                self.participent[uid].penalty += 1200
            self.problem[ICP_id].submit += 1
        self.status.append(InContestStatus(len(self.status),ICP_id,self.participent[uid].ICU_id,result,lang))
        return self.status[-1].toString()

    def toString(self):
        return "contest\tbegin_time\tlength\n"+"\t".join([self.contest_title,str(self.start_time),str(self.contest_length)])+"\npro_id\tproblem\tsubmit\tsolved\n"+"\n".join([x[1].toString() for x in self.problem.items()])
    
    def show_rank(self):
        ranked = sorted(self.participent.items(),key = lambda x :(-(x[1].score),x[1].penalty))
        res = ""
        for rank,user in enumerate(ranked):
            res += "\t".join([str(rank),"user1",str(user[1].score),str(user[1].penalty)])+"\n"
        return res

    def show_status(self):
        res = ""
        for status in self.status[::-1]:
            res += status.toString()
        return res

class ContestRunner(threading.Thread):
    def __init__(self,conn): 
        threading.Thread.__init__(self)
        self.conn = conn
        self.cursor  = conn.cursor()
        self.pending_contest = []                   # list(int)
        self.running_contest = []                   # list(int)
        self.ended_contest   = [-1]                 # list(int)
        self.contests        = {}                   # dic(thread)

    def run(self):
        while(True):
            self.cursor.execute("select * from contest where contest_id not in ("+','.join([str(x) for x in self.pending_contest+self.running_contest+self.ended_contest])+");")
            rs = self.cursor.fetchall()
            if(rs != ()):
                for r in rs:
                    self.pending_contest.append(r[0])
            # print("pending contests : ",self.pending_contest)
            if(self.pending_contest != []):
                for contest in self.pending_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    if(rs[3] <= int(time.time())):
                        self.running_contest.append(contest)
                        self.pending_contest.remove(contest)
                        self.contests[contest]=Contest(rs[0],rs[1],rs[2],rs[3],rs[4],rs[5],rs[6],"running",rs[9])
                        self.contests[contest].start()
                        # self.contests[contest].submit_code(1,0)
                        # print(self.contests[contest].show_rank())

            if(self.running_contest != []):
                for contest in self.running_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    if(rs[3]+rs[4] <= int(time.time())):
                        self.running_contest.remove(contest)
                        self.ended_contest.append(contest)
                        self.contests[contest].exit()
                        self.contests.pop(contest)
            time.sleep(5)
    
    def submit_code(self,contest_id,uid,ICP_id,code,lang):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].submit_code(uid,ICP_id,code,lang)
        else:
            return "This contest is not running."

    def view_contest(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].toString()
        else:
            return "This contest is not running."
    
    def view_rank(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].show_rank()
        else:
            return "This contest is not running."
    
    def view_status(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].show_status()
        else:
            return "This contest is not running."

    def view_problem(self,contest_id,ICP_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].problem[ICP_id].show()
        else:
            return "This contest is not running."

