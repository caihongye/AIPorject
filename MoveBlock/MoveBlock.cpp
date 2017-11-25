//
// Created by chy on 17-9-22.
//

#include <cstring>
#include "MoveBlock.h"


MoveBlock::MoveBlock()
:firstData(NULL)
{
}

BlockData* MoveBlock::Run(string data)
{
    findTime=0;
    this->firstData=new BlockData(data,0);

    //将初始状态压入优先队列
    this->blockQueue.push(this->firstData);
    searchMap.insert(pair<string,int>(this->firstData->block,1));
    while(this->blockQueue.size()>0)
    {
        //取队头元素并压入回收队列
        BlockData* topData=this->blockQueue.top();
        this->blockQueue.pop();
        recycleQueue.push(topData);

        //执行移动函数
        int moveOper[]=MOVE_OPER;
        for(int i=0;i<5;i++)
        {
            BlockData* afterOperData=Move(topData,moveOper[i]);
            if(afterOperData==NULL)
            {
                continue;
            }

            //判断是否已经搜索过
            if(searchMap.find(afterOperData->block)!=searchMap.end())
            {
                delete(afterOperData);
                continue;
            }
            cout<<afterOperData->block<<endl;
            searchMap.insert(pair<string,int>(afterOperData->block,1));

            findTime++;

            //判断是否找到答案
            if(afterOperData->GetHValue()==0)
            {
                //找到答案将优先队列的元素压入回收队列
                while (!this->blockQueue.empty())
                {
                    recycleQueue.push(this->blockQueue.top());
                    this->blockQueue.pop();
                }

                //置搜索次数并返回答案
                afterOperData->findTime=findTime;
                return afterOperData;
            }

            //找不到答案，将当前状态压入优先队列
            this->blockQueue.push(afterOperData);
        }
    }
    return NULL;
}


void MoveBlock::ShowWay(BlockData* ans)
{
    //使用栈回溯找路径
    stack<BlockData*>backStack;
    backStack.push(ans);
    BlockData* parent=ans->parent;
    while(parent!=NULL)
    {
        backStack.push(parent);
        parent=parent->parent;
    }
    while (!backStack.empty())
    {
        BlockData* backData=backStack.top();
        backStack.pop();
        cout<<backData->block<<endl;
    }
}

istream & operator>>(istream &in, MoveBlock &obj)
{
    if(obj.firstData!=NULL)
    {
        delete(obj.firstData);
    }
    string firstData;
    cout << "请输入初始值:" << endl;
    in >> firstData;
    obj.firstData=new BlockData(firstData,0);
    return in;
}

ostream & operator << (ostream &out, MoveBlock &obj)
{
    out<<obj.firstData->block<<endl;
}

MoveBlock::~MoveBlock()
{
    this->CleanQueue();
}

bool MoveBlock::CleanQueue()
{
    for(int i=0;i<this->blockQueue.size();i++){
        BlockData* delData=blockQueue.top();
        blockQueue.pop();
        recycleQueue.push(delData);
    }
    for(int i=0;i<recycleQueue.size();i++)
    {
        BlockData* recycleData=recycleQueue.front();
        recycleQueue.pop();
        delete(recycleData);
    }
    return true;
}


//hello