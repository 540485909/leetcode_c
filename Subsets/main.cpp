#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

   void dp(vector<vector<int> >&result,vector<int> s,vector<int> &temp,int pos)
    {

     for(int i=pos;i<s.size();i++)
     {
         temp.push_back(s[i]);
         result.push_back(temp);
         dp(result,s,temp,i+1);
         temp.pop_back();
         while(i<s.size()-1&&s[i]==s[i+1])i++;
     }

    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      vector<vector<int> >result;
       if(S.size()==0){
            result.push_back(S);
       return result;
       }
       sort(S.begin(),S.end());

       vector<int> temp;
       result.push_back(temp);
       dp(result,S,temp,0);
       return result;


    }
};
int main()
{
   Solution s;
   vector<int> ivec;
   vector<vector<int> >result;
   ivec.push_back(1);
   ivec.push_back(2);
   ivec.push_back(2);
  //    ivec.push_back(4);
 //  ivec.push_back(5);
 //  ivec.push_back(6);
  /*    ivec.push_back(7);
   ivec.push_back(8);
   ivec.push_back(9);*/
   result=s.subsetsWithDup(ivec);
   cout<<result.size()<<endl;
   for(int i=0;i<result.size();i++)
   {
       for(int j=0;j<result[i].size();j++)
       {
           cout<<result[i][j]<<" ";
       }
       cout<<endl;
   }

}
