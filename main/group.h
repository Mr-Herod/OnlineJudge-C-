#include <bits/stdc++.h>
using namespace std;

// �û�����
struct Group{
    int group_id;                   // �û���ID
    int group_name;                 // �û�����
    int group_owner;                // �û��鴴����
    vector<int> group_member;       // �û����Ա
    vector<int> group_contest;      // �û��鴴���ı���
};


// Groupƪ
int Delete_group(int user_id,int group_id);                 // ɾ���û���
int View_group_contest(int group_id);                       // �鿴�û���ı���
int Add_member(int user_id,int group_id,int dest_id);       // ����³�Ա
/** new **/
void Show_groups(string type,int user_id);                  // �鿴������
void Find_group(int user_id);                               // �����û���




// Groupƪ
int Delete_group(int user_id,int group_id){cout<<"����������"<<endl;}                // ɾ���û���
int View_group_contest(int group_id){cout<<"����������"<<endl;}                      // �鿴�û���ı���
int Add_member(int user_id,int group_id,int dest_id){cout<<"����������"<<endl;}      // ����³�Ա
/** new **/
void Show_groups(string type,int user_id){cout<<"����������"<<endl;}                 // �鿴������
void Find_group(int user_id){cout<<"����������"<<endl;}                              // �����û���
