#include"parseMsg.hpp"

parseMsg::parseMsg(function<float(float,float)> sum,function<string(string)> uppercase):
requestMsg_({}),
leftBraceCount_(0),
rightBraceCount_(0),
parseIdx(0),
sum_(sum),
uppercase_(uppercase)
{}

