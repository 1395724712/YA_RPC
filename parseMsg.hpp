//这里实现的类负责解析信息，并调用相应的远程调用函数
#ifndef PARSEMSG_H
#define PARSEMSG_H

#include<functional>
#include<string>
#include"json/json.h"

using namespace std;
using namespace Json;
class parseMsg{
public:
    parseMsg(function<float(float,float)> sum,function<string(string)> uppercase);

    void getMsg(string msg);

private:
    //1、请求数据
    string requestMsg_;
    
    //2、左大括号数量
    unsigned int leftBraceCount_;
    //3、右大括号数量
    unsigned int rightBraceCount_;
    
    //4、当前已经解析的位置
    unsigned int parseIdx;

    //5、远程调用sum
    function<float(float,float)> sum_;
    //6、远程调用uppercase
    function<string(string)> uppercase_;
    //7、结束连接的远程调用
}

#endif