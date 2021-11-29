#include"server.hpp"

#include<iostream>

using namespace std;

int main(){
    EventLoop loop;
    InetAddress listenAddr(string("192.168.123.202"),8818);
    server rpcServer(&loop,listenAddr);
    rpcServer.start(3);
    loop.loop();

    cout<<"running sunccess!"<<endl;

}