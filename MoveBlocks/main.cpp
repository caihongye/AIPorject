#include <iostream>
#include "MoveBlock.h"
#include "MoveBlockTest.h"

using  namespace std;
int main() {
    /*
    MoveBlock mv;
    BlockData* ans=mv.RunH("BBBBEWBBWW");
    cout<<"times:"<<ans->findTime<<endl;
    mv.ShowWay(ans);
    ans=mv.RunNew("BBBBEWBBWW");
    cout<<"times:"<<ans->findTime<<endl;
    mv.ShowWay(ans);
     */
    //cin>>mv;
    /*
    MoveBlock mv;
    BlockData* ans1=mv.RunF("BBBWWWE");
    mv.ShowWay(ans1);
    cout<<ans1->findTime<<endl;
    mv.CleanQueue();
    BlockData* ans2=mv.RunH("BBBWWWE");
    cout<<ans2->findTime<<endl;
    mv.ShowWay(ans2);
    mv.CleanQueue();
*/


    MoveBlockTest mvTest;
    mvTest.RunTest();


/*
    MoveBlock mb;
    int deepFindTime=0;
    BlockData* start=new BlockData("WBWWBWBEBW",0);
    BlockData* ansDeep= mb.RunDeep(start,deepFindTime);
    if(ansDeep==NULL) {
        cout << "ansDeep no ans" << endl;
    }
    cout<<"deep:"<<ansDeep->findTime<<endl;
    delete(start);
    mb.CleanQueue();
    mb.CleanQueue();

    BlockData* start1=new BlockData("WBWWBWBEBW",0);
    BlockData* ansDeep1= mb.RunDeep(start1,deepFindTime);
    if(ansDeep1==NULL) {
        cout << "ansDeep no ans" << endl;
    }
    cout<<"deep:"<<ansDeep1->findTime<<endl;
    delete(start1);
    mb.CleanQueue();
*/


    /*
    MoveBlock* mb=new MoveBlock;
    BlockData* ans= mb->RunBreath("WBWBWEBWBW");
    if(ans==NULL) {
        cout << "no ans" << endl;
        return 0;
    }
    cout<<"breadth:"<<ans->findTime<<endl;
    mb->CleanQueue();
    BlockData* ans1= mb->RunBreath("WBWBWEBWBW");
    if(ans1==NULL) {
        cout << "no ans" << endl;
        return 0;
    }
    cout<<"breadth:"<<ans1->findTime<<endl;
    mb->CleanQueue();
*/

    return 0;
}