#include <iostream>
#include <cstring>
using namespace std;
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		memset(next, NULL, sizeof(next));
		isStop = false;
		appearance = 0;
	}

	TrieNode *next[26];
	bool isStop;
	int appearance;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *p = root, *q;
		int len = word.size();
		int id = 0;
		for (int i = 0; i < len; i++)
		{
			id = word[i] - 'a';
			if (p->next[id] == NULL){
				q = new TrieNode();
				q->appearance = 1;
				p->next[id] = q;//把整个操作看做向链表中添加一个新的节点
				p = p->next[id];//链表向下移动 不需要递归 递归太麻烦
			}
			else{
				p->next[id]->appearance++;
				p = p->next[id];
			}

		}
		p->isStop = true;

	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *p = root;
		int len = word.size();
		int id = 0;
		for (int i = 0; i < len; i++)
		{
			id = word[i] - 'a';
			if (p->next[id] != NULL){
				p = p->next[id];
			}
			else{
				return false;
			}

		}
		if (p->isStop == true){
			return true;
		}
		else{
			return false;
		}
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *p = root;
		int len = prefix.size();
		int id = 0;
		for (int i = 0; i < len; i++)
		{
			id = prefix[i] - 'a';
			if (p->next[id] != NULL){
				p = p->next[id];
			}
			else{
				return false;
			}

		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main()
{
	Trie t;
	t.insert("abc");
	cout << t.search("abc");
	cout << t.search("ab");
	t.insert("ab");

	cout << t.search("ab");
	 t.insert("ab");
	cout << t.search("ab");
	cout << t.search("duan") << endl;
	cout << t.startsWith("duan") << endl;
	return 0;
}
