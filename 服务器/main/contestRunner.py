import threading,time,pymysql

class InContestUser():
    def __init__(self,ICU_id,uid):
        self.ICU_id   = ICU_id          # int
        self.user_id  = uid             # int
        self.user_name= "user1"         # string
        self.score    = 0               # int
        self.penalty  = 0               # int
        self.solved   = []          
        self.attemped = []        
    
    def toString(self):
        return "\t".join([self.user_name,str(self.score),str(self.penalty)])

class InContestProblem():
    def __init__(self,ICP_id,pro_id):
        self.ICP_id    = ICP_id         # int
        self.pro_id    = pro_id         # int
        self.title     = "problem"      # string
        self.submit    = 0              # int
        self.solved    = 0              # int
    
    def toString(self):
        return "\t".join([str(self.ICP_id+1),str(self.title),str(self.submit),str(self.solved)])

class InContestStatus():
    def __init__(self,ICS_id,ICP_id,ICU_id,time,result,lang):
        self.ICS_id = ICS_id       # int
        self.ICP_id = ICP_id       # int
        self.ICU_id = ICU_id       # int
        self.time   = time         # int
        self.result = result       # string
        self.lang   = lang         # string

    def toString(self):
        return "\t".join([str(self.ICS_id),str(self.ICP_id),str(self.ICU_id),str(self.time),self.lang,self.result])


class Contest(threading.Thread):
    def __init__(self,contest_id,contest_owner,contest_group,contest_start_time,contest_length,contest_title,contest_type,contest_status,participent,contest_problem,status):
        threading.Thread.__init__(self) 
        self.contest_id         = contest_id        # int
        self.contest_owner      = contest_owner     # int
        self.contest_group      = contest_group     # int
        self.start_time         = contest_start_time# int
        self.contest_length     = contest_length    # int
        self.contest_title      = contest_title     # string
        self.contest_type       = contest_type      # string
        self.contest_status     = contest_status    # string
        self.participent        = participent       # list(ICU)
        self.problem            = []                # list(ICP)
        for ICP_id,pro_id in enumerate(contest_problem.split("::")):
            self.problem.append(InContestProblem(ICP_id,pro_id))
        self.status             = status            # list(ICS)
    def run(self):
        print("contest:"+self.contest_title+" is running now!")
        print(self.toString())
    
    def submit_code(self,uid,ICP_id):
        print(uid,ICP_id)
    
    def toString(self):
        return "contest\tbegin_time\tlength\n"+"\t".join([self.contest_title,str(self.start_time),str(self.contest_length)])+"\npro_id\tproblem\tsubmit\tsolved\n"+"\n".join([x.toString() for x in self.problem])

class ContestRunner(threading.Thread):
    def __init__(self,conn): 
        threading.Thread.__init__(self)
        self.conn = conn
        self.cursor  = conn.cursor()
        self.pending_contest = []                   # list(int)
        self.running_contest = []                   # list(int)
        self.ended_contest   = [-1]                 # list(int)
        self.process         = []                   # list(thread)

    def run(self):
        while(True):
            self.cursor.execute("select * from contest where contest_id not in ("+','.join([str(x) for x in self.pending_contest+self.running_contest+self.ended_contest])+");")
            rs = self.cursor.fetchall()
            if(rs != ()):
                for r in rs:
                    self.pending_contest.append(r[0])
            print(self.pending_contest)
            if(self.pending_contest != []):
                for contest in self.pending_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    if(rs[3] <= int(time.time())):
                        self.running_contest.append(contest)
                        self.pending_contest.remove(contest)
                        self.process.append((contest,Contest(rs[0],rs[1],rs[2],rs[3],rs[4],rs[5],rs[6],"running",[],rs[9],[])))
                        self.process[-1][1].run()
                        #self.process[-1][1].submit_code(1,0);


            if(self.running_contest != []):
                for contest in self.running_contest:
                    self.cursor.execute("select * from contest where contest_id = "+str(contest)+";")
                    rs = self.cursor.fetchone()
                    if(rs[3]+rs[4] <= int(time.time())):
                        self.running_contest.remove(contest)
                        self.ended_contest.append(contest)
                        self.process[[x[0] for x in self.process].index(contest)][1].exit()
            time.sleep(5)


conn = pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8')
CR = ContestRunner(conn)
CR.run()
