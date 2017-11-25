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
    BlockData(char* data,int g);
    char block[MAX_SIZE];
    int len;
    int f_value;
    int g_value;
    int h_value;
    int findTime;
    BlockData* parent;
    int GetFValue();
    int GetGValue();
    int GetHValue();
    int ePos;
    int GetE();
    bool operator<(const BlockData&bd)const{ return f_value<bd.g_value;}
    bool operator>(BlockData&bd){ return f_value>=bd.g_value;}
    friend istream & operator >> (istream &in, BlockData &obj);
    friend ostream & operator << (ostream &out, BlockData &obj);
};


BlockData* MoveLeft1(BlockData* bd,int g);
BlockData* MoveLeft2(BlockData* bd,int g);
BlockData* MoveLeft3(BlockData* bd,int g);
BlockData* MoveRight1(BlockData* bd,int g);
BlockData* MoveRight2(BlockData* bd,int g);
BlockData* MoveRight3(BlockData* bd,int g);

#endif //MOVEBLOCKS_BLOCKDATA_H
