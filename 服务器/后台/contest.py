import sys
sys.path.append('/root/Onlinejudge-c/')
from judger import *
import threading,time,pymysql,random

class InContestUser():
    def __init__(self,ICU_id,uid,cursor):
        self.ICU_id   = ICU_id          # int
        self.user_id  = uid             # int
        cursor.execute("select user_nickname from User where user_id="+str(uid)+";")
        rs = cursor.fetchone()
        self.user_name= rs[0]           # string
        self.score    = 0               # int
        self.penalty  = 0               # int
        self.solved   = {}              # dic(int,int)
        self.attemped = {}              # dic()
        self.toString()

    def toString(self):
        return ":::".join([self.user_name,str(self.score),str(self.penalty)])

class InContestProblem():
    def __init__(self,ICP_id,pro_id,cursor):
        self.ICP_id    = ICP_id         # int
        self.pro_id    = pro_id         # int
        cursor.execute("select pro_title,pro_description from problem where pro_id="+pro_id+";")
        rs = cursor.fetchone()
        self.title     = rs[0]          # string
        self.des       = rs[1]          # string
        self.submit    = 0              # int
        self.solved    = 0              # int
    
    def show(self):
        return "&&&".join([str(self.ICP_id),self.title+"&&&","submit: "+str(self.submit)+":::"+"solved: "+str(self.solved)+"&&&",self.des])

    def toString(self):
        return ":::".join([str(self.ICP_id),str(self.title),str(self.submit),str(self.solved)])
    
class InContestStatus():
    def __init__(self,ICS_id,ICP_id,ICU_id,result,lang,title,user_name):
        self.ICS_id = ICS_id       # int
        self.ICP_id = ICP_id       # int
        self.ICU_id = ICU_id       # int
        self.pro_title = title
        self.user_name = user_name
        self.time   = time.strftime("%H:%M:%S")
        self.result = result       # string
        self.lang   = lang         # string

    def toString(self):
        msg =  ":::".join([str(self.ICS_id),self.pro_title,self.user_name,self.time,self.lang,self.result])
        return msg

