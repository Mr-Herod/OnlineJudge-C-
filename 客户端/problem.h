#ifndef _PROBLEM_H
#define _PROBLEM_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// Problem篇
int  Find_pro(int user_id);                                 // 查找题目
int  View_pro(int pro_id,int user_id);                      // 查看题目详情
void Show_problems(string type,int user_id);                // 查看所有题目
void Submit_code(int pro_id,int user_id,string code);        // 提交代码
int  Solved_problem(int user_id);                           // 查看通过的题目
int  Attempted_problem(int user_id);                        // 查看尝试过的题目


void Submit_code(int pro_id,int user_id,string code)
{
    string result = recv_data("submit_code:::"+itos(pro_id)+":::"+itos(user_id)+":::"+code);
    cout<<"代码评测结果："<<result<<endl;
    cout<<"按任意键返回..."<<endl;
    getchar();getchar();
}         // 提交代码

// Problem篇
int Find_pro(int user_id)
{
    cout<<"待开发……"<<endl;
}                                 // 查找题目

int View_pro(int pro_id,int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (题目页) "<<endl;
        cout<<"1.提交代码  2.返回"<<endl<<endl;
        vector<string> problem_info = split(recv_data("get_problem"),"&&&");
        for(int i = 0 ; i < problem_info.size() ; i ++)
            if((split(problem_info[i],":::"))[0] == itos(pro_id))
            {
                problem_info = split(problem_info[i],":::");break;
            }
        cout<<problem_info[3]<<endl<<endl;
        cout<<problem_info[5]<<endl<<endl;
        cin>>opt;
        if(opt == "1")
        {
            string code;
            cout<<"请输入代码："<<endl;
            cin>>code;
            Submit_code(pro_id,user_id,code);
        }
        if(opt == "2")
            return 0;
    }
}                       // 查看题目详情



void Show_problems(string type,int user_id)
{
    vector<string> msgs = split(recv_data("get_problem"),"&&&");
    vector<string> msg;
    vector<string> user_info = split(recv_data("get_user"),"&&&");
    for(int i = 0 ; i < user_info.size() ; i ++)
        if((split(user_info[i],":::"))[0] == itos(user_id))
        {
            user_info = split(user_info[i],":::");break;
        }
    vector<string> solved = split(user_info[4],"::");
    vector<string> attempted = split(user_info[5],"::");

    cout<<endl<<setw(5)<<"id"<<setw(10)<<"oj"<<setw(20)<<"title"<<setw(20)<<"source"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i ++)
    {
        msg = split(msgs[i],":::");
        if(type == "solved" && !match(solved,msg[0])) continue;
        if(type == "attempted" && !match(attempted,msg[0])) continue;
        for(int j = 0 ; j < msg.size()-1 ; j ++)
        {
            int wid = 5;
            if(j == 0) wid = 5;
            else if(j == 1) continue;
            else if(j == 2) wid = 10;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int Solved_problem(int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (题目页) "<<endl;
        cout<<"1.查看题目  2.返回"<<endl;
        Show_problems("solved",user_id);
        cin>>opt;
        if(opt == "1")
        {
            int pro_id;
            cout<<"请输入题目ID：";
            cin>>pro_id;
            View_pro(pro_id,user_id);
        }
        if(opt == "2") return 0;
    }
}

int Attempted_problem(int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (题目页) "<<endl;
        cout<<"1.查看题目  2.返回"<<endl;
        Show_problems("attempted",user_id);
        cin>>opt;
        if(opt == "1")
        {
            int pro_id;
            cout<<"请输入题目ID：";
            cin>>pro_id;
            View_pro(pro_id,user_id);
        }
        if(opt == "2") return 0;
    }
}

#endif            // magic code don't touch  !!!
