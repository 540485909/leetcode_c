#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*直接内存容易越界*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len=s.size();
        vector<string> result;
        if(len<20)return result;
        map<string,int> mp;
        string subStr="";
        for(int i=0;i+10<len;++i){
          subStr=s.substr(i,i+10);
           if(mp.find(subStr)!=mp.end()){
            mp[subStr]++;
           } else{
            mp[subStr]=1;
           }
        }
        for(map<string,int>::iterator it=mp.begin();it!=mp.end();++it){
            if(it->second>1){
                result.push_back(it->first);
            }
        }
    }
};
/* students please write your program here */
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
	unordered_map<int, int> m;
	vector<string> r;
	int t = 0, i = 0, ss = s.size();
	while (i < 9)
		t = t << 3 | s[i++] & 7;
	while (i < ss)
		if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
			r.push_back(s.substr(i - 9, 10));
	return r;
}
/*两位加密无法处理AAAAAAAAA情况比较棘手*/
vector<string> findRepeatedDnaSequences(string s) {
	unordered_map<int, int> m;
	vector<string> r;
	int t = 0, i = 0, len = s.size();
	for (int i = 0; i < 9; ++i){
		if (s[i] == 'A'){
			t = t << 2 & 0x000FFFFF | 0;
		}
		else if (s[i] == 'C'){
			t = t << 2 & 0x000FFFFF | 1;
		}
		else if (s[i] == 'G'){
			t = t << 2 & 0x000FFFFF | 2;
		}
		else if (s[i] == 'T'){
			t = t << 2 & 0x000FFFFF | 3;
		}
	}
	for (int i = 9; i < len; ++i){
		if (s[i] == 'A'){
			t = t << 2 & 0x000FFFFF | 0;
		}
		else if (s[i] == 'C'){
			t = t << 2 & 0x000FFFFF | 1;
		}
		else if (s[i] == 'G'){
			t = t << 2 & 0x000FFFFF | 2;
		}
		else if (s[i] == 'T'){
			t = t << 2 & 0x000FFFFF | 3;
		}
		if (m[t]){

			r.push_back(s.substr(i - 9, 10));
			m[t] = 0;
		}
		else{
			m[t] = 1;
		}
	}

	return r;
}

int main()
{
    Solution s;
    vector<string> result=s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    cout << "Hello world!" << endl;
    return 0;
}
