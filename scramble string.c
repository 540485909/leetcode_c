
class Solution {
public:
	bool isScramble(string s1, string s2) {
		size_t len1 = s1.size();
		size_t len2 = s2.size();
		if (len1 != len2)return false;
		if (s1 == s2) return true;
		int comp[26] = { 0 };
		for (size_t i = 0; i < len1; ++i){
		
			comp[s1[i] - 'a']++;
			comp[s2[i] - 'a']--;
		}
		for (int  i = 0; i < 26; ++i){
			if (comp[i] != 0){
				return false;
			}
		}
		for (int i = 1; i < len1; ++i){
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len1 - i)) && isScramble(s1.substr(i), s2.substr(0, len1-i)))
				return true;
		}
		return false;
	}

	
};
