import socket,threading,time,pymysql

class myThread(threading.Thread):
    def __init__(self,threadID,name,ss,cursor,conn):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.ss = ss
        self.cursor = cursor
        self.conn = conn

    def run(self):
        msg = bytes.decode(self.ss.recv(10024))
        print(msg)
        info = msg.split(':::')
        if(info[0] == "create_user"):
            self.create_user(info[1:])
        elif(info[0] == "create_group"):
            self.create_group(info[1:])
        elif(info[0] == "create_contest"):
            self.create_contest(info[1:])
        elif(info[0] == "get_user"):
            self.send_info("User")
        elif(info[0] == "get_group"):
            self.send_info("groups")
        elif(info[0] == "get_contest"):
            self.send_info("contest")
        elif(info[0] == "get_problem"):
            self.send_info("problem")
        elif(info[0] == "get_running_contest"):
            self.send_running_contest()

    
    def create_user(self,info):
        self.cursor.execute("insert into User values(0,'"+info[0]+"','"+info[1]+"','"+info[2]+"',' ',' ',' ',' ',' ',' ',' ',' ');")
    
    def create_group(self,info):
        self.cursor.execute("insert into groups values(0,"+info[0]+",'"+info[1]+"',' ',' ');")
    
    def create_contest(self,info):
        self.cursor.execute("insert into contest values(0,"+info[0]+","+info[1]+","+info[2]+","+info[3]+",'"+info[4]+"','"+info[5]+"','pending',' ','"+info[6]+"',' ');")
        
    def group_add_user(self,sta):
        pass
    
    def group_add_contest(self,sta):
        pass
    
    def submit_code(self,sta):
        pass
    
    def submit_code_from_contest(self,sta):
        pass
    
    def send_info(self,table_name):
        self.cursor.execute("select * from "+table_name+";")
        rs = self.cursor.fetchall()
        if(rs == ()):
            self.ss.send(b' ')
            return

        msg = ""
        print(rs)
        for r in rs:
            for i in r:
                msg += str(i)+":::"
            msg = msg[:-3]+"&&&"
        msg = msg[:-3]
        self.ss.send(msg.encode())

    def send_running_contest(self):
        pass

# 连接数据库
conn = pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8')

s = socket.socket()         # 创建 socket 对象
host = socket.gethostname() # 获取本地主机名
port = 12345                # 设置端口
s.bind((host, port))        # 绑定端口
s.listen(100)
t_num = 0
t_list = []


while(True):
    try:
        try:
            ss,addr = s.accept()
            print("client connected from: ",addr)
            t_list.append(myThread(t_num,"socket-"+str(t_num),ss,conn.cursor(),conn))
            t_list[t_num].start()
            t_num += 1
        except:
            ss.close()
            s.close()
            conn.close()
    except:
        raise


