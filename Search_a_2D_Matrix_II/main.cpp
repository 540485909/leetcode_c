#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<int> vec ,int target){
        int len=vec.size();
        int low=0,high=len-1;
        while(low<high){
            int mid=(low+high)/2;
            if (vec[mid]==target){
                return true;
            }
            else if(vec[mid]<target){
                 low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return false;

    }
     void divideAndConquer(vector<vector<int> >& matrix, int target,bool &isExit,int ){
         int row=matrix.size();
       if(row<=0){
        return ;
       }
       int column=matrix[0].size();
       if(row==1){
        isExit=binarySearch(matrix[0],target);
        return ;
       }
       if(column==1){
            vector<int> temp;
            for(int i=0;i<matrix.size();i++){
                temp.push_back(matrix[i].front());
            }
            isExit=binarySearch(temp,target);
            return ;

       }

       int lowRow=0,highRow=row-1;
       int lowColumn=0,highColumn=column-1;
       while(lowRow<highRow&&lowColumn<highColumn){
        int midRow=(highRow+lowRow)/2;
        int midColumn=(highColumn+lowColumn)/2;

        if(matrix[lowRow][lowColumn]==target
           ||matrix[midRow][midColumn]==target

           ||matrix[lowRow][midColumn+1]==target
           ||matrix[midRow][highColumn]==target

           ||matrix[midRow+1][lowColumn]==target
           ||matrix[highRow][midColumn]==target

           ||matrix[midRow+1][midColumn+1]==target
           ||matrix[highRow][highColumn]==target) {isExit=true;return;}


      /*leftup*/
        if(matrix[lowRow][lowColumn]<target&&matrix[midRow][midColumn]>target){
            highRow=midRow-1;
            highColumn=midColumn-1;
        }
        /*rightup*/
        if(matrix[lowRow][midColumn+1]<target&&matrix[midRow][highColumn]>target){
            highRow=midRow-1;
            lowColumn=midColumn+1;
        }
        /*left down*/
        if(matrix[midRow+1][lowColumn]<target&&matrix[highRow][midColumn]>target){
           lowRow=midRow+1;
           highColumn=midColumn-1;
        }

        /*right down*/
         if(matrix[midRow+1][midColumn+1]<target&&matrix[highRow][highColumn]>target){
           lowRow=midRow+1;
           lowColumn=midColumn+1;
        }
       }
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
      int len=matrix.size();
      if(len<=0)return false;
      int i=0,j=matrix[0].size()-1;
      while(i<len&&j>=0){
        if(target==matrix[i][j])return true;
        if(target>matrix[i][j]){
            i++;
        }else{
        j--;
        }
      }
      return false;
    }

};
int main()
{
    vector<vector<int> > matrix;

    int a[5]={1,   4,  7, 11, 15};
     int b[5]={2,   5,  8, 12, 19};
      int c[5]={3,   6,  9, 16, 22};
       int d[5]={10, 13, 14, 17, 24};
        int e[5]={18, 21, 23, 26, 30};
         vector<int> tempa(a,a+5);
         vector<int> tempb(b,b+5);
         vector<int> tempc(c,c+5);vector<int> tempd(d,d+5);vector<int> tempe(e,e+5);
         matrix.push_back(tempa);
         matrix.push_back(tempb);
         matrix.push_back(tempc);
         matrix.push_back(tempd);matrix.push_back(tempe);
         Solution s;
         cout<<s.searchMatrix(matrix,20)<<endl;



    cout << "Hello world!" << endl;
    return 0;
}
