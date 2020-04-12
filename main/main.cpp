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
        if(opt == "3")  {cout<<"See you next time."<<endl;return;}
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
        if(opt == "2")  Show_problems();
        if(opt == "3")  Show_contests();
        if(opt == "4")  Show_users();
        if(opt == "5")  Show_groups();
        if(opt == "6")  return;
    }
}




// Main flow
void Probelm_page(int user_id){cout<<"待开发……"<<endl;}
void Contest_page(int user_id){cout<<"待开发……"<<endl;}
void User_page(int user_id){cout<<"待开发……"<<endl;}
void Gruop_page(int user_id){cout<<"待开发……"<<endl;}
