#ifndef SERVER_H
#define SERVER_H
#include<functional>
#include<set>
#include"parseMsg.hpp"
#include"muduo/net/EventLoop.h"
#include"muduo/net/TcpServer.h"
using namespace std;
using namespace muduo;
using namespace muduo::net;
class server{
public:
    server(EventLoop* loop,const InetAddress& listenAddr);

    void start(unsigned int threadCount = 0);

private:
    //1、连接时回调函数
    void onConnectionCallback(const TcpConnectionPtr& conn);

    //2、消息可读回调函数
    void onMessageCallback(const TcpConnectionPtr& conn,Buffer* buf,Timestamp);

private:
    //1、mduuo的服务器对象
    TcpServer server_;
    
    //2、求和远程调用
    float sum(float a,float b){
        return a+b;
    }
    //3、该大写远程调用
    string uppercase(string str){
        transform(str.begin(),str.end(),str.begin(),::toupper);
        return str;
    }

    //4、id集合
    set<string> idSet;

};

#endif