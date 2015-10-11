#include <iostream>
#include<cstring>
#include<vector>
#include<map>
#include<math.h>
#include <stack>
#include <algorithm>
#define m 256
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
struct Interval{
    int start;
    int next;
    Interval():start(0),next(0){}
    Interval(int s,int e):start(s),next(e){}
};


double power(double x,int n)
{
    if(0==n)return 1.0;
    if(1==n)return x;
    int remainder=n%2;
    double result=pow(x,n/2);
    result=result*result*(1==remainder?x:1);

}
double pow(double x,int n)
{
    if(n>0)return power(x,n);
    else if(n<0)return 1.0/power(x,-n);

}

ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
{
    ListNode *root,*p;
    root=new ListNode(-1);
    p=root;
    while(1)
    {
        if(l1==NULL){p->next=l2;break;}
        if(l2==NULL){p->next=l1;break;}
        if(l1->val>l2->val)
        {
            p->next=l2;
            l2=l2->next;
        }
        else if(l2->val>l1->val)
        {
            p->next=l1;
            l1=l1->next;
        }
        p=p->next;
    }
    ListNode *result=root->next;
    delete(root);
    return result;
}
vector< vector<int> > threeSum(vector<int> &num,int target)
{
    map<int,int> mp;
    vector<vector<int> >ival;
    int length=num.size();
    for(int i=0;i<length;i++)
        mp[num[i]]=i;
    map<int,int>::iterator it=mp.end();
    for(vector<int>::iterator i=num.begin();i<num.end();i++)
    {
        vector<int> temp;
        for(vector<int>::iterator j=i+1;j<num.end();j++)
        {
            it=mp.find(target-*i-*j);
            if(it!=mp.end())
            {
            temp.push_back(*i);
            temp.push_back(*j);
            temp.push_back(it->first);

            }
            ival.push_back(temp);
        }
    }
    return ival;
}
bool isValid(string s)
{
    int i=0;
    stack<char> st;
    while(s[i])
    {
        char temp;
        switch(s[i])
        {
            case '(':st.push(s[i]);break;
            case '{':st.push(s[i]);break;
            case '[':st.push(s[i]);break;
            case ')':
                temp=st.top();
                if(temp=='(')
                st.pop();
                else return false;
            case '}':
                temp=st.top();if(temp=='{')st.pop();else return false;
            case ']':temp=st.top();if(temp=='[')st.pop();else return false;
            default:break;
        }
        i++;
    }
    if(st.size()==0)return true;
    else return false;

}
bool cmp(Interval a,Interval b)
{
    return a.start<b.start;
}
vector<Interval> merge(vector<Interval> &intervals) {
    sort(intervals.begin(),intervals.end(),cmp);
    vector<Interval>::iterator temp;
    for(vector<Interval>::iterator it=intervals.begin();it!=intervals.end()-1;it++)
    {
        temp=it+1;

        if((*it).next>(*temp).start)
        {

         (*it).next=(*temp).next;
         intervals.erase(temp);
        }

    }
    return intervals;
}






void setZeroes(vector<vector<int> > &matrix) {
      bool row[matrix.size()];
      bool column[matrix[0].size()];
      for(int i=0;i<matrix.size();i++)
      {
          for(int j=0;j<matrix[0].size();j++)
          {
              if(matrix[i][j]==0)
              {
                  row[i]=true;
                  column[j]=true;
              }
          }

      }
      for(int i=0;i<matrix.size();i++)
      {
          for(int j=0;j<matrix[0].size();j++)
          {
              if(row[i]||column[j])
                matrix[i][j]=0;
          }

    }
}
void merge(int A[], int m, int B[], int n) {
        int i=m-1,j=n-1;
        int k=m+n;
        while(i>=0&&j>=0)
        {
            if(A[i]<=B[j])
            {
                A[k--]=B[j--];
            }
            else A[k--]=A[i--];

        }
        while(i>=0)
            A[k--]=A[i--];
        while(j>=0)
            A[k--]=A[j--];


    }
int main()
{
    int num=10;


    //ListNode l1,l2;


    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
   l1->next=l2;
   cout<<l1->val<<endl;
   cout<<l1->next->val<<endl;



vector<Interval> ivec;
ivec.push_back(Interval(1,3));

ivec.push_back(Interval(2,6));
ivec.push_back(Interval(8,10));
ivec.push_back(Interval(15,18));
vector<Interval> result=merge(ivec);






}
