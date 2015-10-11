#include <iostream>
#include <cstring>
using namespace std;
class TrieNode {
public:
	bool isKey;
	TrieNode* children[26];
	TrieNode() : isKey(false) {
		memset(children, NULL, sizeof(TrieNode*) * 26);
	}
};

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* run = root;
		for (char c : word) {
			if (!(run->children[c - 'a']))
				run->children[c - 'a'] = new TrieNode();
			run = run->children[c - 'a'];
		}
		run->isKey = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return query(word.c_str(), root);
	}

private:
	TrieNode* root;

	bool query(const char* word, TrieNode* node) {
		TrieNode* run = node;
		for (int i = 0; word[i]; i++) {
			if (run && word[i] != '.')
				run = run->children[word[i] - 'a'];
			else if (run && word[i] == '.') {
				TrieNode* tmp = run;
				for (int j = 0; j < 26; j++) {
					run = tmp->children[j];
					if (query(word + i + 1, run))//返回false不执行下面的执行上面的循环
						return true;//
				}
			}
			else break;
		}
		return run && run->isKey;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main(){
	 WordDictionary wordDictionary;
	 wordDictionary.addWord("a");
	 wordDictionary.search("a");
	 cout<<wordDictionary.search("aa");
	 cout<< wordDictionary.search(".a");
}
