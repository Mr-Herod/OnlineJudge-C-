import sys
sys.path.append("/root/Onlinejudge-c/")
import socket,threading,time,pymysql
from contest import *
from problem import *


class OjServer(threading.Thread):
    def __init__(self,threadID,name,ss,CR,conn,client):
        threading.Thread.__init__(self)
        self.threadID = threadID            # threadID   
        self.name = name                    # server name
        self.ss = ss                        # server socket
        self.CR = CR                        # ContestRunner
        self.cursor = conn.cursor()         # mysql cursor
        self.conn = conn                    # mysql connection
        self.client = client                # conneted client

    def run(self):
        try:
            while(True):
                msg = bytes.decode(self.ss.recv(10024))
                print(time.strftime("%H:%M:%S"),"client",self.client,":",msg)
                if(msg == ""):
                    self.ss.close()
                    break
                info = msg.split(':::')
                if(info[0] == "create_user"):
                    self.create_user(info[1:])
                elif(info[0] == "create_group"):
                    self.create_group(info[1:])
                elif(info[0] == "create_contest"):
                    self.create_contest(info[1:])
                elif(info[0] == "update_user"):
                    self.update_user(info[1:])
                elif(info[0] == "update_group"):
                    self.update_group(info[1:])
                elif(info[0] == "update_contest"):
                    self.update_contest(info[1:])
                elif(info[0] == "get_user"):
                    self.get_info("User")
                elif(info[0] == "get_group"):
                    self.get_info("groups")
                elif(info[0] == "get_contest"):
                    self.get_info("contest")
                elif(info[0] == "get_problem"):
                    self.get_info("problem")
                elif(info[0] == "submit_code"):
                    self.submit_code(info[1:])
                elif(info[0] == "view_contests"):
                    self.view_contests()
                elif(info[0] == "IC_view_contest"):
                    self.IC_view_contest(info[1:])
                elif(info[0] == "IC_view_problem"):
                    self.IC_view_problem(info[1:])
                elif(info[0] == "IC_view_status"):
                    self.IC_view_status(info[1:])
                elif(info[0] == "IC_view_rank"):
                    self.IC_view_rank(info[1:])
                elif(info[0] == "IC_submit_code"):
                    self.IC_submit_code(info[1:])
                elif(info[0] == "exit"):
                    self.ss.close()
                    self.conn.close()
                    break
                else:
                    self.ss.close()
                    self.conn.close()
                    break

        except:
            self.ss.close()
    
    def create_user(self,info):
        self.cursor.execute("insert into User values(0,'"+info[0]+"','"+info[1]+"','"+info[2]+"',' ',' ',' ',' ',' ',' ',' ',' ');")
        self.conn.commit()
        self.send("succeeded")

    def create_group(self,info):
        self.cursor.execute("insert into groups values(0,"+info[0]+",'"+info[1]+"',' ',' ');")
        self.conn.commit()
        self.send("succeeded")
    
    def create_contest(self,info):
        self.cursor.execute("insert into contest values(0,"+info[0]+","+info[1]+","+info[2]+","+info[3]+",'"+info[4]+"','"+info[5]+"','pending',' ','"+info[6]+"',' ');")
        self.conn.commit()
        self.send("succeeded")
    
    def update_user(self,info):
        self.cursor.execute("update User set "+info[0]+"='"+info[2]+"' where user_id = "+info[1]+";");
        self.conn.commit()
        self.send("succeeded")

    def update_group(self,info):
        self.cursor.execute("update groups set "+info[0]+"='"+info[2]+"' where group_id = "+info[1]+";");
        self.conn.commit()
        self.send("succeeded")
    
    def update_contest(self,info):
        self.cursor.execute("update contest set "+info[0]+"='"+info[2]+"' where contest_id = "+info[1]+";");
        self.conn.commit()
        self.send("succeeded")
    
    def submit_code(self,info):
        self.send(Problem.submit_code(int(info[0]),int(info[1]),info[2]))

    def view_contests(self):
        self.send(self.CR.view_contests())

    def IC_submit_code(self,info):
        self.send(self.CR.submit_code(int(info[0]),int(info[1]),int(info[2]),info[3],info[4]))

    def IC_view_problem(self,info):
        self.send(self.CR.view_problem(int(info[0]),int(info[1])))
    
    def IC_view_rank(self,info):
        self.send(self.CR.view_rank(int(info[0])))

    def IC_view_contest(self,info):
        self.send(self.CR.view_contest(int(info[0])))
    
    def IC_view_status(self,info):
        self.send(self.CR.view_status(int(info[0])))

    def get_info(self,table_name):
        self.cursor.execute("select * from "+table_name+";")
        rs = self.cursor.fetchall()
        self.conn.commit()
        # print(rs)
        msg = ""
        for r in rs:
            for i in r:
                msg += str(i)+":::"
            msg = msg[:-3]+"&&&"
        self.send(msg[:-3])
    
    def send(self,msg):
        if(msg == "" or msg == None):
            msg = "None"
        self.ss.send(msg.encode())

s = socket.socket()         # 创建 socket 对象
host = socket.gethostname() # 获取本地主机名
port = 12345                # 设置端口
s.bind((host, port))        # 绑定端口
s.listen(100)
t_num = 0
t_list = []
CR = ContestRunner(pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8'))
CR.start()

while(True):
    try:
        try:
            ss,addr = s.accept()
            print("client connected from: ",addr)
            t_list.append(OjServer(t_num,"socket-"+str(t_num),ss,CR,pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8'),addr))
            t_list[t_num].start()
            t_num += 1
        except:
            ss.close()
            s.close()
    except:
        s.close()

