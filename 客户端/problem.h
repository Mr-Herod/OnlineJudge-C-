#ifndef _PROBLEM_H
#define _PROBLEM_H
#include "datatrans.h"
#include "dataconv.h"
#include <bits/stdc++.h>
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
int Find_pro(int user_id);                                 // 查找题目
int View_pro(int pro_id,int user_id);                       // 查看题目详情
void Show_problems(string type,int user_id);                           // 查看所有题目
int Submit_pro(int pro_id,int user_id);         // 提交代码

// Problem篇
int Find_pro(int user_id){cout<<"待开发……"<<endl;}                                 // 查找题目
int View_pro(int pro_id,int user_id){cout<<"待开发……"<<endl;}                       // 查看题目详情
void Show_problems(string type,int user_id){cout<<"待开发……"<<endl;}                           // 查看所有题目
int Submit_pro(int pro_id,int user_id){cout<<"待开发……"<<endl;}         // 提交代码



#endif            // magic code don't touch  !!!
