#include <bits/stdc++.h>
//#include "user.h"
#include "group.h"
#include "contest.h"
#include "problem.h"
using namespace std;

// �û���
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
int Submit_pro(int pro_id,int user_id);         // �ύ����
int Mark_user(int user_id,int dest_id);         // ��ע�û�
int Create_group(int user_id);                  // �����û���
int Apply_group(int user_id,int group_id);      // ��������û���
int Create_contest();                           // ��������
/** deleted **/
//int View_user_rank();                         // �鿴�����û�����
/** new  **/
void user_show_info(int user_id);               // �鿴������Ϣ
/** new  **/
void Show_users();                              // �鿴�����û�

// Userƪ
int Sign_out(){cout<<"����������"<<endl;}
int Change_info(int user_id){cout<<"����������"<<endl;}                   // �޸ĸ�����Ϣ
int Submit_pro(int pro_id,int user_id){cout<<"����������"<<endl;}         // �ύ����
int Mark_user(int user_id,int dest_id){cout<<"����������"<<endl;}         // ��ע�û�
int Create_group(int user_id){cout<<"����������"<<endl;}                  // �����û���
int Apply_group(int user_id,int group_id){cout<<"����������"<<endl;}      // ��������û���
int Create_contest(){cout<<"����������"<<endl;}                           // ��������
void Show_users(){cout<<"����������"<<endl;}                              // �鿴�����û�

void user_show_info(int user_id)
{
    cout<<"���������coder������"<<endl;
    cout<<"1.�޸���Ϣ   2.�˳�"<<endl;
}


int Sign_up()
{
    cout<<"ע��ɹ���"<<endl;
    return 1;
}

int Sign_in()
{
    if(true)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

