//
// Created by chy on 17-9-22.
//

#ifndef MOVEBLOCKS_MOVEBLOCK_H
#define MOVEBLOCKS_MOVEBLOCK_H

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
using namespace std;
#include "BlockData.h"

//用于优先队列的比较函数，f值最小的优先
struct cmp{
    bool operator()(BlockData* a, BlockData* b){
        return a->f_value>b->f_value;
    }
};

class MoveBlock {
public:
    MoveBlock();        //构造函数
    ~MoveBlock();       //析构函数
    int findTime;       //统计搜索次数
    BlockData* firstData;       //初始状态
    priority_queue<BlockData*,vector<BlockData*>,cmp> blockQueue;       //优先队列
    queue<BlockData*>recycleQueue;          //回收队列
    map<string,int>searchMap;               //记录搜索过的状态
    BlockData* Run(string data);            //搜索函数
    void ShowWay(BlockData* ans);           //回溯路径
    bool CleanQueue();                      //清除内存
    friend istream & operator >> (istream &in, MoveBlock &obj);         //重载输入输出
    friend ostream & operator << (ostream &out, MoveBlock &obj);
};


#endif //MOVEBLOCKS_MOVEBLOCK_H
