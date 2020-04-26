#ifndef _DATATRANS_H
#define _DATATRANS_H
#include <bits/stdc++.h>
#include <WinSock2.h>
//#pragma comment(lib, "libws2_32.a")
using namespace std;

SOCKET ScoketClient;

int socket_init(int port,string addr);
int send_data(string str);
string recv_data(string opt);
void socket_close();

int socket_init(int port,string addr)
{
    WSADATA Wsd;
    if(WSAStartup(MAKEWORD(1,1),&Wsd) != 0)
    {
        cout << "����������ʧ�ܣ��׽�������ʧ��" << endl;
        return -1;
    }
    ScoketClient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (ScoketClient == INVALID_SOCKET)
    {
        cout << "����������ʧ�ܣ������׽���ʧ��" << endl;
        WSACleanup();
        return -1;
    }
    SOCKADDR_IN ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    ServerAddr.sin_addr.S_un.S_addr = inet_addr((char*)addr.data());
    int RetVal = connect(ScoketClient, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (RetVal == SOCKET_ERROR)
    {
        cout << "���ӷ�����ʧ��" << endl;
        socket_close();
        return -1;
    }
    //cout<<"���������ӳɹ�"<<endl;
}


int send_data(string str)
{
    socket_init(12345,"39.97.242.228");
    int RetVal = send(ScoketClient, (char*)str.data(), str.size() ,0);
    if (RetVal == SOCKET_ERROR)
    {
        cout << "��������ʧ��" << endl;
        socket_close();
        return -1;
    }
    socket_close();
    return 1;
}

string recv_data(string opt)
{
    socket_init(12345,"39.97.242.228");
    send(ScoketClient, (char*)opt.data(), opt.size() ,0);
    char RECVBuff[10024];
    memset(RECVBuff,0,sizeof(RECVBuff));
    recv(ScoketClient,RECVBuff,10024, 0);
    socket_close();
    return (RECVBuff);
}

void socket_close()
{
    string opt = "exit";
    send(ScoketClient, (char*)opt.data(), opt.size() ,0);
    closesocket(ScoketClient);
    WSACleanup();
}

#endif            // magic code don't touch  !!!
