#include"parseMsg.hpp"

#include<algorithm>
#include<iostream>
#include<assert.h>

parseMsg::parseMsg(function<float(float,float)> sum,function<string(string)> uppercase):
requestMsg_({}),
replyMsg_({}),
leftBraceCount_(0),
rightBraceCount_(0),
parseIdx(0),
sum_(sum),
uppercase_(uppercase)
{}

bool parseMsg::getRequestMsg(const string& msg){

#ifdef DEBUG_GETMSG_TEST
    cout<<msg<<endl;
#endif

    assert(parseIdx==requestMsg_.size());
    
    requestMsg_ += msg;

    //统计左右大括号出现的次数，以此记录是否收到完整消息
    for(;parseIdx<requestMsg_.size();parseIdx++){
        if(requestMsg_[parseIdx]=='{')
            leftBraceCount_++;
        else if(requestMsg_[parseIdx]=='}')
            rightBraceCount_++;
    }

    assert(leftBraceCount_>=rightBraceCount_);
    if(leftBraceCount_==rightBraceCount_)
        return true;//已收到完整报文，可以应答
    else
        return false;//未收到完整报文，不得应答
}

string parseMsg::getReplyMsg(){
    assert(leftBraceCount_==rightBraceCount_&&parseIdx==requestMsg_.size());

    if(!replyMsg_.empty())
        return replyMsg_;
    
    //1、解析requestMsg_报文
    Reader reader;
    Value requestVal;
    reader.parse(requestMsg_,requestVal);

    Value replyVal;
    if(requestVal["function"].asString() == "sum"){
        float a = requestVal["a"].asFloat();
        float b = requestVal["b"].asFloat();

        replyVal["result"] = sum_(a,b);
        replyMsg_ = replyVal.toStyledString();
    }
    else if(requestVal["function"].asString() == "uppercase"){
        string srcStr = requestVal["str"].asString();
        replyVal["result"] = uppercase_(srcStr);
        replyMsg_ = replyVal.toStyledString();
    }
    
#ifdef DEBUG_GETREPLYMSG_TEST
    cout<<replyMsg_<<endl;
#endif

    return replyMsg_;
}
