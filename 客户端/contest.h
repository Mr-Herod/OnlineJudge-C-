#ifndef _CONTEST_H
#define _CONTEST_H
#include <bits/stdc++.h>
#include <conio.h>
#include "datatrans.h"
#include "dataconv.h"
using namespace std;

/**
介绍：该文件主要是比赛部分的功能实现。
功能：创建比赛，查找比赛，查看比赛，参加比赛，查看题目、排名、评测情况。
作者：Herod
时间：2020-05-10
**/

void Show_contest(string type,int user_id);                     // 列出所有比赛
int  Create_contest(int user_id);                               // 创建比赛
int  Find_contest(int user_id);                                 // 查找比赛
int  IC_view_contest(int contest_id,int user_id);               // 进入比赛
void IC_view_rank(int contest_id);                              // 查看排名
void IC_view_problem(int contest_id,int pro_id,int user_id);    // 查看题目
void IC_submit_code(int contest_id,int pro_id,int user_id);     // 提交代码
void IC_view_status(int contest_id);                            // 查看实时测评
time_t convert_str_to_tm(char * str_time);                      // 时间转化


void Show_contests(string type,int user_id)                     // 查看比赛,输出比赛简要信息
{
    /*
    数据接收格式：
    id:::title:::start_time:::length:::status:::owner:::group&&&
    */
    cout<<endl<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"start_time"<<setw(20)<<"length"<<setw(20)<<"status"<<endl<<endl;
    vector<string> msgs = split(recv_data("view_contests"),"&&&");
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        vector<string> msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}        // 信息为空输出None
        if(type == "own" && msg[5] != itos(user_id)) continue;  // 筛选自己创建的比赛
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<endl;
    }
    cout<<endl;
}

int Create_contest(int user_id)                                 // 创建比赛
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (创建比赛)"<<endl<<endl;
    string contest_title;                                       // 比赛名称
    string contest_start_time;                                  // 开始时间
    int contest_length;                                         // 比赛时长
    string contest_type;                                        // 比赛类型
    string problems;                                            // 比赛题目
    cout<<"请输入比赛标题：";cin>>contest_title;
    cout<<"请输入比赛开始时间(年/月/日/时/分):";cin>>contest_start_time;
    cout<<"请输入比赛时长(以分钟为单位)：";cin>>contest_length;
    cout<<"请输入比赛类型(pulic/private/password)：";cin>>contest_type;
    cout<<"请输入比赛题目(用/隔开)：";cin>>problems;
    vector<string > tmp = split(contest_start_time,"/");
    // 把字符串表示的时间转化成秒数
    int seconds = convert_str_to_tm((char *)((tmp[0]+"-"+tmp[1]+"-"+tmp[2]+" "+tmp[3]+":"+tmp[4]+":00").data()));
    problems = zip(split(problems,"/"),"::");
    // 默认用户组为1
    string contest_group = "1";
    /*
    数据发送格式：
    create_contest:::user_id:::group_id:::start_time:::length:::title:::type:::problem
    */
    string msg = "create_contest:::"+itos(user_id)+":::"+contest_group+":::"+itos(seconds)+":::"+itos(contest_length*60)+":::"+contest_title+":::"+contest_type+":::"+problems;
    recv_data(msg);
    cout<<"比赛创建成功！按任意键返回..."<<endl;
    getch();
}

