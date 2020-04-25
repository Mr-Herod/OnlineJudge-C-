#ifndef _USER_H
#define _USER_H
#include "datatrans.h"
#include "dataconv.h"
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
int Sign_out();                                 // �û��˳�
int Change_info(int user_id);                   // �޸ĸ�����Ϣ
int Mark_user(int user_id,int dest_id);         // ��ע�û�
int Apply_group(int user_id,int group_id);      // ��������û���
void user_show_info(int user_id);               // �鿴������Ϣ
void Show_users();                              // �鿴�����û�



// Userƪ
int Sign_out(){cout<<"����������"<<endl;}
int Change_info(int user_id){cout<<"����������"<<endl;}                   // �޸ĸ�����Ϣ
int Mark_user(int user_id,int dest_id){cout<<"����������"<<endl;}         // ��ע�û�
int Apply_group(int user_id,int group_id){cout<<"����������"<<endl;}      // ��������û���
void Show_users(){cout<<"����������"<<endl;}                              // �鿴�����û�
void View_user(int uid,int user_id);                                    // �鿴ĳ���û���Ϣ
void Find_user(int user_id);                                            // �����û�

void user_show_info(int user_id)
{
    while(true){
        cout<<"���������coder������"<<endl;
        cout<<"1.�޸���Ϣ   2.�˳�"<<endl;
        string opt;
        cin>>opt;
        if(opt == "1") Change_info(user_id);
        if(opt == "2") return;

    }
}

void View_user(int uid,int user_id)
{
    cout<<"������..."<<endl;
}

void Find_user(int user_id)
{
    cout<<"������...."<<endl;
}

int Sign_up()
{
    string username,nickname,word;
    cout<<"�������û�����";
    cin>>username;
    cout<<"�������ǳƣ�";
    cin>>nickname;
    cout<<"����������(���ɺ���:&�ַ�����";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    send_data(str);
    cout<<"ע��ɹ���"<<endl;
    cout<<"�����������"<<endl;
    getchar();
    getchar();
    return 1;
}


int Sign_in()
{
    string nickname,word,str;
    cout<<"�������ǳƣ�";
    cin>>nickname;
    cout<<"���������룺";
    cin>>word;
    str=recv_data("get_user");
    vector<string> users = split(str,"&&&");
    for(int i = 0 ; i < users.size() ; i ++)
    {
        vector<string> user = split(users[i],":::");
        if(user[1] == nickname)
        {
            if(user[2] == word)
                return stoi(user[0]);
            else
                return -1;
        }
    }
    return -1;
}
#endif            // magic code don't touch  !!!
