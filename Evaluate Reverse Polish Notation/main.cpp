#include<iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cassert>
#include <limits.h>

using namespace std;
#define M 36
vector<int> ivec;
int cal(vector<int> arr)
{
    int cou=0;
    for(int j=0;j<arr.size();j++)
    {
        cout<<arr[j]<<' ';
        for(int k=j+1;k<arr.size();k++)
        {
            if(arr[j]>arr[k])++cou;
        }
    }cout<<endl;
    return cou;
}

int main()
{
    int a;
    string line="";
    while(cin>>line)
    {
    for(int i=0;i<line.length();i++)
    {
     if(line[i]!=',')
        ivec.push_back(line[i]-'0');
    }

    int result=0;
    int cou=cal(ivec);

    for(int j=0;j<ivec.size();j++)
    {
        for(int k=j+1;k<ivec.size();k++)
        {
            swap(ivec[j],ivec[k]);
            int newcou=cal(ivec);
            int dif=cou-newcou;
            if(result<dif)result=dif;

        }

    }
    cout<<result<<endl;
    ivec.clear();
}
}
