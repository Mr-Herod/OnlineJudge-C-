#include <bits/stdc++.h>
#include <WinSock2.h>

using namespace std;
// 用户类
struct User{
    int    user_id;                 // 用户ID
    string user_name;               // 用户名
    string user_password;           // 用户密码
    string user_nickname;           // 用户昵称
    vector<int> solved_problem;     // 解决的题目
    vector<int> attemped_problem;   // 尝试但未解决的题目
    vector<int> favorite_problem;   // 收藏的题目
    vector<int> owned_group;        // 创建的用户组
    vector<int> entered_group;      // 加入的用户组
    vector<int> owned_contest;      // 创建的比赛
    vector<int> entered_contest;    // 参加的比赛（有提交记录就算参加）
    vector<int> favorite_user;      // 关注的用户
};


// User篇
int Sign_up();                                  // 用户注册
int Sign_in();                                  // 用户登录
int Sign_out();                                 // 用户退出
int Change_info(int user_id);                   // 修改个人信息
int Submit_pro(int pro_id,int user_id);         // 提交代码
int Mark_user(int user_id,int dest_id);         // 关注用户
int Create_group(int user_id);                  // 创建用户组
int Apply_group(int user_id,int group_id);      // 申请加入用户组
int Create_contest(int user_id);                // 创建比赛
/** deleted **/
//int View_user_rank();                         // 查看所有用户排名
/** new  **/
void user_show_info(int user_id);               // 查看个人信息
void Show_users();                              // 查看所有用户

int test(string str)
{
    const int BUF_SIZE = 64;
    int RetVal;
    WSADATA Wsd;
    if(WSAStartup(MAKEWORD(1,1),&Wsd) != 0)
    {
        cout << "初始化套接字动态库失败" << endl;
        return -1;
    }
    SOCKET ScoketClient;
    ScoketClient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (ScoketClient == INVALID_SOCKET)
    {
        cout << "创建套接字失败" << endl;
        WSACleanup();
        return -1;
    }
    SOCKADDR_IN ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(12345);
    ServerAddr.sin_addr.S_un.S_addr = inet_addr("39.97.242.228");
    RetVal = connect(ScoketClient, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (RetVal == SOCKET_ERROR)
    {
        cout << "链接服务器失败" << endl;
        closesocket(ScoketClient);
        WSACleanup();
        return -1;
    }
    char SendBuff[BUF_SIZE];
    char RECVBuff[BUF_SIZE];
    ZeroMemory(SendBuff, BUF_SIZE);
    //cout << "向服务器发送数据" << endl;
    //cin >> SendBuff;
    RetVal = send(ScoketClient, (char*)str.data(), str.size() ,0);
    if (RetVal == SOCKET_ERROR)
    {
        cout << "发送数据失败" << endl;
        closesocket(ScoketClient);
        WSACleanup();
        return -1;
    }
    ZeroMemory(RECVBuff, BUF_SIZE);
    recv(ScoketClient, RECVBuff, BUF_SIZE, 0);
    cout << endl << "从服务器接收数据:" << RECVBuff << endl;
    closesocket(ScoketClient);
    WSACleanup();
}
// User篇
int Sign_out(){cout<<"待开发……"<<endl;}
int Change_info(int user_id){cout<<"待开发……"<<endl;}                   // 修改个人信息
//int Submit_pro(int pro_id,int user_id){cout<<"待开发……"<<endl;}       // 提交代码
int Mark_user(int user_id,int dest_id){cout<<"待开发……"<<endl;}         // 关注用户
int Create_group(int user_id){cout<<"待开发……"<<endl;}                  // 创建用户组
int Apply_group(int user_id,int group_id){cout<<"待开发……"<<endl;}      // 申请加入用户组
int Create_contest(int user_id){cout<<"待开发……"<<endl;}                // 创建比赛
void Show_users(){cout<<"待开发……"<<endl;}                              // 查看所有用户
void View_user(int uid,int user_id);                                    // 查看某个用户信息
void Find_user(int user_id);                                            // 查找用户

void user_show_info(int user_id)
{
    while(true){
        cout<<"你是最棒的coder，加油"<<endl;
        cout<<"1.修改信息   2.退出"<<endl;
        string opt;
        cin>>opt;
        if(opt == "1") Change_info(user_id);
        if(opt == "2") return;

    }
}

void View_user(int uid,int user_id)
{
    cout<<"待开发..."<<endl;
}

void Find_user(int user_id)
{
    cout<<"待开发...."<<endl;
}

int Sign_up()
{
    string username,nickname,word;
    cout<<"请输入用户名：";
    cin>>username;
    cout<<"请输入用户昵称：";
    cin>>nickname;
    cout<<"请输入密码:";
    cin>>word;
    string str;
    str="create_user:::"+username+":::"+nickname+":::"+word;
    test(str);
    cout<<"注册成功！"<<endl;
    cout<<"按任意键返回"<<endl;
    getchar();
    getchar();
    return 1;
}


int Sign_in()
{

    if(true)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

