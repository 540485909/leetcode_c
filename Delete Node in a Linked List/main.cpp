#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   float a;
   cin>>a;
   float factor=(rand() % (90-70+1))+ 70;
   cout<<factor<<endl;
   cout<<(int)(a*0.7+factor*0.3+0.5)<<endl;

  cout<<endl;
  cout<<endl;
    return main();
}
