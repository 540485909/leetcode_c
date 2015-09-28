#include <iostream>
#include <cstring>
#include <tr1/unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end1, unordered_set<string> &dict) {
        if(start.size()!=endl.size())
            return 0;
        if(start.empty()||endl.empty())
            return 0;
        if(dict.size()==0)return 0;
        queue<string> queueToPush,queueToPop;
        int distance=1
        queueToPop.push(start);
        while(dict.size()>0&&!queueToPop.empty())
        {
            while(!queueToPop.empty())
            {
                string str(queueToPop.front());
                for(int i=0;i<str.size();i++)
                {
                    for(int j='a';j<='z';j++)
                    {
                        if(j==str[i])
                            continue;
                        char temp=str[i];
                        str[i]=j;
                        if(str==end1)
                            return distance+1;
                        if(dict.count(str)>0)
                        {
                            queueToPush.push(str);
                            dict.erase(str);
                        }
                        str[i]=temp;
                    }
                }

            }
            swap(queueToPush,queueToPop);
            distance++;
        }
        return 0;


    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