int Find_contest(int user_id)                                   // 查找比赛,使用kmp算法进行字符串匹配
{
    string name;
    cout<<"请输入比赛名称:";
    cin>>name;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (比赛页) "<<endl;
        cout<<"1.进入比赛    2.返回"<<endl<<endl;
        /*
        数据接收格式：
        id:::title:::start_time:::length:::status:::owner:::group&&&
        */
        vector<string> msgs = split(recv_data("view_contests"),"&&&");
        cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"start_time"<<setw(20)<<"length"<<endl<<endl;
        for(int i = 0 ; i < msgs.size() ; i ++)
        {
            vector<string> msg = split(msgs[i],":::");
            if(msg[0] == "None") {cout<<"None"<<endl;break;}
            if(!match(msg[1],name)) continue;
            cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<endl;
        }
        cout<<endl;
        string opt;
        opt = getch();
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

void My_contests(int user_id)                                   // 查看自己创建的比赛
{
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (我的比赛) "<<endl;
        cout<<"1.进入比赛    2.返回"<<endl<<endl;
        Show_contests("own",user_id);
        string opt;
        opt = getch();
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

int IC_view_contest(int contest_id,int user_id)                 // 进入比赛，查看详情
{
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (比赛页) "<<endl;
        cout<<"1.查看题目    2.查看排名    3.查看实时测评    4.返回"<<endl<<endl;
        vector<string> msgs = split(recv_data("IC_view_contest:::"+itos(contest_id)),"&&&");
        vector<string> msg  = split(msgs[0],":::");;
        cout<<msg[0]<<"    started at: "<<msg[1]<<"    status: "<<msg[3]<<"    length: "<<msg[2]<<endl<<endl;
        cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"submit"<<setw(20)<<"solved"<<endl<<endl;
        for(int i = 2 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            if(msg[0] == "None") {cout<<"None"<<endl;break;}
            cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<endl;
        }
        cout<<endl;
        string opt;
        opt = getch();
        if(opt == "1")
        {
            int ICP_id;
            cout<<"请输入题号：";
            cin>>ICP_id;
            IC_view_problem(contest_id,ICP_id,user_id);
        }
        if(opt == "2")  IC_view_rank(contest_id);
        if(opt == "3")  IC_view_status(contest_id);
        if(opt == "4")  break;
    }
}

void IC_view_problem(int contest_id,int ICP_id,int user_id)     // 查看题目
{
    while(true)
    {
        system("CLS");
        string opt;
        cout<<"牛人自制在线评测系统 ver-1.0 (题目页) "<<endl;
        vector<string> msgs = split(recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id)),"&&&");
        // 比赛开始前不可以查看题目和提交代码
        if(msgs[0] == "This contest is not running.")
        {
            cout<<endl<<"This contest is not running."<<endl<<endl;
            cout<<"按任意键返回..."<<endl;
            getch();
            break;
        }
        cout<<"1.提交代码    2.返回"<<endl<<endl;
        // 输出题目详情
        for(int i = 1 ; i < msgs.size() ; i  ++)
        {
            vector<string> msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
                cout<<msg[j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        opt = getch();
        if(opt == "2")
            break;
        else
            IC_submit_code(contest_id,ICP_id,user_id);
    }
}

void IC_view_rank(int contest_id)                               // 查看排名
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (排名页) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_rank:::"+itos(contest_id)),"&&&");
    cout<<endl<<setw(6)<<"rank"<<setw(15)<<"user"<<setw(15)<<"score"<<setw(15)<<"penalty"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i ++)
    {
        vector<string> msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}
        cout<<setw(6)<<msg[0]<<setw(15)<<msg[1]<<setw(15)<<msg[2]<<setw(15)<<msg[3]<<endl;
    }
    cout<<endl;
    cout<<"按任意键返回..."<<endl;
    getch();
}

void IC_view_status(int contest_id)                             // 查看实时测评
{
    system("CLS");
    cout<<"牛人自制在线评测系统 ver-1.0 (实时评测页) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_status:::"+itos(contest_id)),"&&&");
    cout<<endl<<setw(5)<<"No."<<setw(20)<<"problem"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        vector<string> msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<setw(20)<<msg[5]<<endl;
    }
    cout<<endl<<"按任意键返回..."<<endl;
    getch();
}

void IC_submit_code(int contest_id,int ICP_id,int user_id)      // 提交代码
{
    string code;
    cout<<"请输入代码："<<endl;
    cin>>code;
    cout<<"请选择语言:"<<endl<<"1. C    2. C++    3. Python2    4. Python3    5. Java"<<endl;
    string lang;
    lang = getch();
    map<string,string> mp;
    mp["1"] = "C";mp["2"] = "C++";mp["3"] = "Python2";mp["4"] = "Python3";mp["5"] = "Java";
    // 默认语言为C语言
    if(mp[lang] == "")  lang = "1";
    system("CLS");
    string msgg = recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+mp[lang]);
    vector<string> msgs = split(msgg,"&&&");
    vector<string> msg;
    // 如果比赛已经结束则不能提交代码
    if(msgg == "This contest is not running.")
    {
        cout<<endl<<"This contest is not running."<<endl;
        cout<<endl<<"按任意键返回..."<<endl;
        getch();
    }
    cout<<"牛人自制在线评测系统 ver-1.0 (评测结果) "<<endl<<endl;
    cout<<setw(5)<<"No."<<setw(20)<<"problem"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<setw(20)<<msg[5]<<endl;
    }
    cout<<endl<<"按任意键返回..."<<endl;
    getch();
}

time_t convert_str_to_tm(char * str_time)                       // 把字符串表示的时间转化成一个整数
{
    struct tm tt;
    memset(&tt,0,sizeof(tt));
    tt.tm_year=atoi(str_time)-1900;
    tt.tm_mon=atoi(str_time+5)-1;
    tt.tm_mday=atoi(str_time+8);
    tt.tm_hour=atoi(str_time+11);
    tt.tm_min=atoi(str_time+14);
    tt.tm_sec=atoi(str_time+17);
    return mktime(&tt);
}

#endif            // magic code don't touch  !!!
