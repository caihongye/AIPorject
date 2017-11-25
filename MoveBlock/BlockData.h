//
// Created by chy on 17-9-22.
//

#ifndef MOVEBLOCKS_BLOCKDATA_H
#define MOVEBLOCKS_BLOCKDATA_H

#include "cstring"
#include "GobalData.h"
#include <iostream>
using namespace std;

class BlockData {
public:
    BlockData(string data,int g);    //构造函数
    string block;           //当前数据
    int f_value;                    //f值
    int g_value;                    //g值
    int h_value;                    //h值
    int findTime;                   //到当前状态所需要的搜索次数，为了计算性能
    BlockData* parent;              //父节点指针
    int GetFValue();                //获取f
    int GetGValue();                //获取g
    int GetHValue();                //获取h
    int ePos;                       //空格E的位置
    int GetE();                     //获取空格E的位置
    bool operator<(const BlockData&bd)const{ return f_value<bd.g_value;}        //重载比较
    bool operator>(BlockData&bd){ return f_value>=bd.g_value;}                  //重载比较
    friend istream & operator >> (istream &in, BlockData &obj);                 //重载输出
    friend ostream & operator << (ostream &out, BlockData &obj);                //重载输出
};

//移动E函数
BlockData* Move(BlockData* bd,int movePos);

#endif //MOVEBLOCKS_BLOCKDATA_H
