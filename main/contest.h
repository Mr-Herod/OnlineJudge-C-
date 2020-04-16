#include <bits/stdc++.h>
using namespace std;


// ��ʱ�û��ࣨICU��
struct InContestUser{
    int ICU_id;                     // ICU ID
    int score;                      // �÷֣���������
    int penalty;                    // ��ʱ���������*20�� + ����ʱ�䣩
    map<int,int> solved;            // ͨ������Ŀ�Լ���Ӧ���ύ����
    map<int,int> attemped;          // �ύ��δͨ������Ŀ�Լ���Ӧ���ύ����
};


// ��ʱ��Ŀ�ࣨICP��
struct InContestProblem{
    int ICP_id;                     // ICP ID
    int pro_id;                     // ��ĿID
    string pro_nick_name;           // ����Ŀ����
    int submit;                     // �ύ��
    int solved;                     // ͨ����
};

// ��ʱ�����ࣨICS��
struct InContestStatus{
    int ICS_id;                     // ICS ID
    int ICP_id;                     // ICP ID
    int ICU_id;                     // ICU ID
    int time;                       // �ύʱ��
    string result;                  // ������
    string lang;                    // ��������
};

// ������
struct Contest{
    int contest_id;                 // ����ID
    int contest_owner;              // ����������
    int contest_group;              // ���������û��飨����û�У�
    int contest_start_time;         // ������ʼʱ��
    int contest_length;             // ��������ʱ��
    string contest_title;           // ��������
    string contest_type;            // �������ͣ��������û���˽�У�
    string contest_status;          // ����״̬��scheduled��running��ended��
    vector<InContestUser>    participent;       // �����û�
    vector<InContestProblem> problem;           // ����ѡ��
    vector<InContestStatus>  status;            // ���������¼
    priority_queue<InContestUser> contest_rank; // ��������
};



// Contestƪ
int Find_contest(int user_id);                             // ���ұ���
int View_contest(int contest_id);               // �鿴����
int Run_contest(int contest_id);                // ���б���������֮�أ��Ƚ���ʵ�֣�
/** new **/
void Show_contests(string args);

// Contestƪ
int Find_contest(int user_id){cout<<"����������"<<endl;}                             // ���ұ���
int View_contest(int contest_id){cout<<"����������"<<endl;}               // �鿴����
int Run_contest(int contest_id){cout<<"����������"<<endl;}                // ���б���������֮�أ��Ƚ���ʵ�֣�
/** new **/
void Show_contests(string args){cout<<"����������"<<endl;}                           // �鿴������Ŀ

