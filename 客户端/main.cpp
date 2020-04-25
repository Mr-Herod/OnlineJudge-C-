#include <bits/stdc++.h>
#include "user.h"
#include "group.h"
#include "contest.h"
#include "problem.h"
#include "datatrans.h"
#include "dataconv.h"

using namespace std;

// Main flow
void Index_page();                  // ����ҳ��
void Home_page(int user_id);        // �û���ҳ
void Probelm_page(int user_id);     // ����ҳ��
void Contest_page(int user_id);     // ����ҳ��
void User_page(int user_id);        // �û�ҳ��
void Gruop_page(int user_id);       // �û���ҳ��

void test()
{
    vector<string> res;
    res = split("haha:::hehe::heihei::xixi:::houhouhou:::zozo",":::");
    for(int i = 0 ; i < res.size() ; i ++)
    {
        cout<<res[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    //test(); return 0;
    socket_init(12345,"39.97.242.228");
    Index_page();
    socket_close();
    return 0;
}

// Main flow
void Index_page()
{
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ ver-1.0 "<<endl;
        cout<<"1.ע��    2.��¼   3.�˳�"<<endl;
        cin>>opt;
        if(opt == "1")  Sign_up();
        if(opt == "2")
        {
            int user_id = Sign_in();
            cout<<"user logged!"<<endl;
            cout<<user_id<<endl;
            if(user_id != -1)
                Home_page(user_id);
            else if(user_id == -1)
                cout<<"������������������"<<endl;
            else {
                cout<<"�˻���������������"<<endl;
            }
        }
        if(opt == "3")  {cout<<"See you next time."<<endl;getchar();getchar();return;}
    }

}

void Home_page(int user_id)
{
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ(������Ϣҳ) "<<endl;
        cout<<"1.�鿴������Ϣ   2.�鿴��Ŀ  3.�鿴����  4.�鿴�û�  5.�鿴��   6.�˳�"<<endl;
        cin>>opt;
        if(opt == "1")  user_show_info(user_id);
        if(opt == "2")  Probelm_page(user_id);
        if(opt == "3")  Contest_page(user_id);
        if(opt == "4")  User_page(user_id);
        if(opt == "5")  Gruop_page(user_id);
        if(opt == "6")  return;
    }
}


void Contest_page(int user_id)
{
    Show_contests("all",user_id);
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ(����ҳ) "<<endl;
        cout<<"1.ȫ������   2.�ҵı���  3.�鿴����  4.��������  5.��������  6.����"<<endl;
        cin>>opt;
        if(opt == "1") Show_contests("all",user_id);
        if(opt == "2") Show_contests("own",user_id);
        if(opt == "3")
        {
            int contest_id;
            cout<<"���������ID:";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
        if(opt == "4") Find_contest(user_id);
        if(opt == "5") Create_contest(user_id);
        if(opt == "6") return;
    }
}

void Probelm_page(int user_id)
{
    Show_problems("all",user_id);
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ(��Ŀҳ) "<<endl;
        cout<<"1.ͨ������Ŀ  2.���Ե���Ŀ 3.������Ŀ  4.�鿴��Ŀ  5.������Ŀ  6.����"<<endl;
        cin>>opt;
        if(opt == "1") Show_problems("solved",user_id);
        if(opt == "2") Show_problems("attempted",user_id);
        if(opt == "3") Show_problems("all",user_id);
        if(opt == "4") View_pro(1,user_id);
        if(opt == "5") Find_pro(user_id);
        if(opt == "6") return;
    }
}

void User_page(int user_id)
{
    Show_users();
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ(�û�ҳ) "<<endl;
        cout<<"1.�鿴�û�   2.�����û�   3.����"<<endl;
        cin>>opt;
        if(opt == "1")
        {
            int uid;
            cout<<"�������û�ID:";
            cin>>uid;
            View_user(uid,user_id);
        }
        if(opt == "2") Find_user(user_id);
        if(opt == "3") return;
    }
}

void Gruop_page(int user_id)
{
    Show_groups("own",user_id);
    string opt;
    while(true)
    {
        cout<<"ţ��������������ϵͳ(�û���ҳ) "<<endl;
        cout<<"1.�鿴�Լ��û���    2.�鿴�����û���   3.�����û���     4.�����û��� 5.����"<<endl;
        cin>>opt;
        if(opt == "1") Show_groups("own",user_id);
        if(opt == "2") Show_groups("all",user_id);
        if(opt == "3") Find_group(user_id);
        if(opt == "4") Create_group(user_id);
        if(opt == "5") return;
    }
}
