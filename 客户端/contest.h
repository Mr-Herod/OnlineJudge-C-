#ifndef _CONTEST_H
#define _CONTEST_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// Contestƪ
int  Find_contest(int user_id);                              // ���ұ���
int  IC_view_contest(int contest_id,int user_id);               // �鿴����
void Show_contest(string type,int user_id);
void IC_view_rank(int contest_id);
void IC_view_problem(int contest_id,int pro_id,int user_id);
void IC_submit_code(int contest_id,int pro_id,int user_id);
void IC_view_status(int contest_id);
int Create_contest(int user_id);                // ��������

// Contestƪ
int Find_contest(int user_id){cout<<"����������"<<endl;}                              // ���ұ���

void Show_contests(string type,int user_id)                                         // �鿴����
{
    cout<<recv_data("view_contests");
}

int IC_view_contest(int contest_id,int user_id)                                        // �鿴����
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
        string msg  = recv_data("IC_view_contest:::"+itos(contest_id));
        if(msg == "This contest is not running.")
        {
            cout<<msg<<endl;
            cout<<"�����������..."<<endl;
            getchar();getchar();
            return 1;
        }
        cout<<"1.�鿴��Ŀ   2.�鿴����  3.�鿴ʵʱ����    4.����"<<endl;
        cout<<msg<<endl<<endl;
        cin>>opt;
        if(opt == "1")
        {
            int ICP_id;
            cout<<"��������ţ�";
            cin>>ICP_id;
            IC_view_problem(contest_id,ICP_id,user_id);
        }
        if(opt == "2")
            IC_view_rank(contest_id);
        if(opt == "3")
            IC_view_status(contest_id);
        if(opt == "4")
            break;
    }
}

void IC_view_problem(int contest_id,int ICP_id,int user_id)
{
    while(true)
    {
        system("CLS");
        string opt;
        cout<<"ţ��������������ϵͳ ver-1.0 (��Ŀҳ) "<<endl;
        cout<<"1.�ύ����   2.����"<<endl;
        cout<<recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id))<<endl;
        cin>>opt;
        if(opt == "2")
            break;
        else
            IC_submit_code(contest_id,ICP_id,user_id);
    }
}

void IC_submit_code(int contest_id,int ICP_id,int user_id)
{
    string code;
    cout<<"��������룺"<<endl;
    cin>>code;
    string result = recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+"python");
    cout<<"��������"<<endl<<result<<endl;
    cout<<"�����������..."<<endl;
    getchar();getchar();

}

void IC_view_rank(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
    cout<<recv_data("IC_view_rank:::"+itos(contest_id))<<endl;
    cout<<"�����������..."<<endl;
    getchar();getchar();
}


void IC_view_status(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (ʵʱ����ҳ) "<<endl;
    cout<<recv_data("IC_view_status:::"+itos(contest_id))<<endl;
    cout<<"�����������..."<<endl;
    getchar();getchar();
}

int Create_contest(int user_id){cout<<"������..."<<endl;}              // ��������
#endif            // magic code don't touch  !!!
