#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include<tr1/unordered_map>
using namespace std;
class Solution {
public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > result;
            if (num.size() < 4) return result;
            sort(num.begin(), num.end());
            tr1::unordered_map<int, vector<pair<int, int> > > cache;
            for(int i=0;i<num.size()-1;i++)
            {
                for(int j=i+1;j<num.size();j++)
                    cache[num[i]+num[j]].push_back(pair<int,int>(i,j));
            }
            for(int c=0;c<num.size()-1;c++)
            {
                for(int d=c+1;d<num.size();d++)
                {
                    if(cache.find(target-num[c]-num[d])==cache.end())continue;
                    vector<pair<int,int> >vec=cache[target-num[c]-num[d]];
                    for(int i=0;i<vec.size();i++)
                    {
                       if(d>=vec[i].first)continue;
                       int a[4]={num[c],num[d],vec[i].first,vec[i].second};
                       vector<int> temp(a,a+4);
                       sort(temp.begin(),temp.end());
                       result.push_back(temp);
                    }
                }
            }
            sort(result.begin(),result.end());
            result.erase(unique(result.begin(), result.end()), result.end());
            return result;

    }

     /*  int threeSumClosest(vector<int> &num, int target) {
        vector<int> result;
        int len=num.size()-2;
        sort(num.begin(),num.end());

        int j,k;
        int m=100000;
        for(int i=0;i<len;i++)
        {

            j=i+1;
            k=len+1;

            while(j<k)
            {
              if(num[i]+num[j]+num[k]==target)
                return target;
              int diff=num[i]+num[j]+num[k]-target;
              if(abs(diff)<abs(m))m=diff;
              if(num[i]+num[j]+num[k]>target)
              {
                  k--;

              }
                else
                {
                    j++;
                }

            }

        }
        return m+target;

    }
   vector<vector<int> > threeSum(vector<int> &num) {
       vector<vector<int> >result;
       vector<int> temp;

       if(num.size()<3)return result;
       sort(num.begin(),num.end());
       int iCurrentValue=num[0];
       int iCount=num.size()-2;
       int i,j;
       for(int k=0;k<iCount;k++)
       {
           if(k&&num[k]==iCurrentValue)//iterate one do not need to check
           {
               continue;
           }

          i=k+1;j=num.size()-1;

          while(i<j)
          {
              if(num[k]+num[i]+num[j]==0)
              {
                  temp.push_back(num[k]);
                  temp.push_back(num[i]);
                  temp.push_back(num[j]);
                 // sort(temp.begin(),temp.end());
                 if(result.size()==0||temp!=result[result.size()-1])
                  result.push_back(temp);
                  temp.clear();
                  i++;j--;
              }
              else if(num[k]+num[i]+num[j]>0)
              {
                  j--;
              }
              else
              {
                  i++;
              }
              iCurrentValue=num[k];
          }




       }
       return result;
    }*/
};
int main()
{

    int a[4]={1 ,1,1 ,0};
    vector<int> vec(a,a+4);
    Solution s;
   // vector<vector<int> > result=s.threeSum(vec);
   // cout<<s.threeSumClosest(vec,100);
//    cout<<result[0][2];
 //   cout<<result[1][2];


    return 0;
}
