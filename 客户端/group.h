#ifndef _GROUP_H
#define _GROUP_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
using namespace std;
// Groupƪ
int View_group_contest(int group_id);                       // �鿴�û���ı���
int Create_group(int user_id);                              // �����û���
void Show_groups(string type,int user_id);                  // �鿴������
void Find_group(int user_id);                               // �����û���
int Apply_group(int user_id,int group_id);                  // ��������û���
string Get_username(int user_id);                           // ��ȡ�û��ǳ�
string Get_groupname(int group_id);                         // ��ȡ�û�����

// Groupƪ
/*int Apply_group(int user_id,int group_id){// ��������û���
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            str1=recv_data("get_group");
            vector<string> res3=split(str1,"&&&");
            for(int j=0;j<res3.size();j++) {
                vector<string> res4=split(res3[j],":::");
                if(res4[0]==itos(group_id)) {
                    vector<string> res5=split(res4[3],":::");
                    for(int k=0;k<res5.size();i++) {
                        if(res5[k]==itos(group_id)) {
                            cout<<"�����ڸ��û���"<<endl;
                            return 0;
                        }
                    }
                    res2[8]+="::";
                    res2[8]+=itos(group_id);
                    str1="update_user:::entered_group:::"+itos(user_id)+":::"+res2[8];
                    recv_data(str1);

                    res4[3]+="::";
                    res4[3]+=itos(user_id);
                    str1="update_group:::group_member:::"+itos(group_id)+":::"+res4[3];
                    recv_data(str1);
                    return 1;
                }
            }
        }
    }
    return 0;
}*/
int Apply_group(int user_id,int group_id){// ��������û���
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            str1=recv_data("get_group");
            vector<string> res3=split(str1,"&&&");
            for(int j=0;j<res3.size();j++) {
                vector<string> res4=split(res3[j],":::");
                if(res4[0]==itos(group_id)) {
                    vector<string> res5=split(res4[3],"::");
                    for(int k=0;k<res5.size();k++) {
                        if(res5[k]==itos(user_id)) {
                            cout<<"�����ڸ��û���"<<endl;
                            return 0;
                        }
                    }
                    res2[8]+="::";
                    res2[8]+=itos(group_id);
                    str1="update_user:::entered_group:::"+itos(user_id)+":::"+res2[8];
                    recv_data(str1);
                    res4[3]+="::";
                    res4[3]+=itos(user_id);
                    str1="update_group:::group_member:::"+itos(group_id)+":::"+res4[3];
                    recv_data(str1);
                    return 1;
                }

            }
            cout<<"���û��鲻����"<<endl;
            return 0;
        }
    }
    return 0;
}
int View_group_contest(int group_id){// �鿴�û���ı���
    string str,name;
    str=recv_data("get_group");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(group_id)) {
            vector<string> res3=split(res2[4],"::");
            for(int j=0;j<res3.size();j++) {
                cout<<res3[i];
                if(j%10==0) {
                    cout<<endl;
                }
            }
        }
    }
    cout<<"�����������..."<<endl;
    getch();
    return 1;
}

void Show_groups(string type,int user_id){ // �鿴��
    string str;
    str=recv_data("get_group");
    cout<<setw(6)<<"ID"<<setw(15)<<"������"<<setw(15)<<"����"<<setw(15)<<"��Ա����"<<setw(15)<<"��������"<<endl<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(type=="own"  && res2[1] != itos(user_id))    continue;
        cout<<setw(6)<<res2[0];
        cout<<setw(15)<<Get_username(Stoi(res2[1]));
        cout<<setw(15)<<res2[2];
        vector<string> res3=split(res2[3],"::");
        vector<string> res4=split(res2[4],"::");
        cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
    }
}
void Find_group(string name){// �����û���
    string str;
    str=recv_data("get_group");
    cout<<setw(6)<<"ID"<<setw(15)<<"������"<<setw(15)<<"����"<<setw(15)<<"��Ա����"<<setw(15)<<"��������"<<endl<<endl;
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(match(res2[2],name)) {
            cout<<setw(6)<<res2[0];
            cout<<setw(15)<<Get_username(Stoi(res2[1]));
            cout<<setw(15)<<res2[2];
            vector<string> res3=split(res2[3],"::");
            vector<string> res4=split(res2[4],"::");
            cout<<setw(15)<<res3.size()-1<<setw(15)<<res4.size()-1<<endl;
        }
    }
}

int Create_group(int user_id){// �����û���
    string s,name;
    cout<<"�������½��û��������(���ɳ���20���ַ�):";
    cin>>name;
    s="create_group:::"+itos(user_id)+":::"+name;
    recv_data(s);
    string str,str1;
    str=recv_data("get_user");
    vector<string> res1=split(str,"&&&");
    for(int i=0;i<res1.size();i++) {
        vector<string> res2=split(res1[i],":::");
        if(res2[0]==itos(user_id)) {
            s=recv_data("get_group");
            vector<string> res3=split(s,"&&&");
            for(int j=0;j<res3.size();j++) {
                vector<string> res4=split(res3[j],":::");
                if(res4[2]==name) {
                    res2[7]+="::";
                    res2[7]+=res4[0];
                    str1="update_user:::owned_group:::"+itos(user_id)+":::"+res2[7];
                    recv_data(str1);
                }
            }
        }
    }
    //cout<<str<<endl;
    cout<<"�����ɹ���"<<endl;
    cout<<"�����������"<<endl;
    getchar();
    getch();
    return 1;
}

string Get_username(int user_id)
{
    string str=recv_data("get_user");
    vector<string> users = split(str,"&&&");
    for(int i = 0 ; i < users.size() ; i ++)
    {
        vector<string> user = split(users[i],":::");
        if(user[0] == itos(user_id))
            return user[1];
    }
    return "admin";
}

string Get_groupname(int group_id)
{
    string str=recv_data("get_group");
    vector<string> groups = split(str,"&&&");
    for(int i = 0 ; i < groups.size() ; i ++)
    {
        vector<string> group = split(groups[i],":::");
        if(group[0] == itos(group_id))
            return group[2];
    }
    return "admin";
}

#endif            // magic code don't touch  !!!
