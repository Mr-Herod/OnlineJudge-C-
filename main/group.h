#include <bits/stdc++.h>
#include "user.h"
//#include "group.h"
#include "contest.h"
#include "problem.h"
using namespace std;

// 用户组类
struct Group{
    int group_id;                   // 用户组ID
    int group_name;                 // 用户组名
    int group_owner;                // 用户组创建者
    vector<int> group_member;       // 用户组成员
    vector<int> group_contest;      // 用户组创建的比赛
};


// Group篇
int Delete_group(int user_id,int group_id);     // 删除用户组
int View_group_contest(int group_id);           // 查看用户组的比赛
int Add_member(int user_id,int group_id,int dest_id);   // 添加新成员
/** new **/
void Show_groups();                             // 查看所有组

// Group篇
int Delete_group(int user_id,int group_id){cout<<"待开发……"<<endl;}     // 删除用户组
int View_group_contest(int group_id){cout<<"待开发……"<<endl;}           // 查看用户组的比赛
int Add_member(int user_id,int group_id,int dest_id){cout<<"待开发……"<<endl;}   // 添加新成员
/** new **/
void Show_groups(){cout<<"待开发……"<<endl;}                             // 查看所有组
