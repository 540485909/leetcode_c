#include <iostream>
#include <vector>
#include <algorithm>
/*
http://blog.csdn.net/sunbaigui/article/details/8980904*/
using namespace std;
struct Interval{
    int head;
    int tail;
    Interval():head(0),tail(0){}
    Interval(int h,int t):head(h),tail(t){}
};
/*must defined outside of the class*/
bool cmp(Interval a,Interval b)
{
        if(a.head<b.head)return true;
        else if(a.head==b.head&& a.tail<=b.tail)return true;
        else return false;
}
class Solution {

public:

    Interval mergeInterval(Interval a,Interval b)
    {
        a.tail=b.tail;
        return a;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int len=intervals.size();
        if(len<=1)return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval>::iterator iti,itj;
        for(iti=intervals.begin(),itj=iti+1;itj!=intervals.end();)
        {
            if(iti->tail>=itj->head)
            {
                *iti=mergeInterval(*iti,*itj);
                intervals.erase(itj);
                itj=iti+1;
            }
            else {iti++;itj++;}
        }
        return intervals;


    }
};
int main()
{
    vector<Interval> i;
    i.push_back(Interval(1,4));
     i.push_back(Interval(1,4));
       i.push_back(Interval(1,4));
     i.push_back(Interval(5,5));
      i.push_back(Interval(5,5));
       i.push_back(Interval(5,5));
     // i.push_back(Interval(8,10));
    //   i.push_back(Interval(15,18));
    Solution s;
    s.merge(i);
    return 0;
}
