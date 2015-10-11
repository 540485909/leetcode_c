#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n));
        if(n<=1)return matrix;
        int start_position=0,end_position=n-1;
        int value=1;
        int i=0,j=0;
        bool flag=false;
        if(n%2==0)flag=true;
        else flag=false;
             cout<<pow(n,2)<<endl;
       if(flag){
        while(value<=pow(n,2))
        {

            while(i==start_position&&j<end_position)
            {
                 matrix[i][j]=value;
                 j++;
                 value++;
            }
            while(j==end_position&&i<end_position)
            {
                matrix[i][j]=value;
                i++;
                value++;
            }
            while(i==end_position&&j>start_position)
            {
                matrix[i][j]=value;
                j--;
                value++;
            }
            while(j==start_position&&i>start_position)
            {
                matrix[i][j]=value;
                i--;
                value++;
            }
            start_position++;
            end_position--;
            i=start_position;
            j=start_position;


        }
       }
       else{
         while(value<pow(n,2))
        {

            while(i==start_position&&j<end_position)
            {
                 matrix[i][j]=value;
                 j++;
                 value++;
            }
            while(j==end_position&&i<end_position)
            {
                matrix[i][j]=value;
                i++;
                value++;
            }
            while(i==end_position&&j>start_position)
            {
                matrix[i][j]=value;
                j--;
                value++;
            }
            while(j==start_position&&i>start_position)
            {
                matrix[i][j]=value;
                i--;
                value++;
            }
            start_position++;
            end_position--;
            i=start_position;
            j=start_position;


        }
        matrix[start_position][end_position]=value;
       }
        return matrix;
    }
};
int main()
{
    Solution s;
    int n=7;
      vector<vector<int> > matrix=s.generateMatrix(n);
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<"       ";
          cout<<endl;
      }

    return 0;
}
