#ifndef _CONTEST_H
#define _CONTEST_H
#include <bits/stdc++.h>
#include <conio.h>
#include "datatrans.h"
#include "dataconv.h"
using namespace std;

// Contestƪ
time_t convert_str_to_tm(char * str_time);                       // ʱ��ת��
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
        cout<<"1.�������    2.����"<<endl<<endl;
        cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"start_time"<<setw(20)<<"length"<<endl<<endl;
        for(int i = 0 ; i < msgs.size() ; i ++)
        {
            msg = split(msgs[i],":::");
            if(msg[0] == "None") {cout<<"None"<<endl;break;}
            if(!match(msg[1],name)) continue;
            cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<endl;
        }
        cout<<endl;
        opt = getch();
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
    cout<<endl;
    cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"start_time"<<setw(20)<<"length"<<setw(20)<<"status"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}
        if(type == "own" && msg[5] != itos(user_id)) continue;
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<endl;
    }
    cout<<endl;
}

void My_contests(int user_id)                                         // �鿴����
{
    string opt;
    while(true)
    {
        system("CLS");
        cout<<"ţ��������������ϵͳ ver-1.0 (�ҵı���) "<<endl;
        cout<<"1.�������    2.����"<<endl<<endl;
        Show_contests("own",user_id);
        opt = getch();
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
            getch();
            return 1;
        }
        cout<<"1.�鿴��Ŀ    2.�鿴����    3.�鿴ʵʱ����    4.����"<<endl<<endl;
        vector<string> msg = split(msgs[0],":::");;
        cout<<msg[0]<<"    started at: "<<msg[1]<<"    status: "<<msg[3]<<"    length: "<<msg[2]<<endl<<endl;
        cout<<setw(5)<<"id"<<setw(20)<<"title"<<setw(20)<<"submit"<<setw(20)<<"solved"<<endl<<endl;
        for(int i = 2 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            if(msg[0] == "None") {cout<<"None"<<endl;break;}
            cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<endl;
        }
        cout<<endl;
        opt = getch();
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
        vector<string> msgs = split(recv_data("IC_view_problem:::"+itos(contest_id)+":::"+itos(ICP_id)),"&&&");
        if(msgs[0] == "This contest is not running.")
        {
            cout<<endl<<"This contest is not running."<<endl<<endl;
            cout<<"�����������..."<<endl;
            getch();
            break;
        }
        cout<<"1.�ύ����    2.����"<<endl<<endl;
        vector<string> msg;
        for(int i = 1 ; i < msgs.size() ; i  ++)
        {
            msg = split(msgs[i],":::");
            for(int j = 0 ; j < msg.size() ; j ++)
                cout<<msg[j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        opt = getch();
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
    cout<<"��ѡ�����ԣ�1. C    2. C++    3. Python2    4. Python3    5. Java"<<endl;
    string lang;
    lang = getch();
    map<string,string> mp;
    mp["1"] = "C";mp["2"] = "C++";mp["3"] = "Python2";mp["4"] = "Python3";mp["5"] = "Java";
    if(lang != "1" && lang != "2" && lang != "3" && lang != "4" && lang != "5")
        lang = "1";
    system("CLS");
    string msgg = recv_data("IC_submit_code:::"+itos(contest_id)+":::"+itos(user_id)+":::"+itos(ICP_id)+":::"+code+":::"+mp[lang]);
    vector<string> msgs = split(msgg,"&&&");
    vector<string> msg;
    if(msgg == "This contest is not running.")
    {
        cout<<endl<<"This contest is not running."<<endl;
        cout<<endl<<"�����������..."<<endl;
        getch();
    }
    cout<<"ţ��������������ϵͳ ver-1.0 (������) "<<endl<<endl;
    cout<<setw(5)<<"No."<<setw(20)<<"problem"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<setw(20)<<msg[5]<<endl;
    }
    cout<<endl<<"�����������..."<<endl;
    getch();
}

void IC_view_rank(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (����ҳ) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_rank:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    cout<<endl<<setw(6)<<"rank"<<setw(15)<<"user"<<setw(15)<<"score"<<setw(15)<<"penalty"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i ++)
    {
        msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}
        cout<<setw(6)<<msg[0]<<setw(15)<<msg[1]<<setw(15)<<msg[2]<<setw(15)<<msg[3]<<endl;
    }
    cout<<endl;
    cout<<"�����������..."<<endl;
    getch();
}


void IC_view_status(int contest_id)
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (ʵʱ����ҳ) "<<endl;
    vector<string> msgs = split(recv_data("IC_view_status:::"+itos(contest_id)),"&&&");
    vector<string> msg;
    cout<<endl<<setw(5)<<"No."<<setw(20)<<"problem"<<setw(20)<<"user"<<setw(20)<<"time"<<setw(20)<<"language"<<setw(20)<<"result"<<endl<<endl;
    for(int i = 0 ; i < msgs.size() ; i  ++)
    {
        msg = split(msgs[i],":::");
        if(msg[0] == "None") {cout<<"None"<<endl;break;}
        cout<<setw(5)<<msg[0]<<setw(20)<<msg[1]<<setw(20)<<msg[2]<<setw(20)<<msg[3]<<setw(20)<<msg[4]<<setw(20)<<msg[5]<<endl;
    }
    cout<<endl<<"�����������..."<<endl;
    getch();
}



int Create_contest(int user_id)                               // ��������
{
    system("CLS");
    cout<<"ţ��������������ϵͳ ver-1.0 (��������)"<<endl<<endl;
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
    getch();
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
    return mktime(&tt);
}

#endif            // magic code don't touch  !!!
