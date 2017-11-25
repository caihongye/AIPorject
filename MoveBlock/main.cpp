#include <iostream>
#include "MoveBlock.h"

using  namespace std;
int main() {
    MoveBlock mv;
    BlockData* ans=mv.Run("BBWWE");
    cout<<"times:"<<ans->findTime<<endl;
    cout<<ans->g_value<<endl;
    mv.ShowWay(ans);
    mv.CleanQueue();

    return 0;
}