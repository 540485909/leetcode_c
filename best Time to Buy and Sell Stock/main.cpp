#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int> &prices) {
//
//        int len=prices.size();
//        if(len<=1)return 0;
//      int minProfit=prices[0];
//      int minProfitlater=prices[len/2];
//      int res=0;
//      int res
//      for(int i=1;i<prices.size();i++)
//      {
//          if(minProfit>prices[i]){minProfit=prices[i];continue;}
//          else if(prices[i]-minProfit>0)
//               res+=prices[i]-minProfit;
//
//      }
//      return res;
////    int len=prices.size();
////    if(len<=1)return 0;
////    int res=0;
////    for(int i=0;i<len-1;i++)
////    {
////        if(prices[i+1]>prices[i])
////            res+=prices[i+1]-prices[i];
////    }
////return res;
//
//    }
//};
class Solution {
public:

    int maxProfit(vector<int> &prices) {
        int len=prices.size();
        if(len<=1)return 0;
      vector<int> pre(len,0);
      vector<int> next(len,0);
      int minProfit=prices[0];

      for(int i=1;i<len;i++)
      {
        pre[i]=prices[i]-minProfit;
        if(minProfit>prices[i])minProfit=prices[i];
        pre[i]=pre[i]>pre[i-1]?pre[i]:pre[i-1];

      }
      int maxP=prices[len-1];
      for(int i=len-2;i>=0;i--)
      {
          next[i]=prices[i]-maxP;
          if(maxP>prices[i])maxP=prices[i];
          next[i]=next[i]>next[i+1]?next[i]:next[i+1];

      }
      int profit=0;
      int tempValue=0;
      for(int i=0;i<len;i++)
      {
          tempValue=pre[i]+next[i];
          if(profit<tempValue)
            profit=tempValue;
      }
      return profit;

    }
};
int main()
{

    return 0;
}
