//
// Created by chy on 17-10-21.
//

#ifndef DRAWTABLE_DRAWTABLE_H
#define DRAWTABLE_DRAWTABLE_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX_ITEM 1000

class Item{
public:
    string color;
    long long height;
    string itemName;
};

class DrawTable {
public:
    DrawTable(string filename);
    string filename;
    int itemNum;
    long long yMax;
    Item item[MAX_ITEM];
    bool Draw();

private:
    string head;
    string end;
};


#endif //DRAWTABLE_DRAWTABLE_H
