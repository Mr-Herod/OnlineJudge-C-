#ifndef _USER_H
#define _USER_H
#include "datatrans.h"
#include "dataconv.h"
#include "group.h"
#include <bits/stdc++.h>
using namespace std;

// User篇
int Sign_up();                                  // 用户注册
int Sign_in();                                  // 用户登录
int Change_info(int user_id);                   // 修改个人信息
int Mark_user(int user_id,int dest_id);         // 关注用户
void user_show_info(int user_id);               // 查看个人信息
void Show_users();                              // 查看所有用户
void View_user(int uid,int user_id);            // 查看某个用户信息
void Find_user(string nickname,int user_id);    // 查找用户


// User篇
int Change_info(int user_id){  // 修改个人信息
    while(true) {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (个人信息页) "<<endl;
        cout<<"1.修改信息    2.申请加入用户组    3.退出"<<endl<<endl;
        string str,str1,str2;
        string nickname,password;
        str=recv_data("get_user");
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            if(res2[0]==itos(user_id)) {
                string opt;
                system("CLS");
                cout<<"牛人自制在线评测系统 ver-1.0 (个人信息页) "<<endl;
                cout<<"1.修改昵称    2.修改密码    3.退出"<<endl<<endl;
                opt=getch();
                if(opt=="1") {     //修改昵称
                    cout<<"请输入新昵称:";
                    cin>>nickname;
                    str1="update_user:::user_nickname:::"+itos(user_id)+":::"+nickname;
                    recv_data(str1);
                    return 1;
                }
                if(opt=="2") {       //修改密码
                    cout<<"请输入新密码:";
                    cin>>password;
                    str2="update_user:::user_pwd:::"+itos(user_id)+":::"+password;
                    recv_data(str2);
                    return 1;
                }
                if(opt=="3") {
                    return 0;
                }
            }
        }
    }
    return 0;
}
int Mark_user(int user_id,int dest_id){ // 关注用户
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            vector<string> res3=split(res2[11],"::");
            for(int j=0;j<res3.size();j++) {
                if(res3[j]==itos(dest_id)) {
                    cout<<"已关注该用户!"<<endl;
                    return 0;
                }
            }
            res2[11]+="::";
            res2[11]+=itos(dest_id);
            str1="update_user:::favorite_user:::"+itos(user_id)+":::"+res2[11];
            recv_data(str1);
            return 1;
        }
    }
    return 0;
}

void Show_users(){// 查看所有用户
    string str;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    cout<<setw(5)<<"ID号"<<setw(15)<<"用户名"<<setw(15)<<"昵称"<<setw(15)<<"过题数"<<setw(15)<<"尝试题数"<<endl<<endl;
    for(int i=0;i<res1.size();i++){
        vector<string> res2=split(res1[i],":::");
        cout<<setw(5)<<res2[0];
        for(int j=1;j<3;j++) {
            cout<<setw(15)<<res2[j];
        }
        vector<string> res3=split(res2[4],"::");
        vector<string> res4=split(res2[5],"::");
        cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
    }
}

