#include <bits/stdc++.h>
using namespace std;


// ��ʱ�û��ࣨICU��
struct InContestUser{
    int ICU_id;                     // ICU ID
    int score;                      // �÷֣���������
    int penalty;                    // ��ʱ���������*20�� + ����ʱ�䣩
    map<int,int> solved;            // ͨ������Ŀ�Լ���Ӧ���ύ����
    map<int,int> attemped;          // �ύ��δͨ������Ŀ�Լ���Ӧ���ύ����
    friend bool operator < (const InContestUser& user1,const InContestUser& user2)
    {
        if(user1.score == user2.score)
            return user1.penalty < user2.penalty;
        return user1.score < user2.score;
    }
};

// ��ʱ��Ŀ�ࣨICP��
struct InContestProblem{
    int ICP_id;                     // ICP ID
    int pro_id;                     // ��ĿID
    int submit;                     // �ύ��
    int solved;                     // ͨ����
    string pro_nickname;           // ����Ŀ����
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
    vector<InContestStatus>  judge;            // ���������¼
    priority_queue<InContestUser> contest_rank; // ��������
};



// Contestƪ
int Find_contest(int user_id);                              // ���ұ���
int View_contest(int contest_id,int user_id);               // �鿴����
int Run_contest(int contest_id);                            // ���б���������֮�أ��Ƚ���ʵ�֣�
/** new **/
void Show_contests(string type,int user_id);
void Show_rank(int contest_id);
// Contestƪ
int Find_contest(int user_id){cout<<"����������"<<endl;}                              // ���ұ���

int View_contest(int contest_id,int user_id)                                        // �鿴����
{
    string opt;
    while(true)
    {
        cout<<"xxx ��һ�β�����"<<endl;
        cout<<"Begin time: 00:00 End time: 1:00"<<endl;
        if(1)
            cout<<"Pending!"<<endl;
        else if('a' == 'b')
            cout<<"Running"<<endl;
        else
            cout<<"Ended!"<<endl;
        for(int i = 0 ; i < 3 ; i ++)
        {
            cout<<"(status)1/2  (pro_id)1    (title)A+B problem"<<endl;
        }
        cout<<"1.�鿴��Ŀ   2.�鿴����  3.����"<<endl;
        cin>>opt;
        if(opt == "1")
        {

        }
        if(opt == "2")
            Show_rank(contest_id);
    }
}

int Run_contest(int contest_id){cout<<"����������"<<endl;}                            // ���б���������֮�أ��Ƚ���ʵ�֣�
/** new **/
void Show_contests(string type,int user_id)                                         // �鿴����
{
    if(type == "all" || type == "own")
        cout<<"";
}

void Show_rank(int contest_id)
{
    cout<<"Rank\tName\tScore\tPenalty"<<endl;
    for(int i = 0 ; i < 3 ; i ++)
    {
        cout<<i<<"\t(name)herod\t(score)3\t(oenalty)100"<<endl;
    }
}
