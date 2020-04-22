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
        self.cursor.execute("insert into User values(0,'"+info[1]+"','"+info[2]+"','"+info[3]+"',' ',' ',' ',' ',' ',' ',' ',' ');")
        self.conn.commit()
        self.ss.send(b"\nsign up succeeded!")
        self.ss.close()
    
    def create_user(self,sta,cursor):
        pass
    
    def create_group(self,sta,cursor):
        pass
    
    def create_contest(self,sta,cursor):
        pass
    
    def group_add_user(self,sta,cursor):
        pass
    
    def group_add_contest(self,sta,cursor):
        pass
    
    def submit_code(self,sta,cursor):
        pass
    
    def submit_code_from_contest(self,sta,cursor):
        pass
    
    def send_user_info(self,cursor):
        pass
    
    def send_group_info(self,cursor):
        pass
        
    def send_problem_info(self,cursor):
        pass
        
    def send_contest_info(self,cursor):
        pass
    
    def send_running_contest(self,cursor):
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


