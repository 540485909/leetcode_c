#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=128;
bool cmp(int a,int b){
return a<b;

}
int main()
{
    int arr[N+1];
    memset(arr,0,sizeof(arr));
    string str;
    while(cin>>str){
      for(int i=0;i<str.size();i++){
          if(!arr[str[i]-'a']){
            arr[str[i]-'a']=1;
          }
          else {
            arr[str[i]-'a']++;
          }

      }
      int maxElem=-1;
      int index=0;
      for(int i=0;i<=N;i++){
        if(maxElem<arr[i]){
            maxElem=arr[i];
            index=i;
        }

      }
      cout<<(char)(index+'a')<<endl;



    }

    return 0;
}
