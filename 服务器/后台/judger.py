import pymysql,time,random

class Judger(object):
    @classmethod
    def judge(self,pro_id,code):
        return random.choice(['AC','TLE','AC','RE','AC','PE','WA','WA','MLE','WA','AC'])
        
