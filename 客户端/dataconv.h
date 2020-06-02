#ifndef _DATACONV_H
#define _DATACONV_H
#include <bits/stdc++.h>
using namespace std;

vector<string>  split(string s,string pat)
{
    s += " ";
    int sz = s.size();
    int ps = pat.size();
    vector<string>  res;
    int pre = 0;
    for(int i = 0 ; i < sz ; i ++)
    {
        if((i+ps-1 < sz && s.substr(i,ps) == pat ) || i == sz-1)
        {
            res.push_back(s.substr(pre,i-pre));
            pre = i+ps;
            i += ps-1;
        }
    }
    return res;
}

int Stoi(string s)      // string to int
{
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

string itos(int x)      // int to string
{
    stringstream ss;
    ss<<x;
    string res;
    ss>>res;
    return res;
}

string zip(vector<string> strs,string opt)
{
    int n = strs.size();
    if(n == 0)  return "";
    string res = strs[0];
    for(int i = 1 ; i < n ; i ++)
        res += opt+strs[i];
    return res;
}

string zip(vector<int> strs,string opt)
{
    int n = strs.size();
    if(n == 0)  return "";
    string res = itos(strs[0]);
    for(int i = 1 ; i < n ; i ++)
        res += opt+itos(strs[i]);
    return res;
}

int match(string str,string pat)
{
    int n = str.size(),m = pat.size();
    int next[150];
    next[0] = -1;
    int i = 0,j = -1 ;
    while(i < m)
    {
        if(j == - 1 || pat[i] == pat[j])
        {
            ++i;++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    i = 0;j = 0;
    int res = 0;
    while(i < n && j < m)
    {
        if(j == -1 || str[i] == pat[j])
        {
            i++; j++;
        }
        else
            j = next[j];
    }
    return j == m;
}

int match(vector<string> msgs,string msg)
{
    int n = msgs.size();
    for(int i = 0 ; i < n ; i ++)
    {
        if(msgs[i] == msg)
            return 1;
    }
    return 0;
}

int match(vector<int> msgs,int msg)
{
    int n = msgs.size();
    for(int i = 0 ; i < n ; i ++)
    {
        if(msgs[i] == msg)
            return 1;
    }
    return 0;
}

#endif            // magic code don't touch  !!!
