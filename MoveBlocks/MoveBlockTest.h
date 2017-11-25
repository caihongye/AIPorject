//
// Created by chy on 17-9-25.
//

#ifndef MOVEBLOCKS_MOVEBLOCKTEST_H
#define MOVEBLOCKS_MOVEBLOCKTEST_H


#include "GobalData.h"
#include "MoveBlock.h"
#include "DrawTable.h"

class MoveBlockTest {
    MoveBlock mvTest;
    char testData[TEST_LEN][TEST_STR_LEN];
    bool InitTestData();
    long long avgF[MAX_SIZE];
    long long avgG[MAX_SIZE];
    long long avgH[MAX_SIZE];
    long long findTime[MAX_SIZE];
public:
    void RunTest();
};


#endif //MOVEBLOCKS_MOVEBLOCKTEST_H
