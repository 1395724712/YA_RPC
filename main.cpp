#include"server.hpp"

#include<iostream>

using namespace std;

int main(){
    EventLoop loop;
    InetAddress listenAddr(string("192.168.123.202"),8802);
    server rpcServer(&loop,listenAddr);
    rpcServer.start(0);
    loop.loop();

    cout<<"running sunccess!"<<endl;

}