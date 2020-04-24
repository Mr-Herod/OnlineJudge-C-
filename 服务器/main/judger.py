import pymysql,time,random

class Judger(object):
    @classmethod
    def judge(self,pro_id,code):
        return random.choice(['AC','TLE','RE','PE'])
        
