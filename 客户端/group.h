#ifndef _GROUP_H
#define _GROUP_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// 用户组类
struct Group{
    int group_id;                   // 用户组ID
    int group_owner;                // 用户组创建者
    string group_name;                 // 用户组名
    vector<int> group_member;       // 用户组成员
    vector<int> group_contest;      // 用户组创建的比赛
};


// Group篇
int View_group_contest(int group_id);                       // 查看用户组的比赛
int Add_member(int user_id,int group_id,int dest_id);       // 添加新成员
int Create_group(int user_id);                              // 创建用户组
void Show_groups(string type,int user_id);                  // 查看所有组
void Find_group(int user_id);                               // 查找用户组



// Group篇
int View_group_contest(int group_id){// 查看用户组的比赛
    string str,name;
    str=recv_data("get_group");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(group_id)) {
            vector<string> res3=split(res2[4],"::");
            for(int j=0;j<res3.size();j++) {
                cout<<res3[i];
                if(j%10==0) {
                    cout<<endl;
                }
            }
        }
    }
    cout<<"按任意键继续..."<<endl;
    getch();
    return 1;
}
int Add_member(int user_id,int group_id,int dest_id){// 添加新成员
    string str,str1;
    str=recv_data("get_group");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[1]==itos(user_id)&&res2[0]==itos(group_id)) {
            res2[3]+="::";
            res2[3]+=itos(dest_id);
            str1="update_group:::group_member:::"+itos(group_id)+":::"+res2[3];
            recv_data(str1);
            return 1;
        }

    }
    cout<<"按任意键继续..."<<endl;
    getch();
}
void Show_groups(string type,int user_id){ // 查看组
    string str;
    str=recv_data("get_group");
    if(type=="own") {
        cout<<setw(10)<<"用户组ID"<<setw(25)<<"用户组创建者ID"<<setw(25)<<"用户组名称"<<setw(25)<<"用户组成员数量"<<setw(25)<<"用户组创建的比赛数量"<<endl<<endl;
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            if(res2[1]==itos(user_id)) {
                cout<<setw(10)<<res2[0];
                cout<<setw(25)<<res2[1];
                cout<<setw(25)<<res2[2];
                vector<string> res3=split(res2[3],"::");
                vector<string> res4=split(res2[4],"::");
                cout<<setw(25)<<res3.size()-1<<setw(25)<<res4.size()-1<<endl;
            }
        }
        cout<<"按任意键继续..."<<endl;
        getch();
    }
    if(type=="all") {
        cout<<setw(10)<<"用户组ID"<<setw(25)<<"用户组创建者ID"<<setw(25)<<"用户组名称"<<setw(25)<<"用户组成员数量"<<setw(25)<<"用户组创建的比赛数量"<<endl<<endl;
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            cout<<setw(10)<<res2[0];
            cout<<setw(25)<<res2[1];
            cout<<setw(25)<<res2[2];
            vector<string> res3=split(res2[3],"::");
            vector<string> res4=split(res2[4],"::");
            cout<<setw(25)<<res3.size()-1<<setw(25)<<res4.size()-1<<endl;
        }
        cout<<"按任意键继续..."<<endl;
        getch();
    }
}
void Find_group(string name){// 查找用户组
    string str;
    str=recv_data("get_group");
    cout<<setw(10)<<"用户组ID"<<setw(25)<<"用户组创建者ID"<<setw(25)<<"用户组名称"<<setw(25)<<"用户组成员数量"<<setw(25)<<"用户组创建的比赛数量"<<endl<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(match(res2[2],name)) {
            cout<<setw(10)<<res2[0];
            cout<<setw(25)<<res2[1];
            cout<<setw(25)<<res2[2];
            vector<string> res3=split(res2[3],"::");
            vector<string> res4=split(res2[4],"::");
            cout<<setw(25)<<res3.size()-1<<setw(25)<<res4.size()-1<<endl;
        }
    }
    cout<<"按任意键继续..."<<endl;
    getchar();
    getch();
}

int Create_group(int user_id){// 创建用户组
    string s,name,str;
    cout<<"请输入新建用户组的名称(不可超过20个字符):";
    cin>>name;
    s="create_group:::"+itos(user_id)+":::"+name;
    recv_data(s);
    //str=recv_data("get_group");
    cout<<str<<endl;
    cout<<"创建成功！"<<endl;
    cout<<"按任意键返回"<<endl;
    getchar();
    getch();
    return 1;
}


#endif            // magic code don't touch  !!!
