#ifndef _CONTEST_H
#define _CONTEST_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// Contest篇
int  Find_contest(int user_id);                              // 查找比赛
int  IC_view_contest(int contest_id,int user_id);               // 查看比赛
void Show_contest(string type,int user_id);
void IC_view_rank(int contest_id);
void IC_view_problem(int contest_id,int pro_id,int user_id);
void IC_submit_code(int contest_id,int pro_id,int user_id);
void IC_view_status(int contest_id);
int Create_contest(int user_id);                // 创建比赛

// Contest篇
int Find_contest(int user_id){cout<<"待开发……"<<endl;}                              // 查找比赛

void Show_contests(string type,int user_id)                                         // 查看比赛
{
    cout<<recv_data("view_contests");
}

int IC_view_contest(int contest_id,int user_id)                                        // 查看比赛
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (比赛页) "<<endl;
        string msg  = recv_data("IC_view_contest:::"+itos(contest_id));
        if(msg == "This contest is not running.")
        {
            cout<<msg<<endl;
            cout<<"按任意键返回..."<<endl;
            getchar();getchar();
            return 1;
        }
        cout<<"1.查看题目   2.查看排名  3.查看实时测评    4.返回"<<endl;
        cout<<msg<<endl<<endl;
        cin>>opt;
        if(opt == "1")
        {
            int ICP_id;
            cout<<"请输入题号：";
            cin>>ICP_id;
            IC_view_problem(contest_id,ICP_id,user_id);
        }
        if(opt == "2")
            IC_view_rank(contest_id);
        if(opt == "3")
            IC_view_status(contest_id);
        if(opt == "4")
            break;
    }
}

void IC_view_problem(int contest_id,int ICP_id,int user_id)
{
    while(true)
    {
        system("CLS");
        string opt;
        cout<<"牛人自制在线评测系统 ver-1.0 (题目页) "<<endl;
        cout<<"1.提交代码   2.返回"<<endl;
        cout<<recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id))<<endl;
        cin>>opt;
        if(opt == "2")
            break;
        else
            IC_submit_code(contest_id,ICP_id,user_id);
    }
}

void IC_submit_code(int contest_id,int ICP_id,int user_id)
{
    string code;
    cout<<"请输入代码："<<endl;
    cin>>code;
    string result = recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+"python");
    cout<<"评测结果："<<endl<<result<<endl;
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();

}

void IC_view_rank(int contest_id)
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (排名页) "<<endl;
    cout<<recv_data("IC_view_rank:::"+itos(contest_id))<<endl;
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}


void IC_view_status(int contest_id)
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (实时评测页) "<<endl;
    cout<<recv_data("IC_view_status:::"+itos(contest_id))<<endl;
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}

int Create_contest(int user_id){cout<<"待开发..."<<endl;}              // 创建比赛
#endif            // magic code don't touch  !!!
