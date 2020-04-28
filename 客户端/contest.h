#ifndef _CONTEST_H
#define _CONTEST_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;

// Contestƪ
void Show_contest(string type,int user_id);                     // �г����б���
int  Create_contest(int user_id);                               // ��������
int  Find_contest(int user_id);                                 // ���ұ���
int  IC_view_contest(int contest_id,int user_id);               // �������
void IC_view_rank(int contest_id);                              // �鿴����
void IC_view_problem(int contest_id,int pro_id,int user_id);    // �鿴��Ŀ
void IC_submit_code(int contest_id,int pro_id,int user_id);     // �ύ����
void IC_view_status(int contest_id);                            // �鿴����״̬

// Contestƪ
int Find_contest(int user_id)               // ���ұ���
{
    vector<string> msgs = split(recv_data("view_contests"),"&&&");
    vector<string> msg;
    string name;
    cout<<"�������������:";
    cin>>name;
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
        cout<<"1.�������  2.����"<<endl<<endl;
        for(int i = 0 ; i < msgs.size() ; i ++)
        {
            msg = split(msgs[i],":::");
            if(i != 0 && !match(msg[1],name)) continue;
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                if(msg.size() == 6 && j == 4) break;
                int wid = 0;
                if(j == 0) wid = 5;
                else       wid = 20;
                cout<<setw(wid)<<msg[j];
            }
            cout<<endl;
        }
        cin>>opt;
        if(opt == "2") return 0;
        if(opt == "1")
        {
            int contest_id;
            cout<<"���������ID��";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
    }
}

void Show_contests(string type,int user_id)                                         // �鿴����
{
    vector<string> msgs = split(recv_data("view_contests"),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        if(type == "own" && msg.size() == 6 &&  i != 0 && msg[4] != itos(user_id)) continue;
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            if(msg.size() == 6 && j == 4) break;
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
}

void My_contests(int user_id)                                         // �鿴����
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (�ҵı���) "<<endl;
        cout<<"1.�������   2.����"<<endl<<endl;
        Show_contests("own",user_id);
        cin>>opt;
        if(opt == "1")
        {
            int contest_id;
            cout<<"���������ID��";
            cin>>contest_id;
            IC_view_contest(contest_id,user_id);
        }
        if(opt == "2") return ;
    }
}

int IC_view_contest(int contest_id,int user_id)                                        // �鿴����
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
        vector<string> msgs = split(recv_data("IC_view_contest:::"+itos(contest_id)),"&&&");
        if(msgs[0] == "None")
        {
            cout<<"This contest is not running."<<endl;
            cout<<"�����������..."<<endl;
            getchar();getchar();
            return 1;
        }
        cout<<"1.�鿴��Ŀ   2.�鿴����  3.�鿴ʵʱ����    4.����"<<endl;
        vector<string> msg;
        cout<<endl;
        for(int i = 0 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                int wid = 0;
                if(j == 0) wid = 6;
                else       wid = 20;
                cout<<setw(wid)<<msg[j];
            }
            cout<<endl;
        }
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
        cout<<"1.�ύ����   2.����"<<endl<<endl;
        vector<string> msgs = split(recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id)),"&&&");
        vector<string> msg;
        for(int i = 1 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
            {
                int wid = 20;
                if(j != 0)
                    cout<<setw(wid)<<msg[j];
                else
                    cout<<msg[j];
            }
            cout<<endl;
        }
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
    system("CLS");
    vector<string> msgs = split(recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+"python"),"&&&");
    vector<string> msg;
    cout<<"ţ��������������ϵͳ ver-1.0 (������) "<<endl<<endl;
    cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"�����������..."<<endl;
    getchar();getchar();
}

void IC_view_rank(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_rank:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"�����������..."<<endl;
    getchar();getchar();
}


void IC_view_status(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (ʵʱ����ҳ) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_status:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        for(int j = 0 ; j < msg.size() ; j ++)
        {
            int wid = 0;
            if(j == 0) wid = 5;
            else       wid = 20;
            cout<<setw(wid)<<msg[j];
        }
        cout<<endl;
    }
    cout<<"�����������..."<<endl;
    getchar();getchar();
}

time_t convert_str_to_tm(char * str_time)
{
    struct tm tt;
    memset(&tt,0,sizeof(tt));
    tt.tm_year=atoi(str_time)-1900;
    tt.tm_mon=atoi(str_time+5)-1;
    tt.tm_mday=atoi(str_time+8);
    tt.tm_hour=atoi(str_time+11);
    tt.tm_min=atoi(str_time+14);
    tt.tm_sec=atoi(str_time+17);
    return mktime(&tt);// + 28800;//28800��һ��ƫ����������
}

int Create_contest(int user_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (��������)"<<endl;
    string contest_title;
    string contest_start_time;
    int contest_length;
    string contest_type;
    string problems;
    cout<<"������������⣺";cin>>contest_title;
    cout<<"�����������ʼʱ��(��/��/��/ʱ/��):";cin>>contest_start_time;
    cout<<"���������ʱ��(�Է���Ϊ��λ)��";cin>>contest_length;
    cout<<"�������������(pulic/private/password)��";cin>>contest_type;
    cout<<"�����������Ŀ(��/����)��";cin>>problems;
    vector<string > tmp = split(contest_start_time,"/");
    int seconds = convert_str_to_tm((char *)((tmp[0]+"-"+tmp[1]+"-"+tmp[2]+" "+tmp[3]+":"+tmp[4]+":00").data()));
    problems = zip(split(problems,"/"),"::");
    string contest_group = "1";
    string msg = "create_contest:::"+itos(user_id)+":::"+contest_group+":::"+itos(seconds)+":::"+itos(contest_length*60)+":::"+contest_title+":::"+contest_type+":::"+problems;
    //cout<<msg<<endl;
    recv_data(msg);
    cout<<"���������ɹ��������������..."<<endl;
    getchar();getchar();
}              // ��������


#endif            // magic code don't touch  !!!
