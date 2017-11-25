//
// Created by chy on 17-9-22.
//

#include <cstring>
#include "MoveBlock.h"


MoveBlock::MoveBlock()
:firstData(NULL)
{
    this->type=' ';
    this->goFunc[0]=MoveLeft1;
    this->goFunc[1]=MoveLeft2;
    this->goFunc[2]=MoveLeft3;
    this->goFunc[3]=MoveRight1;
    this->goFunc[4]=MoveRight2;
    this->goFunc[5]=MoveRight3;
}

BlockData* MoveBlock::RunF(char* data)
{
    this->firstData=new BlockData(data,0);
    findTime=0;
    this->blockQueueF.push(this->firstData);
    while(this->blockQueueF.size()>0)
    {
        BlockData* topData=this->blockQueueF.top();
        this->blockQueueF.pop();
        recycleQueue.push(topData);
        for(int i=0;i<6;i++)
        {
            findTime++;
            BlockData* afterOperData=((this->goFunc)[i])(topData,topData->g_value);
            if(afterOperData==NULL)
            {
                continue;
            }
            if(afterOperData->GetHValue()==0)
            {
                //cout<<"找到答案！搜索步骤:"<<findTime<<endl;
                //this->ShowWay(afterOperData);
                while (!this->blockQueueF.empty())
                {
                    recycleQueue.push(this->blockQueueF.top());
                    this->blockQueueF.pop();
                }
                afterOperData->findTime=findTime;
                return afterOperData;
            }

            //判断是否已经搜索过
            if(searchMap.find(afterOperData->block)!=searchMap.end())
            {
                delete(afterOperData);
                continue;
            }
            searchMap.insert(pair<string,int>(afterOperData->block,1));
            this->blockQueueF.push(afterOperData);
        }
        //cout<<"top:"<<blockQueue.top()->block<<"|"<<runQueue->top()->f_value<<"|"<<blockQueue.top()->h_value<<endl;
    }
    return NULL;
}


BlockData* MoveBlock::RunH(char* data)
{
    this->firstData=new BlockData(data,0);
    findTime=0;
    this->blockQueueH.push(this->firstData);
    while(this->blockQueueH.size()>0)
    {
        BlockData* topData=this->blockQueueH.top();
        this->blockQueueH.pop();
        recycleQueue.push(topData);
        for(int i=0;i<6;i++)
        {
            findTime++;
            BlockData* afterOperData=((this->goFunc)[i])(topData,topData->g_value);
            if(afterOperData==NULL)
            {
                continue;
            }
            if(afterOperData->GetHValue()==0)
            {
                //cout<<"找到答案！搜索步骤:"<<findTime<<endl;
                //this->ShowWay(afterOperData);
                while (!this->blockQueueH.empty())
                {
                    recycleQueue.push(this->blockQueueH.top());
                    this->blockQueueH.pop();
                }
                afterOperData->findTime=findTime;
                return afterOperData;
            }

            //判断是否已经搜索过
            if(searchMap.find(afterOperData->block)!=searchMap.end())
            {
                delete(afterOperData);
                continue;
            }
            searchMap.insert(pair<string,int>(afterOperData->block,1));

            this->blockQueueH.push(afterOperData);
        }
        //cout<<"top:"<<blockQueue.top()->block<<"|"<<runQueue->top()->f_value<<"|"<<blockQueue.top()->h_value<<endl;
    }
    return NULL;
}

BlockData* MoveBlock::RunDeep(BlockData* data,int& deepFindTime)
{
    for (int i = 0; i < 6; i++) {
        BlockData *afterOperData = ((this->goFunc)[i])(data, data->g_value);
        if (afterOperData == NULL) {
            continue;
        }
        afterOperData->findTime=deepFindTime++;
        afterOperData->parent=data;
        this->recycleQueue.push(afterOperData);
        if (afterOperData->GetHValue() == 0) {
            return afterOperData;
        }
        //判断是否已经搜索过
        if(searchMap.find(afterOperData->block)!=searchMap.end())
        {
            continue;
        }
        searchMap.insert(pair<string,int>(afterOperData->block,1));

        BlockData *ansOperData = RunDeep(afterOperData,deepFindTime);
        if(ansOperData!=NULL){
            return ansOperData;
        }
    }
    return NULL;
}

BlockData* MoveBlock::RunBreath(char* data)
{
    this->firstData=new BlockData(data,0);
    findTime=0;
    this->breadthQueue.push(this->firstData);
    searchMap.insert(pair<string,int>(firstData->block,1));
    while(this->breadthQueue.size()>0)
    {
        BlockData* topData=this->breadthQueue.front();
        this->breadthQueue.pop();
        recycleQueue.push(topData);
        for(int i=0;i<6;i++)
        {
            findTime++;
            BlockData* afterOperData=((this->goFunc)[i])(topData,topData->g_value);
            if(afterOperData==NULL)
            {
                continue;
            }
            if(afterOperData->GetHValue()==0)
            {
                afterOperData->findTime=findTime;
                this->breadthQueue.push(afterOperData);
                return afterOperData;
            }
            //判断是否已经搜索过
            if(searchMap.find(afterOperData->block)!=searchMap.end())
            {
                delete(afterOperData);
                continue;
            }
            searchMap.insert(pair<string,int>(afterOperData->block,1));
            this->breadthQueue.push(afterOperData);
        }
        //cout<<"top:"<<blockQueue.top()->block<<"|"<<runQueue->top()->f_value<<"|"<<blockQueue.top()->h_value<<endl;
    }
    return NULL;
}


void MoveBlock::ShowWay(BlockData* ans)
{
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
    cout<<"f:"<<ans->f_value<<"|g:"<<ans->g_value<<"|h:"<<ans->h_value<<endl;
}

istream & operator>>(istream &in, MoveBlock &obj)
{
    if(obj.firstData!=NULL)
    {
        delete(obj.firstData);
    }
    char firstData[MAX_SIZE];
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

    cout<<"BeforeClean:"<<this->blockQueueF.size()<<"|"<<blockQueueH.size()<<"|"<<breadthQueue.size()<<"|"<<recycleQueue.size()<<endl;
    while(!blockQueueF.empty()){
        BlockData* delData=blockQueueF.top();
        blockQueueF.pop();
        recycleQueue.push(delData);
    }
    cout<<"clear blockQueueF ok"<<endl;

    while(!blockQueueH.empty()){
        BlockData* delData=blockQueueH.top();
        blockQueueH.pop();
        recycleQueue.push(delData);
    }
    cout<<"clear blockQueueH ok"<<endl
            ;
    while(!breadthQueue.empty()){
        BlockData* delData=breadthQueue.front();
        breadthQueue.pop();
        recycleQueue.push(delData);
    }
    cout<<"clear breadthQueue ok"<<endl;

    while(!recycleQueue.empty())
    {
        BlockData* recycleData=recycleQueue.front();
        recycleQueue.pop();
        delete(recycleData);
    }
    cout<<"clear recycleQueue ok"<<endl;

    this->searchMap.clear();
    cout<<"clear searchMap ok"<<endl;
    cout<<"AfterClean:"<<this->blockQueueF.size()<<"|"<<blockQueueH.size()<<"|"<<breadthQueue.size()<<"|"<<recycleQueue.size()<<endl;

    //cout<<"clean over"<<endl;
    //cout<<this->blockQueueF.size()<<"|"<<this->blockQueueH.size()<<"|"<<this->recycleQueue.size()<<endl;
    return true;
}