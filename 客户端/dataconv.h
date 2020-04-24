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
            pre = i+3;
            i += 2;
        }
    }
    cout<<res.size()<<endl;
    return res;
}

int stoi(string s)      // string to int
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

#endif            // magic code don't touch  !!!
