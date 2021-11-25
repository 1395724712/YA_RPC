#include"server.hpp"

#include<string>

#include"muduo/base/Logging.h"
#include"muduo/net/EventLoop.h"
using namespace muduo;

server::server(EventLoop* loop,const InetAddress& listenAddr):
    server_(loop,listenAddr,"YA_RPC server")
{
    server_.setConnectionCallback(bind(&server::onConnectionCallback,this,placeholders::_1));
    server_.setMessageCallback(bind(&server::onMessageCallback,this,placeholders::_1,placeholders::_2,placeholders::_3));
}

void server::start(unsigned int threadNums){
    server_.setThreadNum(threadNums);
    server_.start();
}

void server::onConnectionCallback(const TcpConnectionPtr& conn){
    //1、输出连接信息
    LOG_INFO<<"Connection from "<<conn->peerAddress().toIpPort()<<" to "
        <<conn->localAddress().toIpPort()<<" is "
        <<(conn->connected()?"UP":"DONW");
    
    //todo: 创建一个消息解析对象，保存在动态内存中，由conn.setContent维护
}

void server::onMessageCallback(const TcpConnectionPtr& conn,Buffer* buf,Timestamp)
{
    //1、输出收到的数据
    string msg = buf->retrieveAllAsString();
    LOG_INFO<<"Recive: "<<msg<<"\t"<<"from "<<conn->peerAddress().toIpPort();
    //todo: 将数据传递给消息解析对象
}