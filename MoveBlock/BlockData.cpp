//
// Created by chy on 17-9-22.
//

#include <cstring>
#include "BlockData.h"

BlockData::BlockData(string data, int g)
{
    //构造并初始化
    this->parent=NULL;
    this->block=data;
    this->ePos=this->GetE();
    g_value = g;
    GetHValue();
    GetFValue();
};

int BlockData::GetFValue() {
    return this->f_value=this->g_value + h_value;
}

int BlockData::GetGValue() {
    return this->g_value;
}

int BlockData::GetHValue() {
    //计算f，算法是每个W前的B的总和
    this->h_value=0;
    int bCount=0;
    for(int i=0;i<this->block.size();i++)
    {
        if(this->block[i]=='B')
        {
            bCount++;
        } else if(this->block[i]=='W')
        {
            this->h_value+=bCount;
        }
    }
    return this->h_value;
}

istream & operator>>(istream &in, BlockData &obj)
{
    in>>obj.block;
    return in;
}

ostream & operator << (ostream &out, BlockData &obj)
{
    out<<obj.block<<endl;
}


int BlockData::GetE()
{
    for(int i=0;i<this->block.size();i++)
    {
        if(this->block[i]=='E')
        {
            this->ePos=i;
            return i;
        }
    }
    return -1;
}

BlockData* Move(BlockData* bd,int movePos) {
    //判断参数合法性
    if(movePos<-3||movePos>3||movePos==0){
        return NULL;
    }
    int ePos=bd->ePos;
    if(!((ePos+movePos)>=0&&(ePos+movePos)<bd->block.size()))
    {
        return NULL;
    }

    //计算g
    int g;
    if(abs(movePos)==3)
    {
        g=2;
    } else
    {
        g=1;
    }

    //移动E
    string temp;
    temp=bd->block;
    temp[bd->ePos]=temp[bd->ePos+movePos];
    temp[bd->ePos+movePos]='E';
    BlockData* ans=new BlockData(temp,bd->g_value+g);
    ans->parent=bd;
    return ans;
}
