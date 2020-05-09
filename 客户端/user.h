#ifndef _USER_H
#define _USER_H
#include "datatrans.h"
#include "dataconv.h"
#include "group.h"
#include <bits/stdc++.h>
using namespace std;
/*
struct User{
    int    user_id;                 // �û�ID
    string user_name;               // �û���
    string user_password;           // �û�����
    string user_nickname;           // �û��ǳ�
    vector<int> solved_problem;     // �������Ŀ
    vector<int> attemped_problem;   // ���Ե�δ�������Ŀ
    vector<int> favorite_problem;   // �ղص���Ŀ
    vector<int> owned_group;        // �������û���
    vector<int> entered_group;      // ������û���
    vector<int> owned_contest;      // �����ı���
    vector<int> entered_contest;    // �μӵı��������ύ��¼����μӣ�
    vector<int> favorite_user;      // ��ע���û�
};
*/
// Userƪ
int Sign_up();                                  // �û�ע��
int Sign_in();                                  // �û���¼
int Change_info(int user_id);                   // �޸ĸ�����Ϣ
int Mark_user(int user_id,int dest_id);         // ��ע�û�
void user_show_info(int user_id);               // �鿴������Ϣ
void Show_users();                              // �鿴�����û�
void View_user(int uid,int user_id);            // �鿴ĳ���û���Ϣ
void Find_user(int user_id);                    // �����û�


// Userƪ
int Change_info(int user_id){  // �޸ĸ�����Ϣ
    string str,str1,str2;
    string nickname,password;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            string opt;
            cout<<"1.�޸��ǳ�\t2.�޸�����"<<endl;
            opt=getch();
            if(opt=="1") {
                cout<<"���������ǳ�:";
                cin>>nickname;
                str1="update_user:::user_nickname:::"+itos(user_id)+":::"+nickname;
                recv_data(str1);
                return 1;
            }
            if(opt=="2") {
                cout<<"������������:";
                cin>>password;
                str2="update_user:::user_pwd:::"+itos(user_id)+":::"+password;
                recv_data(str2);
                return 1;
            }
        }
    }
    return 0;
}
int Mark_user(int user_id,int dest_id){ // ��ע�û�
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            vector<string> res3=split(res2[11],"::");
            for(int j=0;j<res3.size();j++) {
                if(res3[j]==itos(dest_id)) {
                    cout<<"�ѹ�ע���û�"<<endl;
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

void Show_users(){// �鿴�����û�
    string str;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    cout<<setw(5)<<"ID��"<<setw(15)<<"�û���"<<setw(15)<<"�ǳ�"<<setw(15)<<"������"<<setw(15)<<"��������"<<endl<<endl;
//    sort()
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

void user_show_info(int user_id)
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (������Ϣҳ) "<<endl;
        cout<<"1.�޸���Ϣ    2.��������û���    3.�˳�"<<endl<<endl;
        string str;
        str=recv_data("get_user");
        vector<string> res1=split(str,"&&&");
        for(int i=0;i<res1.size();i++) {
            vector<string> res2=split(res1[i],":::");
            if(res2[0]==itos(user_id)) {
                cout<<"�û���:  "<<res2[1]<<endl;
                cout<<"�ǳ�:  "<<res2[2]<<endl;
                vector<string> res4=split(res2[4],"::");
                cout<<"�ѽ������Ŀ:  ";
                for(int j=1;j<res4.size();j++) {
                    cout<<res4[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res5=split(res2[5],"::");
                cout<<"���Խ������Ŀ:  ";
                for(int j=1;j<res5.size();j++) {
                    cout<<res5[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res6=split(res2[6],"::");
                cout<<"�ղص���Ŀ:  ";
                for(int j=1;j<res6.size();j++) {
                    cout<<res6[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                cout<<"�������û���:  ";
                vector<string> res7=split(res2[7],"::");
                for(int j=1;j<res7.size();j++) {
                    cout<<Get_groupname(Stoi(res7[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res8=split(res2[8],"::");
                cout<<"������û���:  ";
                for(int j=1;j<res8.size();j++) {
                    cout<<Get_groupname(Stoi(res8[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res9=split(res2[9],"::");
                cout<<"�����ı���:  ";
                for(int j=1;j<res9.size();j++) {
                    cout<<res9[j]<<" ";
                    if(j%10==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res10=split(res2[10],"::");
                cout<<"����ı���:  ";
                for(int j=1;j<res10.size();j++) {
                    cout<<res10[j]<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                vector<string> res11=split(res2[11],"::");
                cout<<"��ע���û�:  ";
                for(int j=1;j<res11.size();j++) {
                    cout<<Get_username(Stoi(res11[j]))<<" ";
                    if(j%50==0) {
                        cout<<endl;
                    }
                }
                cout<<endl;
                cout<<endl<<"���������coder������!"<<endl<<endl;

            }
        }
        string opt;
        opt = getch();
        if(opt == "1") {
            if(Change_info(user_id)) {
                cout<<"�޸ĳɹ�!"<<endl;
                cout<<"�����������..."<<endl;
            }
            else {
                cout<<"�޸�ʧ��!"<<endl;
                cout<<"�����������..."<<endl;
            }
            getch();
        }
        if(opt == "2") {
            int group_id;
            cout<<"�������û����ID:";
            cin>>group_id;
            if(Apply_group(user_id,group_id)) {
                cout<<"����ɹ�!"<<endl;
                cout<<"�����������..."<<endl;
                getch();
            }
            else {
                cout<<"����ʧ��!"<<endl;
                cout<<"�����������..."<<endl;
                getch();
            }
        }
        if(opt == "3") return;
    }
}

void View_user(int uid,int user_id)
{
    string str;
    str=recv_data("get_user");
    //cout<<str<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(uid)) {
            cout<<"�û���:  "<<res2[1]<<endl;
            cout<<"�ǳ�:  "<<res2[2]<<endl;
            vector<string> res4=split(res2[4],"::");
            cout<<"�ѽ������Ŀ:  ";
            for(int j=1;j<res4.size();j++) {
                cout<<res4[j]<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res5=split(res2[5],"::");
            cout<<"���Խ������Ŀ:  ";
            for(int j=1;j<res5.size();j++) {
                cout<<res5[j]<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res6=split(res2[6],"::");
            cout<<"�ղص���Ŀ:   ";
            for(int j=1;j<res6.size();j++) {
                cout<<res6[j]<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            cout<<"�������û���:  ";
            vector<string> res7=split(res2[7],"::");
            for(int j=1;j<res7.size();j++) {
                cout<<Get_groupname(Stoi(res7[j]))<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res8=split(res2[8],"::");
            cout<<"������û���:  ";
            for(int j=1;j<res8.size();j++) {
                cout<<Get_groupname(Stoi(res8[j]))<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res9=split(res2[9],"::");
            cout<<"�����ı���:  ";
            for(int j=1;j<res9.size();j++) {
                cout<<res9[j]<<" ";
                if(j%10==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res10=split(res2[10],"::");
            cout<<"����ı���:  ";
            for(int j=1;j<res10.size();j++) {
                cout<<res10[j]<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            vector<string> res11=split(res2[11],"::");
            cout<<"��ע���û�:  ";
            for(int j=1;j<res11.size();j++) {
                cout<<Get_username(Stoi(res11[j]))<<" ";
                if(j%50==0) {
                    cout<<endl;
                }
            }
            cout<<endl;
            cout<<"1.��ע   2.�˳�"<<endl;
            string opt;
            opt = getch();
            if(opt == "1") {
                if(Mark_user(user_id,uid)&&user_id!=uid) {
                    cout<<"��ע�ɹ�!"<<endl;
                    cout<<"�����������..."<<endl;
                    getch();
                    return ;
                }
                else {
                    cout<<"��עʧ��!"<<endl;
                    cout<<"�����������..."<<endl;
                    getch();
                    return ;
                }
            }
            if(opt == "2") return;
        }
    }
    cout<<"���û������ڣ�"<<endl;
    cout<<"�����������..."<<endl;
    getch();
}

void Find_user(string nickname)
{
    string str;
    str=recv_data("get_user");
    cout<<setw(5)<<"ID��"<<setw(15)<<"�û���"<<setw(15)<<"�ǳ�"<<setw(15)<<"������"<<setw(15)<<"��������"<<endl<<endl;
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
    cout<<"�����������..."<<endl;
    getch();
}

int Sign_up()
{
    string username,nickname,word;
    cout<<"�������û���(���ɳ���20���ַ�)��";
    cin>>username;
    if(username.size()>20) {
        cout<<"�����������û���(���ɳ���20���ַ�)��";
        cin>>username;
    }
    cout<<"�������ǳ�(���ɳ���20���ַ�)��";
    cin>>nickname;
    if(nickname.size()>20) {
        cout<<"�����������ǳ�(���ɳ���20���ַ�):";
        cin>>nickname;
    }
    cout<<"����������(���ɺ���:&�ַ�����";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    recv_data(str);
    cout<<"ע��ɹ���"<<endl;
    cout<<"�����������..."<<endl;
    getch();
    return 1;
}


int Sign_in()
{
    string username,word,str;
    cout<<"�������û�����";
    cin>>username;
    cout<<"���������룺";
    for(int i=0;;i++) {
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