class Contest(threading.Thread):
    def __init__(self,contest_id,contest_owner,contest_group,contest_start_time,contest_length,contest_title,contest_type,contest_status,contest_problem,conn):
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
        self.conn               = pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8')
        self.cursor             = self.conn.cursor()
        for ICP_id,pro_id in enumerate(contest_problem.split("::")):
            self.problem[ICP_id+1] = InContestProblem(ICP_id+1,pro_id,conn.cursor())
        self.conn.commit()
        self.record()
    
    def run(self):
        self.contest_status = "running"
        self.conn.commit()
        self.cursor.execute("update contest set contest_status = 'running' where contest_id="+str(self.contest_id)+";")
        self.conn.commit()
        print("contest:"+self.contest_title+" is running now! "+time.strftime("%d %H:%M:%S"))
    
    def exit(self):
        self.contest_status = "ended"
        self.cursor.execute("update contest set contest_status = 'ended' where contest_id="+str(self.contest_id)+";")
        self.conn.commit()
        self.record()
        self.conn.close()
        print("contest:"+self.contest_title+" is ended now! "+time.strftime("%d %H:%M:%S"))
    
    def submit_code(self,uid,ICP_id,code,lang):
        #print("-------debug0-------")
        if(uid not in self.participent.keys()):
            self.participent[uid] = InContestUser(len(self.participent.keys()),uid,self.conn.cursor())
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
        #print("-------debug1-------")
        self.status.append(InContestStatus(len(self.status),ICP_id,self.participent[uid].ICU_id,result,lang,self.problem[ICP_id].title,self.participent[uid].user_name))
        #print("-------debug2-------")
        try:
            self.record()
        except:
            raise
        #print("-------debug3-------")
        #print(self.status[-1].toString())
        return self.status[-1].toString()
    
    def record(self):
        self.cursor.execute("update contest set contest_rank = '"+self.show_rank()+"',contest_judge = '"+self.show_status()+"',contest_summary = '"+self.summary()+"',contest_string = '"+self.toString()+"' where contest_id = "+str(self.contest_id)+";")
        self.conn.commit()

    def toString(self):
        msg =":::".join([self.contest_title,time.strftime("%m-%d %H:%M",time.gmtime(self.start_time+28800)),str(int(self.contest_length/(60*60*24)))+" d "+str(int((self.contest_length%(24*60*60))/3600))+" h "+str(int((self.contest_length%3600)/60))+" m",self.contest_status])+"&&&&&&"+"&&&".join([x[1].toString() for x in self.problem.items()])
        return msg

    def summary(self):
        msg = ":::".join([str(self.contest_id),self.contest_title,time.strftime("%m-%d %H:%M",time.gmtime(self.start_time+28800)),str(int(self.contest_length/(60*60*24)))+" d "+str(int((self.contest_length%(24*60*60))/3600))+" h "+str(int((self.contest_length%3600)/60))+" m",self.contest_status,str(self.contest_owner),str(self.contest_group)])
        return msg

    def show_rank(self):         
        res = []
        for rank,user in enumerate(sorted(self.participent.items(),key = lambda x :(-(x[1].score),x[1].penalty))):
            res.append(":::".join([str(rank),user[1].user_name,str(user[1].score),str(user[1].penalty)]))
        msg = "&&&".join(res)
        #print("---debug----",msg)
        return msg
    
    def show_status(self):
        msg = "&&&".join([status.toString() for status in self.status[::-1]])
        return msg

    def reactive(self):
        print(time.strftime("%H:%M:%S"),self.contest_id," reactived!!")
        self.cursor.execute("select contest_title from contest where contest_id = "+str(self.contest_id)+";")
        self.cursor.fetchone()
        self.conn.commit()

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
        count = 0
        while(True):
            self.refresh()
            if(count == 1200):
                print("reactive contests")
                count = 0
                for contest in self.running_contest:
                    self.contests[contest].reactive()
            count += 1

    def refresh(self):
        if ( 1 == 1 ):
            self.cursor.execute("select * from contest where contest_id not in ("+','.join([str(x) for x in self.pending_contest+self.running_contest+self.ended_contest])+");")
            rs = self.cursor.fetchall()
            self.conn.commit()
            if(rs != ()):
                for r in rs:
                    self.pending_contest.append(r[0])
            tmp = []
            if(self.pending_contest != []):
                for contest in self.pending_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    self.conn.commit()
                    if(rs[3] <= int(time.time())):
                        self.running_contest.append(contest)
                        tmp.append(contest)
                        self.contests[contest]=Contest(rs[0],rs[1],rs[2],rs[3],rs[4],rs[5],rs[6],"running",rs[9],self.conn)
                        self.contests[contest].start()
                    else:
                        Contest(rs[0],rs[1],rs[2],rs[3],rs[4],rs[5],rs[6],"pending",rs[9],self.conn).record()
            for contest in tmp: 
                self.pending_contest.remove(contest)
            tmp = []
            if(self.running_contest != []):
                for contest in self.running_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    self.conn.commit()
                    if(rs[3]+rs[4] <= int(time.time())):
                        tmp.append(contest)
                        #self.running_contest.remove(contest)
                        self.ended_contest.append(contest)
                        self.contests[contest].exit()
                        self.contests.pop(contest)
            for contest in tmp: 
                self.running_contest.remove(contest)
            time.sleep(6)
    
    def submit_code(self,contest_id,uid,ICP_id,code,lang):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].submit_code(uid,ICP_id,code,lang)
        else:
            return "This contest is not running now."

    def view_contests(self):
        self.cursor.execute("select contest_summary from contest;")
        rs = self.cursor.fetchall()
        self.conn.commit()
        msg = "&&&".join([summary[0] for summary in rs])
        return msg

    def view_contest(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].toString()
        elif(contest_id in self.pending_contest or contest_id in self.ended_contest):
            self.cursor.execute("select contest_string from contest where contest_id = "+str(contest_id)+";")
            rs = self.cursor.fetchone()
            self.conn.commit()
            return rs[0]
        else:
            return "Contest not found!"
    
    def view_rank(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].show_rank()
        elif(contest_id in self.pending_contest or contest_id in self.ended_contest):
            self.cursor.execute("select contest_rank from contest where contest_id = "+str(contest_id)+";")
            rs = self.cursor.fetchone()
            self.conn.commit()
            return rs[0]
        else:
            return "None"
    
    def view_status(self,contest_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].show_status()
        elif(contest_id in self.pending_contest or contest_id in self.ended_contest):
            self.cursor.execute("select contest_judge from contest where contest_id = "+str(contest_id)+";")
            rs = self.cursor.fetchone()
            self.conn.commit()
            return rs[0]
        else:
            return "None"

    def view_problem(self,contest_id,ICP_id):
        if(contest_id in self.contests.keys()):
            return self.contests[contest_id].problem[ICP_id].show()
        else:
            return "This contest is not running."
