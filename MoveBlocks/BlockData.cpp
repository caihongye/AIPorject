//
// Created by chy on 17-9-22.
//

#include <cstring>
#include "BlockData.h"

BlockData::BlockData(char *data, int g)
{
    this->parent=NULL;
    this->len=strlen(data);
    strcpy(this->block, data);
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
    this->h_value=0;
    int bCount=0;
    for(int i=0;i<strlen(this->block);i++)
    {
        if(this->block[i]=='B')
        {
            bCount++;
        } else if(this->block[i]=='W')
        {
            //cout<<"FIRST:"<<this->h_value<<"ADD:"<<bCount<<endl;
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
    for(int i=0;i<strlen(this->block);i++)
    {
        if(this->block[i]=='E')
        {
            this->ePos=i;
            return i;
        }
    }
    return -1;
}

BlockData* MoveLeft1(BlockData* bd,int g) {
    //cout<<"MoveLeft1"<<endl;
    if(bd->ePos<1)
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos-1];
    temp[bd->ePos-1]='E';
    BlockData* ans=new BlockData(temp,g+1);
    ans->parent=bd;
    return ans;
}

BlockData* MoveLeft2(BlockData* bd,int g) {
    //cout<<"MoveLeft2"<<endl;
    if(bd->ePos<2)
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos-2];
    temp[bd->ePos-2]='E';
    BlockData* ans=new BlockData(temp,g+1);
    ans->parent=bd;
    return ans;
}

BlockData* MoveLeft3(BlockData* bd,int g) {
    //cout<<"MoveLeft3"<<endl;
    if(bd->ePos<3)
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos-3];
    temp[bd->ePos-3]='E';
    BlockData* ans=new BlockData(temp,g+2);
    ans->parent=bd;
    return ans;
}

BlockData* MoveRight1(BlockData* bd,int g) {
    //cout<<"MoveRight1"<<endl;
    if(bd->ePos>strlen(bd->block)-2)
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    //cout<<bd->block<<endl;
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos+1];
    temp[bd->ePos+1]='E';
    BlockData* ans=new BlockData(temp,g+1);
    ans->parent=bd;
    return ans;
}

BlockData* MoveRight2(BlockData* bd,int g) {
    //cout<<"MoveRight2"<<endl;
    if(bd->ePos>strlen(bd->block)-3)
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos+2];
    temp[bd->ePos+2]='E';
    BlockData* ans=new BlockData(temp,g+1);
    ans->parent=bd;
    return ans;
}

BlockData* MoveRight3(BlockData* bd,int g) {
    //cout<<"MoveRight3"<<endl;
    if((bd->ePos)>(strlen(bd->block)-4))
    {
        return NULL;
    }
    char temp[MAX_SIZE];
    strcpy(temp,bd->block);
    temp[bd->ePos]=temp[bd->ePos+3];
    temp[bd->ePos+3]='E';
    BlockData* ans=new BlockData(temp,g+2);
    ans->parent=bd;
    return ans;
}