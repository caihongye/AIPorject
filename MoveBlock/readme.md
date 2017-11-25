# 浅析A\*算法：
A\*算法是一种静态路由中求解最短路最有效的直接搜索方法，同时也是一种启发式搜索。
定义A*的公式为：f(n)=g(n)+h(n)
其中f(n)为初始状态经由状态n到目标的代价估计，
g(n)是在状态空间中从初始状态到状态n的实际代价，
h(n)表示从状态n到目标状态的最佳路径的代价估计。
***
# 积木块游戏问题描述：
移动积木块游戏的初始排列顺序是：BBWWE，B表示黑牌，W表示白牌，E表示空格。规定：任一牌移入相邻空格，或跳过一张牌移入空格，耗散值为1;跳过两张牌移入空格，耗散为2;不能跳过3或更多的牌移入空格。目标序列为白牌均在黑牌之左，空格位置不计。
***
### 分析：定义f(n)=g(n)+h(n)
其中g(n)从从初始状态到状态n的所需的耗散值，
h(n)定义为每个白块左边黑块个数的总和。
***
#### 项目地址：[github/MoveBlock/](https://github.com/gzhuchy/ArtificialIntelligence.git)
***
### 源代码设计：
定义数据类以及其相应的方法：

### 文件：BlockData.h
```cpp
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
```
### 文件：BlockData.cpp
```cpp
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
```
启发搜索类及其实现方法：

### 文件：MoveBlock.h

```cpp
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
```
### 文件：MoveBlock.cpp
```cpp
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
```
---
