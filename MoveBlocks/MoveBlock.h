//
// Created by chy on 17-9-22.
//

#ifndef MOVEBLOCKS_MOVEBLOCK_H
#define MOVEBLOCKS_MOVEBLOCK_H

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include<map>
using namespace std;
#include "BlockData.h"

struct cmpF{
    bool operator()(BlockData* a, BlockData* b){
        return a->f_value>b->f_value;
    }
};

struct cmpH{
    bool operator()(BlockData* a, BlockData* b){
        return a->h_value>b->h_value;
    }
};

class MoveBlock {
public:
    MoveBlock();
    ~MoveBlock();
    long long findTime;
    char type;
    BlockData* firstData;
    priority_queue<BlockData*,vector<BlockData*>,cmpF> blockQueueF;
    priority_queue<BlockData*,vector<BlockData*>,cmpH> blockQueueH;
    queue<BlockData*>recycleQueue;
    queue<BlockData*>breadthQueue;
    BlockData* (*goFunc[6])(BlockData* bd,int g);
    BlockData* RunF(char* data);
    BlockData* RunH(char* data);
    BlockData* RunDeep(BlockData* data,int& deepFindTime);
    BlockData* RunBreath(char* data);
    map<string,int>searchMap;               //记录搜索过的状态

    void ShowWay(BlockData* ans);
    bool CleanQueue();
    friend istream & operator >> (istream &in, MoveBlock &obj);
    friend ostream & operator << (ostream &out, MoveBlock &obj);
};


#endif //MOVEBLOCKS_MOVEBLOCK_H
