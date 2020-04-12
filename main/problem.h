#include <bits/stdc++.h>
#include "user.h"
#include "group.h"
#include "contest.h"
//#include "problem.h"
using namespace std;

// 题目类
struct Problem{
    int pro_id;                     // 题目ID（在本系统的唯一标识）
    int pro_num;                    // 在原OJ题号
    string pro_oj;                  // 原OJ名
    string pro_title;               // 题目标题
    string pro_source;              // 题目来源
    string pro_description;         // 题目详细描述（时限，内存限，描述，输入输出格式，样例）
};

// Problem篇
int Find_pro();                                 // 查找题目
int View_pro(int pro_id);                       // 查看题目详情
/** new **/
void Show_problems();                           // 查看所有题目

// Problem篇
int Find_pro(){cout<<"待开发……"<<endl;}                                 // 查找题目
int View_pro(int pro_id){cout<<"待开发……"<<endl;}                       // 查看题目详情
/** new **/
void Show_problems(){cout<<"待开发……"<<endl;}                           // 查看所有题目

