#ifndef _USER_H
#define _USER_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;
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
int Mark_user(int user_id,int dest_id);         // 关注用户
int Apply_group(int user_id,int group_id);      // 申请加入用户组
void user_show_info(int user_id);               // 查看个人信息
void Show_users();                              // 查看所有用户



// User篇
int  Sign_out(){cout<<"待开发……"<<endl;}
int  Change_info(int user_id){cout<<"待开发……"<<endl;}                   // 修改个人信息
int  Mark_user(int user_id,int dest_id){cout<<"待开发……"<<endl;}         // 关注用户
int  Apply_group(int user_id,int group_id){cout<<"待开发……"<<endl;}      // 申请加入用户组
void Show_users(){cout<<"待开发……"<<endl;}                              // 查看所有用户
void View_user(int uid,int user_id);                                    // 查看某个用户信息
void Find_user(int user_id);                                            // 查找用户

void user_show_info(int user_id)
{
    while(true){
        cout<<"你是最棒的coder，加油"<<endl;
        cout<<"1.修改信息   2.退出"<<endl;
        string opt;
        cin>>opt;
        if(opt == "1") Change_info(user_id);
        if(opt == "2") return;

    }
}

void View_user(int uid,int user_id)
{
    cout<<"待开发..."<<endl;
}

void Find_user(int user_id)
{
    cout<<"待开发...."<<endl;
}

int Sign_up()
{
    string username,nickname,word;
    cout<<"请输入用户名：";
    cin>>username;
    cout<<"请输入昵称：";
    cin>>nickname;
    cout<<"请输入密码(不可含有:&字符）：";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    recv_data(str);
    cout<<"注册成功！"<<endl;
    cout<<"按任意键返回"<<endl;
    getchar();
    getchar();
    return 1;
}


int Sign_in()
{
    string nickname,word,str;
    cout<<"请输入昵称：";
    cin>>nickname;
    cout<<"请输入密码：";
    cin>>word;
    str=recv_data("get_user");
    vector<string> users = split(str,"&&&");
    for(int i = 0 ; i < users.size() ; i ++)
    {
        vector<string> user = split(users[i],":::");
        if(user[1] == nickname)
        {
            if(user[2] == word)
                return stoi(user[0]);
            else
                return -1;
        }
    }
    return -1;
}
#endif            // magic code don't touch  !!!
