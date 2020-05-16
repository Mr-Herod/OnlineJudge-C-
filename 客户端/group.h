#ifndef _GROUP_H
#define _GROUP_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;
// Group篇
int View_group_contest(int group_id);                       // 查看用户组的比赛
int Create_group(int user_id);                              // 创建用户组
void Show_groups(string type,int user_id);                  // 查看所有组
void Find_group(int user_id);                               // 查找用户组
int Apply_group(int user_id,int group_id);                  // 申请加入用户组
string Get_username(int user_id);                           // 获取用户昵称
string Get_groupname(int group_id);                         // 获取用户组名

// Group篇

int Apply_group(int user_id,int group_id){// 申请加入用户组
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            str1=recv_data("get_group");
            vector<string> res3=split(str1,"&&&");
            for(int j=0;j<res3.size();j++) {
                vector<string> res4=split(res3[j],":::");
                if(res4[0]==itos(group_id)) {
                    vector<string> res5=split(res4[3],"::");
                    for(int k=0;k<res5.size();k++) {
                        if(res5[k]==itos(user_id)) {
                            cout<<"您已在该用户组"<<endl;
                            return 0;
                        }
                    }
                    res2[8]+="::";
                    res2[8]+=itos(group_id);
                    str1="update_user:::entered_group:::"+itos(user_id)+":::"+res2[8];
                    recv_data(str1);
                    res4[3]+="::";
                    res4[3]+=itos(user_id);
                    str1="update_group:::group_member:::"+itos(group_id)+":::"+res4[3];
                    recv_data(str1);
                    return 1;
                }

            }
            cout<<"该用户组不存在"<<endl;
            return 0;
        }
    }
    return 0;
}
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

void Show_groups(string type,int user_id){ // 查看所有用户组或者自己的用户组
    string str;
    str=recv_data("get_group");
    cout<<setw(6)<<"ID"<<setw(15)<<"创建者"<<setw(15)<<"名称"<<setw(15)<<"成员数量"<<setw(15)<<"比赛数量"<<endl<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(type=="own"  && res2[1] != itos(user_id))    continue;
        cout<<setw(6)<<res2[0];
        cout<<setw(15)<<Get_username(Stoi(res2[1]));
        cout<<setw(15)<<res2[2];
        vector<string> res3=split(res2[3],"::");
        vector<string> res4=split(res2[4],"::");
        cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
    }
}
void Find_group(string name){ //用kmp查找所有用户组昵称包含输入昵称的用户组
    str=recv_data("get_group");
    cout<<setw(6)<<"ID"<<setw(15)<<"创建者"<<setw(15)<<"名称"<<setw(15)<<"成员数量"<<setw(15)<<"比赛数量"<<endl<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(match(res2[2],name)) {
            cout<<setw(6)<<res2[0];
            cout<<setw(15)<<Get_username(Stoi(res2[1]));
            cout<<setw(15)<<res2[2];
            vector<string> res3=split(res2[3],"::");
            vector<string> res4=split(res2[4],"::");
            cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
        }
    }
}

int Create_group(int user_id){// 创建用户组
    string s,name;
    cout<<"请输入新建用户组的名称(不可超过20个字符):";
    cin>>name;
    s="create_group:::"+itos(user_id)+":::"+name;
    recv_data(s);
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            s=recv_data("get_group");
            vector<string> res3=split(s,"&&&");
            for(int j=0;j<res3.size();j++) {
                vector<string> res4=split(res3[j],":::");
                if(res4[2]==name) {
                    res2[7]+="::";
                    res2[7]+=res4[0];
                    str1="update_user:::owned_group:::"+itos(user_id)+":::"+res2[7];
                    recv_data(str1);
                }
            }
        }
    }
    //cout<<str<<endl;
    cout<<"创建成功！"<<endl;
    cout<<"按任意键返回"<<endl;
    getchar();
    getch();
    return 1;
}

string Get_username(int user_id)//返回用户名
{
    string str=recv_data("get_user");
    vector<string> users = split(str,"&&&");
    for(int i = 0 ; i < users.size() ; i ++)
    {
        vector<string> user = split(users[i],":::");
        if(user[0] == itos(user_id))
            return user[1];
    }
    return "admin";
}

string Get_groupname(int group_id)//返回用户组名称
{
    string str=recv_data("get_group");
    vector<string> groups = split(str,"&&&");
    for(int i = 0 ; i < groups.size() ; i ++)
    {
        vector<string> group = split(groups[i],":::");
        if(group[0] == itos(group_id))
            return group[2];
    }
    return "admin";
}

#endif            // magic code don't touch  !!!
