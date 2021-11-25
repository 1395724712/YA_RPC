#include"server.hpp"

#include<iostream>

using namespace std;

float sum(float a,float b){

}

int main(){
    EventLoop loop;
    InetAddress listenAddr(string("192.168.123.202"),8807);
    server rpcServer(&loop,listenAddr);
    rpcServer.start(0);
    loop.loop();

    cout<<"running sunccess!"<<endl;

}