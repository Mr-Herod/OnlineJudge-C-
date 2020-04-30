#ifndef _USER_H
#define _USER_H
#include "datatrans.h"
#include "dataconv.h"
#include "group.h"
#include <bits/stdc++.h>
using namespace std;

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

// Userƪ
int Sign_up();                                  // �û�ע��
int Sign_in();                                  // �û���¼
int Change_info(int user_id);                   // �޸ĸ�����Ϣ
int Mark_user(int user_id,int dest_id);         // ��ע�û�
int Apply_group(int user_id,int group_id);      // ��������û���
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
            int opt;
            cout<<"1.�޸��ǳ�\t2.�޸�����"<<endl;
            cin>>opt;
            if(opt==1) {
                cout<<"���������ǳ�"<<endl;
                cin>>nickname;
                str1="update_user:::user_nickname:::"+itos(user_id)+":::"+nickname;
                recv_data(str1);
                return 1;
            }
            if(opt==2) {
                cout<<"������������"<<endl;
                cin>>password;
                str2="update_user:::user_pwd:::"+itos(user_id)+":::"+password;
                recv_data(str2);
                //cout<<str<<endl;
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
            res2[11]+=itos(dest_id);
            res2[11]+=":: ";
            str1="update_user:::favorite_user:::"+itos(user_id)+":::"+res2[11];
            recv_data(str1);
            //cout<<str<<endl;
            return 1;
        }
    }
    return 0;
}
int Apply_group(int user_id,int group_id){// ��������û���
    string str;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        vector<string> res3=split(res2[7],"::");
        for(int k=0;k<res3.size();k++) {
            if(res3[k]==itos(group_id)) {
                Add_member(Stoi(res2[0]),group_id,user_id);
            }
        }
    }
}
void Show_users(){// �鿴�����û�
    string str;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    cout<<"ID��\t\t�û���\t\t�ǳ�\t\t�ѽ������Ŀ����\t\t���Խ������Ŀ����"<<endl;
    for(int i=0;i<res1.size();i++){
        vector<string> res2=split(res1[i],":::");
        for(int j=0;j<3;j++) {
            cout<<res2[j]<<"\t\t";
        }
        vector<string> res3=split(res2[4],"::");
        vector<string> res4=split(res2[5],"::");
        cout<<"\t"<<res3.size()<<"\t\t\t\t"<<res4.size();
        cout<<endl;
    }
}
void user_show_info(int user_id)
{
    string str;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            cout<<"�û���:"<<res2[1]<<endl;
            cout<<"�ǳ�:"<<res2[2]<<endl;
            cout<<"�ѽ������Ŀ:"<<res2[4]<<endl;
            cout<<"���Խ������Ŀ:"<<res2[5]<<endl;
            cout<<"�ղص���Ŀ:"<<res2[6]<<endl;
            cout<<"�������û���:"<<res2[7]<<endl;
            cout<<"������û���:"<<res2[8]<<endl;
            cout<<"�����ı���:"<<res2[9]<<endl;
            cout<<"����ı���:"<<res2[10]<<endl;
            cout<<"��ע���û�:"<<res2[11]<<endl;
            cout<<"���������coder������"<<endl;
            cout<<"1.�޸���Ϣ   2.�˳�"<<endl;
            string opt;
            cin>>opt;
            if(opt == "1") {
                if(Change_info(user_id)) {
                    cout<<"�޸ĳɹ�"<<endl;
                }
                else {
                    cout<<"�޸�ʧ��"<<endl;
                }
            }
            if(opt == "2") return;
        }
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
            cout<<"�û���:"<<res2[1]<<endl;
            cout<<"�ǳ�:"<<res2[2]<<endl;
            cout<<"�ѽ������Ŀ:"<<res2[4]<<endl;
            cout<<"���Խ������Ŀ:"<<res2[5]<<endl;
            cout<<"�ղص���Ŀ:"<<res2[6]<<endl;
            cout<<"�������û���:"<<res2[7]<<endl;
            cout<<"������û���:"<<res2[8]<<endl;
            cout<<"�����ı���:"<<res2[9]<<endl;
            cout<<"����ı���:"<<res2[10]<<endl;
            cout<<"��ע���û�:"<<res2[11]<<endl;
            cout<<"���������coder������"<<endl;
            cout<<"1.��ע   2.�˳�"<<endl;
            string opt;
            cin>>opt;
            if(opt == "1") {
                if(Mark_user(user_id,uid)) {
                    cout<<"��ע�ɹ�"<<endl;
                }
                else {
                    cout<<"��עʧ��"<<endl;
                }
            }
            if(opt == "2") return;
        }
    }
}

void Find_user(string nickname)
{
    string str;
    str=recv_data("get_user");
    cout<<"ID��\t\t�û���\t\t�ǳ�\t\t�ѽ������Ŀ����\t\t���Խ������Ŀ����"<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(match(res2[1],nickname)) {
            for(int j=0;j<3;j++) {
                cout<<res2[j]<<"\t\t";
            }
            vector<string> res3=split(res2[4],"::");
            vector<string> res4=split(res2[5],"::");
            cout<<"\t"<<res3.size()-1<<"\t\t\t\t"<<res4.size()-1<<endl;
        }
    }
}

int Sign_up()
{
    string username,nickname,word;
    cout<<"�������û���(���ɳ���7���ַ�)��";
    cin>>username;
    if(username.size()>7) {
        cout<<"�����������û���:";
        cin>>username;
    }
    cout<<"�������ǳ�(���ɳ���7���ַ�)��";
    cin>>nickname;
    if(nickname.size()>7) {
        cout<<"�����������ǳ�:";
        cin>>nickname;
    }
    cout<<"����������(���ɺ���:&�ַ�����";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    recv_data(str);
    cout<<"ע��ɹ���"<<endl;
    cout<<"�����������"<<endl;
    getchar();
    getchar();
    return 1;
}


int Sign_in()
{
    string username,word,str;
    cout<<"�������û�����";
    cin>>username;
    cout<<"���������룺";
    cin>>word;
    str=recv_data("get_user");
    //cout<<str<<endl;
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
