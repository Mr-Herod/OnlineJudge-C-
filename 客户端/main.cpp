#include <bits/stdc++.h>
#include <conio.h>
#include "user.h"                   // 用户模块
#include "group.h"                  // 用户组模块
#include "contest.h"                // 比赛模块
#include "problem.h"                // 题目模块
#include "datatrans.h"              // 数据传输模块
#include "dataconv.h"               // 数据处理模块

using namespace std;

// Main flow
void Index_page();                  // 引导页面
void Home_page(int user_id);        // 用户主页
void Probelm_page(int user_id);     // 问题页面
void Contest_page(int user_id);     // 比赛页面
void User_page(int user_id);        // 用户页面
void Gruop_page(int user_id);       // 用户组页面


int main()
{
    system("color 2F");
    Index_page();
    return 0;

}


void Index_page()
{
    system("color 2F");
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 "<<endl;
        cout<<"1.注册    2.登录    3.退出"<<endl;
        opt = getch();
        if(opt == "1")  Sign_up();
        if(opt == "2")
        {
            int user_id = Sign_in();
            if(user_id != -1)
            {
                cout<<"登录成功!!!!"<<endl;
                cout<<"按任意键继续..."<<endl;
                getch();
                Home_page(user_id);
            }
            else if(user_id == -1) {
                cout<<"密码输入有误请重试"<<endl;
                cout<<"按任意键继续..."<<endl;
                getch();
            }
            else {
                cout<<"账户输入有误请重试"<<endl;
                cout<<"按任意键继续..."<<endl;
                getch();
            }
        }
        if(opt == "3")  {cout<<"按任意键退出系统..."<<endl;getch();return;}
    }

}

void Home_page(int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 (个人信息页) "<<endl;
        cout<<"1.查看个人信息    2.题目页    3.比赛页    4.用户页    5.用户组页    6.退出"<<endl;
        opt = getch();
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
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 (比赛页) "<<endl;
        cout<<"1.我的比赛    2.进入比赛    3.搜索比赛    4.创建比赛    5.返回"<<endl<<endl;
        Show_contests("all",user_id);
        opt = getch();
        if(opt == "1") My_contests(user_id);
        if(opt == "2")
        {
            int contest_id;
            cout<<"请输入比赛ID:";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
        if(opt == "3") Find_contest(user_id);
        if(opt == "4") Create_contest(user_id);
        if(opt == "5") return;
    }
}

void Probelm_page(int user_id)
{

    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 (题目页) "<<endl;
        cout<<"1.通过的题目    2.尝试的题目    3.查看题目    4.搜索题目    5.返回"<<endl;
        Show_problems("all",user_id);
        opt = getch();
        if(opt == "1") Solved_problem(user_id);
        if(opt == "2") Attempted_problem(user_id);
        if(opt == "3")
        {
            int pro_id;
            cout<<"请输入题目ID：";
            cin>>pro_id;
            View_pro(pro_id,user_id);
        }
        if(opt == "4") Find_pro(user_id);
        if(opt == "5") return;
    }
}

void User_page(int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 (用户页) "<<endl;
        cout<<"1.查看用户    2.搜索用户    3.返回"<<endl<<endl;
        Show_users();
        opt = getch();
        if(opt == "1")
        {
            int uid;
            cout<<"请输入用户ID:";
            cin>>uid;
            View_user(uid,user_id);
        }
        if(opt == "2") {
            string nickname;
            cout<<"请输入用户昵称:";
            cin>>nickname;
            Find_user(nickname,user_id);
        }
        if(opt == "3") {
            return;
        }
    }
}

void Gruop_page(int user_id)
{

    string opt;
    while(true)
    {
        system("CLS");
        cout<<"自制在线代码评测系统 ver-1.0 (用户组页) "<<endl;
        cout<<"1.查看自己用户组    2.查看所有用户组    3.查找用户组    4.创建用户组    5.返回"<<endl<<endl;
        Show_groups("all",user_id);
        opt = getch();
        if(opt == "1")
        {
            system("CLS");
            cout<<"自制在线代码评测系统 ver-1.0 (用户组页) "<<endl;
            cout<<"1.查看自己用户组    2.查看所有用户组    3.查找用户组    4.创建用户组    5.返回"<<endl<<endl;
            Show_groups("own",user_id);
            cout<<"按任意键继续..."<<endl;
            getch();
        }
        if(opt == "2")
        {
            system("CLS");
            cout<<"自制在线代码评测系统 ver-1.0 (用户组页) "<<endl;
            cout<<"1.查看自己用户组    2.查看所有用户组    3.查找用户组    4.创建用户组    5.返回"<<endl<<endl;
            Show_groups("all",user_id);
            cout<<"按任意键继续..."<<endl;
            getch();
        }
        if(opt == "3") {
                string name;
                cout<<"请输入要查找的用户组的名称:";
                cin>>name;
                system("CLS");
                cout<<"自制在线代码评测系统 ver-1.0 (用户组页) "<<endl;
                cout<<"1.查看自己用户组    2.查看所有用户组    3.查找用户组    4.创建用户组    5.返回"<<endl<<endl;
                Find_group(name);
                cout<<"按任意键继续..."<<endl;
                getch();
        }
        if(opt == "4") Create_group(user_id);
        if(opt == "5") return;
    }
}
