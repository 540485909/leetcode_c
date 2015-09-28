#include <iostream>
#include <tr1/unordered_map>
#include <hash_fun.h>
#include <tr1/hashtable.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        tr1::unordered_map<int,int> mp;
       tr1::hash<string> hash_fn;
        vector<string> v;
        for(int i=0;i+9<s.size();i++){
            int subS=s.substr(i,10);
            int h=hash_fn(subS);
            if(mp.find(h)==mp.end()){
                mp[h]=1;
            }
            else{
                if(mp[h]==1){
                    v.push_back(subS);
                    mp[h]++;
                }
            }
        }
        return v;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
