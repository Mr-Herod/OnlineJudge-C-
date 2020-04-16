#include <bits/stdc++.h>
#include "user.h"
#include "group.h"
#include "contest.h"
#include "problem.h"

using namespace std;

// Main flow
void Index_page();
void Home_page(int user_id);
void Probelm_page(int user_id);
void Contest_page(int user_id);
void User_page(int user_id);
void Gruop_page(int user_id);

int main()
{
    Index_page();
    return 0;
}

// Main flow
void Index_page()
{
    string opt;
    while(true)
    {
        cout<<"牛人自制在线评测系统 ver-1.0 "<<endl;
        cout<<"1.注册    2.登录   3.退出"<<endl;
        cin>>opt;
        if(opt == "1")  Sign_up();
        if(opt == "2")
        {
            int user_id = Sign_in();
            if(user_id != -1)
                Home_page(user_id);
        }
        if(opt == "3")  {cout<<"See you next time."<<endl;getchar();getchar();return;}
    }

}

void Home_page(int user_id)
{
    string opt;
    while(true)
    {
        cout<<"1.查看个人信息   2.查看题目  3.查看比赛  4.查看用户  5.查看组   6.退出"<<endl;
        cin>>opt;
        if(opt == "1")  user_show_info(user_id);
        if(opt == "2")  Probelm_page(user_id);
        if(opt == "3")  Contest_page(user_id);
        if(opt == "4")  User_page(user_id);
        if(opt == "5")  Gruop_page(user_id);
        if(opt == "6")  return;
    }
}


void Contest_page(int user_id)
{
    Show_contests("all");
    string opt;
    while(true)
    {
        cout<<"1.全部比赛   2.我的比赛  3.查看比赛  4.搜索比赛  5.返回"<<endl;
        cin>>opt;
        if(opt == "1") Show_contests("all");
        if(opt == "2") Show_contests("own");
        if(opt == "3")
        {
            int contest_id;
            cout<<"请输入比赛ID:";
            cin>>contest_id;
            View_contest(contest_id);
        }
        if(opt == "4") Find_contest(user_id);
        if(opt == "5") return;
    }
}

void Probelm_page(int user_id)
{
    Show_problems("all",user_id);
    string opt;
    while(true)
    {
        cout<<"1.通过的题目  2.尝试的题目 3.所有题目  4.查看题目  5.返回"<<endl;
        cin>>opt;
        if(opt == "1") Show_problems("solved",user_id);
        if(opt == "2") Show_problems("attempted",user_id);
        if(opt == "3") Show_problems("all",user_id);
        if(opt == "4") View_pro(1);
        if(opt == "5") return;
    }
}

void User_page(int user_id)
{
    Show_users();
    string opt;
    while(true)
    {
        cout<<"1.查看用户   2.搜索用户   3.返回"<<endl;
        cin>>opt;
        if(opt == "1")
        {
            int uid;
            cout<<"请输入用户ID:";
            cin>>uid;
            View_user(uid,user_id);
        }
        if(opt == "2") Find_user(user_id);
        if(opt == "3") return;
    }
}

void Gruop_page(int user_id)
{
    Show_groups("own",user_id);
    string opt;
    while(true)
    {
        cout<<"1.查看自己用户组    2.查看所有用户组   3.查找用户组     4.返回"<<endl;
        cin>>opt;
        if(opt == "1") Show_groups("own",user_id);
        if(opt == "2") Show_groups("all",user_id);
        if(opt == "3") Find_group(user_id);
        if(opt == "4") return;
    }
}
