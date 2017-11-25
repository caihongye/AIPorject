//
// Created by chy on 17-9-25.
//

#include "MoveBlockTest.h"



bool MoveBlockTest::InitTestData()
{
    srand(time(NULL));
    for(int i=0;i<TEST_LEN;i++)
    {
        int ePos=rand()%(TEST_STR_LEN-1);
        for(int j=0;j<TEST_STR_LEN-1;j++)
        {
            if(j==ePos)
            {
                this->testData[i][j]='E';
            } else
            {
                if(rand()%2==0)
                {
                    this->testData[i][j]='W';
                } else
                {
                    this->testData[i][j]='B';
                }
            }
        }
        testData[i][TEST_STR_LEN-1]='\0';
    }
}
void MoveBlockTest::RunTest()
{
    InitTestData();
    avgF[0]=avgG[0]=avgH[0]=findTime[0]=0;
    avgF[1]=avgG[1]=avgH[1]=findTime[1]=0;
    avgF[2]=avgG[2]=avgH[2]=findTime[2]=0;
    avgF[3]=avgG[3]=avgH[3]=findTime[3]=0;
    for(int i=0;i<TEST_LEN;i++)
    {

/*
        MoveBlock* mb=new MoveBlock;
        cout<<"RUN:"<<i<<"|"<<this->testData[i]<<endl;
        BlockData* start=new BlockData(this->testData[i],0);
        BlockData* ans= mb->RunBreath(this->testData[i]);
        if(ans==NULL) {
            cout << "no ans" << endl;
            return;
        }
        cout<<"breadth:"<<ans->findTime<<endl;
        delete(start);
        mb->CleanQueue();
        int deepFindTime=0;
        BlockData* ans1= mb->RunDeep(start,deepFindTime);
        if(ans1==NULL) {
            cout << "no ans" << endl;
        }
        cout<<"deep:"<<ans1->findTime<<endl;
        delete(start);
        mb->CleanQueue();
        */
        /*
        MoveBlock* mb=new MoveBlock;
        cout<<"RUN:"<<i<<"|"<<this->testData[i]<<endl;
        BlockData* start=new BlockData(this->testData[i],0);
        BlockData* ans= mb->RunDeep(start,0);
        cout<<"end"<<endl;
        if(ans==NULL) {
            cout << "no ans" << endl;
        }else{
            cout<<"ok"<<endl;
        }
        mb->ShowWay(ans);
        cout<<ans->findTime<<endl;
        delete(start);
        mb->CleanQueue();
         */

        MoveBlock* mb=new MoveBlock;
        cout<<"RUN:"<<i<<"|"<<this->testData[i]<<endl;
        BlockData* ans= mb->RunF(this->testData[i]);
        avgF[0]+=ans->f_value;
        avgG[0]+=ans->g_value;
        avgH[0]+=ans->h_value;
        findTime[0]+=ans->findTime;
        mb->CleanQueue();
        ans= mb->RunH(this->testData[i]);
        avgF[1]+=ans->f_value;
        avgG[1]+=ans->g_value;
        avgH[1]+=ans->h_value;
        findTime[1]+=ans->findTime;
        mb->CleanQueue();

        BlockData* ansBreadth= mb->RunBreath(this->testData[i]);
        if(ansBreadth==NULL) {
            cout << "ansBreadth no ans" << endl;
            return;
        }
        cout<<"breadth:"<<ansBreadth->findTime<<endl;
        avgF[2]+=ansBreadth->f_value;
        avgG[2]+=ansBreadth->g_value;
        avgH[2]+=ansBreadth->h_value;
        findTime[2]+=ansBreadth->findTime;
        mb->CleanQueue();

        BlockData* startDeep=new BlockData(this->testData[i],0);
        int deepFindTime=0;
        BlockData* ansDeep= mb->RunDeep(startDeep,deepFindTime);
        if(ansDeep==NULL) {
            cout << "ansDeep no ans" << endl;
        }
        cout<<"deepth:"<<ansDeep->findTime<<endl;
        avgF[3]+=ansDeep->f_value;
        avgG[3]+=ansDeep->g_value;
        avgH[3]+=ansDeep->h_value;
        findTime[3]+=ansDeep->findTime;
        delete(startDeep);
        mb->CleanQueue();


        cout<<"RUNF:f:"<<avgF[0]<<"|g:"<<avgG[0]<<"|h:"<<
            avgH[0]<<"|time:"<<findTime[0]<<endl;
        cout<<"RUNH:f:"<<avgF[1]<<"|g:"<<avgG[1]<<"|h:"<<
            avgH[1]<<"|time:"<<findTime[1]<<endl;
        cout<<"RUN_Breadth:f:"<<avgF[2]<<"|g:"<<avgG[2]<<"|h:"<<
            avgH[2]<<"|time:"<<findTime[2]<<endl;
        cout<<"RUN_Deep:f:"<<avgF[3]<<"|g:"<<avgG[3]<<"|h:"<<
            avgH[3]<<"|time:"<<findTime[3]<<endl;

    }

    DrawTable draw("RunTime.html");
    draw.itemNum=4;
    int maxY=findTime[0];
    for(int i=1;i<4;i++){
        if(maxY<findTime[i]){
            maxY=findTime[i];
        }
    }
    draw.yMax=(maxY);
    draw.item[0].height=findTime[0];
    draw.item[0].itemName="RunF";
    draw.item[1].height=findTime[1];
    draw.item[1].itemName="RunH";
    draw.item[2].height=findTime[2];
    draw.item[2].itemName="RunBreadth";
    draw.item[3].height=findTime[3];
    draw.item[3].itemName="RunDeep";
    draw.Draw();

    DrawTable draw2("RunG.html");
    draw2.itemNum=4;
    int maxG=avgG[0];
    for(int i=1;i<4;i++){
        if(maxG<avgG[i]){
            maxG=avgG[i];
        }
        cout<<maxG<<"|"<<avgG[i]<<endl;
    }
    draw2.yMax=(maxG);
    draw2.item[0].height=avgG[0];
    draw2.item[0].itemName="RunF";
    draw2.item[1].height=avgG[1];
    draw2.item[1].itemName="RunH";
    draw2.item[2].height=avgG[2];
    draw2.item[2].itemName="RunBreadth";
    draw2.item[3].height=avgG[3];
    draw2.item[3].itemName="RunDeep";
    draw2.Draw();
}



