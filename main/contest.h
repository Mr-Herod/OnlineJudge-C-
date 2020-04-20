#include <bits/stdc++.h>
using namespace std;


// 赛时用户类（ICU）
struct InContestUser{
    int ICU_id;                     // ICU ID
    int score;                      // 得分（过题数）
    int penalty;                    // 罚时（错误次数*20分 + 过题时间）
    map<int,int> solved;            // 通过的题目以及对应的提交次数
    map<int,int> attemped;          // 提交但未通过的题目以及对应的提交次数
    friend bool operator < (const InContestUser& user1,const InContestUser& user2)
    {
        if(user1.score == user2.score)
            return user1.penalty < user2.penalty;
        return user1.score < user2.score;
    }
};

// 赛时题目类（ICP）
struct InContestProblem{
    int ICP_id;                     // ICP ID
    int pro_id;                     // 题目ID
    int submit;                     // 提交数
    int solved;                     // 通过数
    string pro_nickname;           // 新题目名称
};

// 赛时评测类（ICS）
struct InContestStatus{
    int ICS_id;                     // ICS ID
    int ICP_id;                     // ICP ID
    int ICU_id;                     // ICU ID
    int time;                       // 提交时间
    string result;                  // 判题结果
    string lang;                    // 代码语言
};

// 比赛类
struct Contest{
    int contest_id;                 // 比赛ID
    int contest_owner;              // 比赛创建者
    int contest_group;              // 比赛创建用户组（可以没有）
    int contest_start_time;         // 比赛开始时间
    int contest_length;             // 比赛持续时长
    string contest_title;           // 比赛标题
    string contest_type;            // 比赛类型（公开，用户组私有）
    string contest_status;          // 比赛状态（scheduled，running，ended）
    vector<InContestUser>    participent;       // 参赛用户
    vector<InContestProblem> problem;           // 比赛选题
    vector<InContestStatus>  judge;            // 比赛评测记录
    priority_queue<InContestUser> contest_rank; // 比赛排名
};



// Contest篇
int Find_contest(int user_id);                              // 查找比赛
int View_contest(int contest_id,int user_id);               // 查看比赛
int Run_contest(int contest_id);                            // 运行比赛（重中之重，比较难实现）
/** new **/
void Show_contests(string type,int user_id);
void Show_rank(int contest_id);
// Contest篇
int Find_contest(int user_id){cout<<"待开发……"<<endl;}                              // 查找比赛

int View_contest(int contest_id,int user_id)                                        // 查看比赛
{
    string opt;
    while(true)
    {
        cout<<"xxx 第一次测试赛"<<endl;
        cout<<"Begin time: 00:00 End time: 1:00"<<endl;
        if(1)
            cout<<"Pending!"<<endl;
        else if('a' == 'b')
            cout<<"Running"<<endl;
        else
            cout<<"Ended!"<<endl;
        for(int i = 0 ; i < 3 ; i ++)
        {
            cout<<"(status)1/2  (pro_id)1    (title)A+B problem"<<endl;
        }
        cout<<"1.查看题目   2.查看排名  3.返回"<<endl;
        cin>>opt;
        if(opt == "1")
        {

        }
        if(opt == "2")
            Show_rank(contest_id);
    }
}

int Run_contest(int contest_id){cout<<"待开发……"<<endl;}                            // 运行比赛（重中之重，比较难实现）
/** new **/
void Show_contests(string type,int user_id)                                         // 查看比赛
{
    if(type == "all" || type == "own")
        cout<<"";
}

void Show_rank(int contest_id)
{
    cout<<"Rank\tName\tScore\tPenalty"<<endl;
    for(int i = 0 ; i < 3 ; i ++)
    {
        cout<<i<<"\t(name)herod\t(score)3\t(oenalty)100"<<endl;
    }
}
