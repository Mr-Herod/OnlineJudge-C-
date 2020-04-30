import sys
sys.path.append("/root/Onlinejudge-c/")
import pymysql,time
from judger import *

class Problem(object):
    @classmethod
    def submit_code(self,pro_id,user_id,code):
        conn = pymysql.connect(host='localhost', port=3306, user='root', passwd='2015hero', db='onlinejudge', charset='utf8') 
        cursor = conn.cursor()
        cursor.execute("select solved_problem,attempted_problem from User where user_id = "+str(user_id)+";")
        user_info = cursor.fetchone()
        conn.commit()
        solved = user_info[0].split("::")
        attempted = user_info[1].split("::")
        result = Judger.judge(pro_id,code)
        if(result == "AC"):
            if(str(pro_id) in attempted):
                attempted.remove(str(pro_id))
            if(str(pro_id) not in solved):
                solved.append(str(pro_id))
        elif(str(pro_id) not in solved and str(pro_id) not in attempted):
            attempted.append(str(pro_id))
        cursor.execute("update User set solved_problem = '" +"::".join(solved)+ "', attempted_problem = ' " +"::".join(attempted)+"' where user_id = "+str(user_id)+";")
        conn.commit()
        cursor.close()
        conn.close()
        return result
