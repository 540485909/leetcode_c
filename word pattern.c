#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		size_t pLen = pattern.size();
		size_t sLen = str.size();
		int pIndex = 0;
		map<char, string> mp;
		map<string, char> reverse_mp;
		int i = 0;
		for (; i < sLen&&pIndex < pLen;++i){
			int j = i;
			while (j < sLen&&str[j] != ' ')j++;

			mp[pattern[pIndex]] = str.substr(i, j - i);
			reverse_mp[str.substr(i, j - i)] = pattern[pIndex++];
			i = j;
		}
		if (mp.size() != reverse_mp.size())return false;
		if (pIndex < pLen) return false;
		if (i < sLen) return false;
		string result;
		i = 0;
		for (; i < pLen; ++i){
			result = result + mp.find(pattern[i])->second + ' ';
		}
		result.pop_back();
		return result == str;

	}
};

int main(){
	
	Solution s;
	cout<<s.wordPattern("abba", "dog cat cat dog");


}
