#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector< bool> wordB(s.length()+1,false);//wordB stands for the string from 0 to i can be segument
        wordB[0]=true;
        for(int i=1;i<s.length()+1;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(wordB[j]&&dict.find(s.substr(j,i-j))!=dict.end()))
                    {
                        wordB[i]=true;
                        break;
                    }
            }
        }
        return wordB[s.length()];

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
