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
int Find_pro();                                 // ������Ŀ
int View_pro(int pro_id);                       // �鿴��Ŀ����
/** new **/
void Show_problems(string type,int user_id);                           // �鿴������Ŀ

// Problemƪ
int Find_pro(){cout<<"����������"<<endl;}                                 // ������Ŀ
int View_pro(int pro_id){cout<<"����������"<<endl;}                       // �鿴��Ŀ����
/** new **/
void Show_problems(string type,int user_id){cout<<"����������"<<endl;}                           // �鿴������Ŀ

