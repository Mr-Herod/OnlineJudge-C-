#ifndef _CONTEST_H
#define _CONTEST_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// Contest篇
void Show_contest(string type,int user_id);                     // 列出所有比赛
int  Create_contest(int user_id);                               // 创建比赛
int  Find_contest(int user_id);                                 // 查找比赛
int  IC_view_contest(int contest_id,int user_id);               // 进入比赛
void IC_view_rank(int contest_id);                              // 查看排名
void IC_view_problem(int contest_id,int pro_id,int user_id);    // 查看题目
void IC_submit_code(int contest_id,int pro_id,int user_id);     // 提交代码
void IC_view_status(int contest_id);                            // 查看评测状态

// Contest篇
int Find_contest(int user_id)               // 查找比赛
{
    vector<string> msgs = split(recv_data("view_contests"),"&&&");
    vector<string> msg;
    string name;
    cout<<"请输入比赛名称:";
    cin>>name;
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (比赛页) "<<endl;
        cout<<"1.进入比赛  2.返回"<<endl<<endl;
        for(int i = 0 ; i < msgs.size() ; i ++)
        {
            msg = split(msgs[i],":::");
            if(i != 0 && !match(msg[1],name)) continue;
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                if(msg.size() == 6 && j == 4) break;
                int wid = 0;
                if(j == 0) wid = 5;
                else       wid = 20;
                cout<<setw(wid)<<msg[j];
            }
            cout<<endl;
        }
        cin>>opt;
        if(opt == "2") return 0;
        if(opt == "1")
        {
            int contest_id;
            cout<<"请输入比赛ID：";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
    }
}

void Show_contests(string type,int user_id)                                         // 查看比赛
{
    vector<string> msgs = split(recv_data("view_contests"),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        if(type == "own" && msg.size() == 6 &&  i != 0 && msg[4] != itos(user_id)) continue;
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            if(msg.size() == 6 && j == 4) break;
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
}

void My_contests(int user_id)                                         // 查看比赛
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (我的比赛) "<<endl;
        cout<<"1.进入比赛   2.返回"<<endl<<endl;
        Show_contests("own",user_id);
        cin>>opt;
        if(opt == "1")
        {
            int contest_id;
            cout<<"请输入比赛ID：";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
        if(opt == "2") return ;
    }
}

int IC_view_contest(int contest_id,int user_id)                                        // 查看比赛
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (比赛页) "<<endl;
        vector<string> msgs = split(recv_data("IC_view_contest:::"+itos(contest_id)),"&&&");
        if(msgs[0] == "None")
        {
            cout<<"This contest is not running."<<endl;
            cout<<"按任意键返回..."<<endl;
            getchar();getchar();
            return 1;
        }
        cout<<"1.查看题目   2.查看排名  3.查看实时测评    4.返回"<<endl;
        vector<string> msg;
        cout<<endl;
        for(int i = 0 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                int wid = 0;
                if(j == 0) wid = 6;
                else       wid = 20;
                cout<<setw(wid)<<msg[j];
            }
            cout<<endl;
        }
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
        cout<<"1.提交代码   2.返回"<<endl<<endl;
        vector<string> msgs = split(recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id)),"&&&");
        vector<string> msg;
        for(int i = 1 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                int wid = 20;
                if(j != 0)
                    cout<<setw(wid)<<msg[j];
                else
                    cout<<msg[j];
            }
            cout<<endl;
        }
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
    system("CLS");
    vector<string> msgs = split(recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+"python"),"&&&");
    vector<string> msg;
    cout<<"牛人自制在线评测系统 ver-1.0 (评测结果) "<<endl<<endl;
    cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}

void IC_view_rank(int contest_id)
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (排名页) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_rank:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}


void IC_view_status(int contest_id)
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (实时评测页) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_status:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}

time_t convert_str_to_tm(char * str_time)
{
    struct tm tt;
    memset(&tt,0,sizeof(tt));
    tt.tm_year=atoi(str_time)-1900;
    tt.tm_mon=atoi(str_time+5)-1;
    tt.tm_mday=atoi(str_time+8);
    tt.tm_hour=atoi(str_time+11);
    tt.tm_min=atoi(str_time+14);
    tt.tm_sec=atoi(str_time+17);
    return mktime(&tt);// + 28800;//28800是一个偏差。。加上这个
}

int Create_contest(int user_id)
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (创建比赛)"<<endl;
    string contest_title;
    string contest_start_time;
    int contest_length;
    string contest_type;
    string problems;
    cout<<"请输入比赛标题：";cin>>contest_title;
    cout<<"请输入比赛开始时间(年/月/日/时/分):";cin>>contest_start_time;
    cout<<"请输入比赛时长(以分钟为单位)：";cin>>contest_length;
    cout<<"请输入比赛类型(pulic/private/password)：";cin>>contest_type;
    cout<<"请输入比赛题目(用/隔开)：";cin>>problems;
    vector<string > tmp = split(contest_start_time,"/");
    int seconds = convert_str_to_tm((char *)((tmp[0]+"-"+tmp[1]+"-"+tmp[2]+" "+tmp[3]+":"+tmp[4]+":00").data()));
    problems = zip(split(problems,"/"),"::");
    string contest_group = "1";
    string msg = "create_contest:::"+itos(user_id)+":::"+contest_group+":::"+itos(seconds)+":::"+itos(contest_length*60)+":::"+contest_title+":::"+contest_type+":::"+problems;
    //cout<<msg<<endl;
    recv_data(msg);
    cout<<"比赛创建成功！按任意键返回..."<<endl;
    getchar();getchar();
}              // 创建比赛


#endif            // magic code don't touch  !!!
