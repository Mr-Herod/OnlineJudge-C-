#ifndef _PROBLEM_H
#define _PROBLEM_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// ��Ŀ��
struct Problem{
    int pro_id;                     // ��ĿID���ڱ�ϵͳ��Ψһ��ʶ��
    int pro_num;                    // ��ԭOJ���
    string pro_oj;                  // ԭOJ��
    string pro_title;               // ��Ŀ����
    string pro_source;              // ��Ŀ��Դ
    string pro_description;         // ��Ŀ��ϸ������ʱ�ޣ��ڴ��ޣ����������������ʽ��������
};

// Problemƪ
int Find_pro(int user_id);                                 // ������Ŀ
int View_pro(int pro_id,int user_id);                       // �鿴��Ŀ����
void Show_problems(string type,int user_id);                           // �鿴������Ŀ
int Submit_pro(int pro_id,int user_id);         // �ύ����

// Problemƪ
int Find_pro(int user_id){cout<<"����������"<<endl;}                                 // ������Ŀ
int View_pro(int pro_id,int user_id){cout<<"����������"<<endl;}                       // �鿴��Ŀ����
void Show_problems(string type,int user_id){cout<<"����������"<<endl;}                           // �鿴������Ŀ


#endif            // magic code don't touch  !!!
