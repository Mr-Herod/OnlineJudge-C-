#include <bits/stdc++.h>
//#include "user.h"
#include "group.h"
#include "contest.h"
#include "problem.h"
using namespace std;

// 用户类
struct User{
    int    user_id;                 // 用户ID
    string user_name;               // 用户名
    string user_password;           // 用户密码
    string user_nickname;           // 用户昵称
    vector<int> solved_problem;     // 解决的题目
    vector<int> attemped_problem;   // 尝试但未解决的题目
    vector<int> favorite_problem;   // 收藏的题目
    vector<int> owned_group;        // 创建的用户组
    vector<int> entered_group;      // 加入的用户组
    vector<int> owned_contest;      // 创建的比赛
    vector<int> entered_contest;    // 参加的比赛（有提交记录就算参加）
    vector<int> favorite_user;      // 关注的用户
};


// User篇
int Sign_up();                                  // 用户注册
int Sign_in();                                  // 用户登录
int Sign_out();                                 // 用户退出
int Change_info(int user_id);                   // 修改个人信息
int Submit_pro(int pro_id,int user_id);         // 提交代码
int Mark_user(int user_id,int dest_id);         // 关注用户
int Create_group(int user_id);                  // 创建用户组
int Apply_group(int user_id,int group_id);      // 申请加入用户组
int Create_contest();                           // 创建比赛
/** deleted **/
//int View_user_rank();                         // 查看所有用户排名
/** new  **/
void user_show_info(int user_id);               // 查看个人信息
/** new  **/
void Show_users();                              // 查看所有用户

// User篇
int Sign_out(){cout<<"待开发……"<<endl;}
int Change_info(int user_id){cout<<"待开发……"<<endl;}                   // 修改个人信息
int Submit_pro(int pro_id,int user_id){cout<<"待开发……"<<endl;}         // 提交代码
int Mark_user(int user_id,int dest_id){cout<<"待开发……"<<endl;}         // 关注用户
int Create_group(int user_id){cout<<"待开发……"<<endl;}                  // 创建用户组
int Apply_group(int user_id,int group_id){cout<<"待开发……"<<endl;}      // 申请加入用户组
int Create_contest(){cout<<"待开发……"<<endl;}                           // 创建比赛
void Show_users(){cout<<"待开发……"<<endl;}                              // 查看所有用户

void user_show_info(int user_id)
{
    cout<<"你是最棒的coder，加油"<<endl;
    cout<<"1.修改信息   2.退出"<<endl;
}


int Sign_up()
{
    cout<<"注册成功！"<<endl;
    return 1;
}

int Sign_in()
{
    if(true)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

