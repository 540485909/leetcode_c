#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> &A)
{
    int len=A.size();
    if(len==0)return -1;
    if(len==1)return A[0];

    int i=0,j,k=len-1,cur;
    while(i<=k)
    {
        cur=0;
        j=i+1;
        while(j<=k)
        {
            if(A[j]<A[i])
                j++;
            else{
                cur=j;
                break;
            }

        }

       while(j<=k)
       {
           if(A[cur]<=A[j]){

            if(j==k)
           {
              return cur;
           }
             j++;
           }
          else{
            break;
          }

       }
       i++;


    }
    return -1;


}

int main(){
	int a=1,b=2;
	int &ref=a;
	ref=10;
	a=1;

	cout<<"new a: "<<ref<<""<<a<<endl;
}