void user_show_info(int user_id)//查看个人信息
{
    while(true)
    {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (个人信息页) "<<endl;
        cout<<"1.修改信息    2.申请加入用户组    3.退出"<<endl<<endl;
        string str;
        str=recv_data("get_user");
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {//将用户信息分割后输出
            vector<string> res2=split(res1[i],":::");
            if(res2[0]==itos(user_id)) {
                cout<<"用户名:  "<<res2[1]<<endl;
                cout<<"昵称:  "<<res2[2]<<endl;
                vector<string> res4=split(res2[4],"::");
                cout<<"已解决的题目:  ";
                for(int j=1;j<res4.size();j++) {
                    cout<<res4[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res5=split(res2[5],"::");
                cout<<"尝试解决的题目:  ";
                for(int j=1;j<res5.size();j++) {
                    cout<<res5[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res6=split(res2[6],"::");
                cout<<"收藏的题目:  ";
                for(int j=1;j<res6.size();j++) {
                    cout<<res6[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                cout<<"创建的用户组:  ";
                vector<string> res7=split(res2[7],"::");
                for(int j=1;j<res7.size();j++) {
                    cout<<Get_groupname(Stoi(res7[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res8=split(res2[8],"::");
                cout<<"加入的用户组:  ";
                for(int j=1;j<res8.size();j++) {
                    cout<<Get_groupname(Stoi(res8[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res9=split(res2[9],"::");
                cout<<"创建的比赛:  ";
                for(int j=1;j<res9.size();j++) {
                    cout<<res9[j]<<" ";
                    if(j%10==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res10=split(res2[10],"::");
                cout<<"加入的比赛:  ";
                for(int j=1;j<res10.size();j++) {
                    cout<<res10[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res11=split(res2[11],"::");
                cout<<"关注的用户:  ";
                for(int j=1;j<res11.size();j++) {
                    cout<<Get_username(Stoi(res11[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                cout<<endl<<"你是最棒的coder，加油!"<<endl<<endl;
            }
        }
        string opt;
        opt = getch();
        if(opt == "1") {//选择修改自己的信息

            if(Change_info(user_id)) {
                cout<<"修改成功!"<<endl;
                cout<<"按任意键继续..."<<endl;
            }
            else {
                cout<<"修改失败!"<<endl;
                cout<<"按任意键继续..."<<endl;
            }
            getch();
        }
        if(opt == "2") {//选择加入某个用户组
            int group_id;
            cout<<"请输入用户组的ID:";
            cin>>group_id;
            if(Apply_group(user_id,group_id)) {
                cout<<"加入成功!"<<endl;
                cout<<"按任意键继续..."<<endl;
                getch();
            }
            else {
                cout<<"加入失败!"<<endl;
                cout<<"按任意键继续..."<<endl;
                getch();
            }
        }
        if(opt == "3") return;
    }
}

void View_user(int uid,int user_id)//查看某个用户的信息
{
    while(true) {
        int flag=0;
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (用户页) "<<endl;
        cout<<"1.关注   2.返回"<<endl<<endl;
        string str;
        str=recv_data("get_user");
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            if(res2[0]==itos(uid)) {
                flag=1;
                cout<<"用户名:  "<<res2[1]<<endl;
                cout<<"昵称:  "<<res2[2]<<endl;
                vector<string> res4=split(res2[4],"::");
                cout<<"已解决的题目:  ";
                for(int j=1;j<res4.size();j++) {
                    cout<<res4[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res5=split(res2[5],"::");
                cout<<"尝试解决的题目:  ";
                for(int j=1;j<res5.size();j++) {
                    cout<<res5[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res6=split(res2[6],"::");
                cout<<"收藏的题目:   ";
                for(int j=1;j<res6.size();j++) {
                    cout<<res6[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                cout<<"创建的用户组:  ";
                vector<string> res7=split(res2[7],"::");
                for(int j=1;j<res7.size();j++) {
                    cout<<Get_groupname(Stoi(res7[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res8=split(res2[8],"::");
                cout<<"加入的用户组:  ";
                for(int j=1;j<res8.size();j++) {
                    cout<<Get_groupname(Stoi(res8[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res9=split(res2[9],"::");
                cout<<"创建的比赛:  ";
                for(int j=1;j<res9.size();j++) {
                    cout<<res9[j]<<" ";
                    if(j%10==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res10=split(res2[10],"::");
                cout<<"加入的比赛:  ";
                for(int j=1;j<res10.size();j++) {
                    cout<<res10[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res11=split(res2[11],"::");
                cout<<"关注的用户:  ";
                for(int j=1;j<res11.size();j++) {
                    cout<<Get_username(Stoi(res11[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
            }
        }
        if(flag==0) {
            cout<<"该用户不存在!"<<endl;
            cout<<"按任意键退出..."<<endl;
            getch();
            return ;
        }
        else {
            string opt;
            opt = getch();
            if(opt == "1") {//选择关注该用户
                if(Mark_user(user_id,uid)&&user_id!=uid) {
                    cout<<"关注成功!"<<endl;
                    cout<<"按任意键继续..."<<endl;
                    getch();
                    return ;
                }
                else {
                    cout<<"关注失败!"<<endl;
                    cout<<"按任意键继续..."<<endl;
                    getch();
                    return ;
                }
            }
            if(opt == "2") return;
        }
    }
}

void Find_user(string nickname,int user_id)//用kmp查找所有用户中昵称包含输入昵称的用户
{
    while(true) {
        system("CLS");
        cout<<"牛人自制在线评测系统 ver-1.0 (用户页) "<<endl;
        cout<<"1.查看用户    2.返回"<<endl<<endl;
        string str;
        str=recv_data("get_user");
        cout<<setw(5)<<"ID号"<<setw(15)<<"用户名"<<setw(15)<<"昵称"<<setw(15)<<"过题数"<<setw(15)<<"尝试题数"<<endl<<endl;
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            if(match(res2[1],nickname)) {
                cout<<setw(5)<<res2[0];
                for(int j=1;j<3;j++) {
                    cout<<setw(15)<<res2[j];
                }
                vector<string> res3=split(res2[4],"::");
                vector<string> res4=split(res2[5],"::");
                cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
            }
        }
        string opt;
        opt=getch();
        if(opt=="1") {//选择查看某个用户的信息
            int uid;
            cout<<"请输入用户ID:";
            cin>>uid;
            View_user(uid,user_id);
        }
        if(opt=="2") {
            return;
        }
    }
    return ;
}

int Sign_up()//注册用户
{
    string username,nickname,word;
    cout<<"请输入用户名(不可超过20个字符)：";
    cin>>username;
    if(username.size()>20) {
        cout<<"请重新输入用户名(不可超过20个字符)：";
        cin>>username;
    }
    cout<<"请输入昵称(不可超过20个字符)：";
    cin>>nickname;
    if(nickname.size()>20) {
        cout<<"请重新输入昵称(不可超过20个字符):";
        cin>>nickname;
    }
    cout<<"请输入密码(不可含有:&字符）：";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    recv_data(str);
    cout<<"注册成功！"<<endl;
    cout<<"按任意键继续..."<<endl;
    getch();
    return 1;
}


int Sign_in()//登录
{
    string username,word,str;
    cout<<"请输入用户名：";
    cin>>username;
    cout<<"请输入密码：";
    for(int i=0;;i++) {//将输入的密码用*代替
        char ch=getch();
        if(ch==13) {
            break;
        }
        else if(ch==8) {
            if(word.length() == 0) continue;
            word = word.substr(0,word.length()-1);
            cout<<"\b";
            cout<<" ";
            cout<<"\b";
        }
        else {
            word+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    str=recv_data("get_user");
    vector<string> users = split(str,"&&&");
    for(int i = 0 ; i < users.size() ; i ++)
    {
        vector<string> user = split(users[i],":::");
        if(user[1] == username)
        {
            if(user[3] == word)
                return Stoi(user[0]);
            else
                return -1;
        }
    }
    return -1;
}



#endif            // magic code don't touch  !!!
