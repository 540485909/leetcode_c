#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
    int score=0;
    int finalScore=0;
    int eaxmScore=0;
    cin>>eaxmScore;
    score=80+rand()%20;
    cout<<"Æ½Ê±³É¼¨  "<<score<<endl;
    cout<<"final socre "<<score*0.4+eaxmScore*0.6<<endl;
    return main();
}
