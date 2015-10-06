#include <iostream>
#include <vector>
using namespace std;
class Solution {
	class Trie{
	public:
		Trie *children[26]; // pointers to its substrings starting with 'a' to 'z'
		bool leaf; // if the node is a leaf, or if there is a word stopping at here
		int idx; // if it is a leaf, the string index of the array words
		Trie()
		{
			this->leaf = false;
			this->idx = 0;
			fill_n(this->children, 26, nullptr);
		}
	};

public:
	void insertWords(Trie *root, vector<string>& words, int idx)
	{
		int pos = 0, len = words[idx].size();
		while (pos < len)
		{
			if (nullptr == root->children[words[idx][pos] - 'a']) root->children[words[idx][pos] - 'a'] = new Trie();
			root = root->children[words[idx][pos++] - 'a'];
		}
		root->leaf = true;
		root->idx = idx;
	}

	Trie *buildTrie(vector<string>& words)
	{
		Trie *root = new Trie();
		int i;
		for (i = 0; i < words.size(); i++) insertWords(root, words, i);
		return root;
	}
	void dfs(vector<vector<char> >board, vector<vector<bool> >visited, int i, int j,  int row, int column,Trie* root,vector<string>words,vector<string> &result){
		    if (visited[i][j] == 1)return;
			if (root->children[board[i][j] - 'a'] == nullptr)return;
			else{
				if (root->children[board[i][j] - 'a']->leaf){
					result.push_back(words[root->children[board[i][j] - 'a']->idx]);
					root->children[board[i][j] - 'a']->leaf = false;
				}
				visited[i][j] = 1;
				if (j + 1 < column){

					dfs(board, visited, i, j + 1, row, column, root->children[board[i][j] - 'a'],words,result);//横着走

				}

				if (i + 1 < row){


					dfs(board, visited, i+1, j , row, column, root->children[board[i][j] - 'a'], words, result);//竖着走

				}
				if (j> 0){

					dfs(board, visited, i, j - 1, row, column, root->children[board[i][j] - 'a'], words, result);//竖着走

				}

				if (i >0){

					dfs(board, visited, i - 1, j,  row, column, root->children[board[i][j] - 'a'], words, result);

				}
				visited[i][j] = 0;
			}






	}
	vector<string> findWord(vector<vector<char> >& board, Trie* root, int row, int column,vector<string> words) {
		bool isExit = false;
		vector<string> result;
		int wordCount = words.size();
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column&&wordCount>result.size(); j++){
				vector<vector<bool> >visited(row, vector<bool>(column, 0));

				dfs(board, visited, i, j, row, column, root, words, result);

				}

		}
		//return isExit;
	return	result;
	}
	vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
		int row = board.size();
		int column = 0;
		vector<string> result;
		if (row <= 0)return result;

		column = board[0].size();
		Trie *root = buildTrie(words);
	//	for (int i = 0; i < words.size(); i++){
		//	bool isExit = false;
			//isExit=findWord(board, words[i], row, column);
			//if (isExit == true){
				//result.push_back(words[i]);
			//}
		//}
		result = findWord(board, root, row, column,words);
		return result;
	}
};





int main()
{
	Solution s;
	/*string str[4] = { "oath", "pea", "eat", "rain" };
	vector<string> words(str, str + 4);
	vector<vector<char> >board;
	char arr1[4] = { 'o', 'a', 'a', 'n' };
	vector<char> vec1(arr1, arr1 + 4);
	board.push_back(vec1);
	char arr2[4] = { 'e', 't', 'a', 'e' };
	vector<char> vec2(arr2, arr2 + 4);
	board.push_back(vec2);
	char arr3[4] = { 'i', 'h', 'k', 'r' };
	vector<char> vec3(arr3, arr3 + 4);
	board.push_back(vec3);
	char arr4[4] = { 'i', 'f', 'l', 'v' };
	vector<char> vec4(arr4, arr4 + 4);
	board.push_back(vec4);*/
	string str[3] = {
		"aaaaaaaaaaaa", "aaaaaaaaaaaaa", "aaaaaaaaaaab" };
	vector<string> words(str, str + 3);
	vector<vector<char> >board;
	char arr1[4] = { 'a', 'a', 'a', 'a' };
	vector<char> vec1(arr1, arr1 + 4);
	board.push_back(vec1);
	board.push_back(vec1);
	board.push_back(vec1);
	/*
	vector<string> words;
	vector<vector<char> >board;
	char a = 'a';
	vector<char> vec1;
	vec1.push_back(a);
	board.push_back(vec1);*/
	vector<string> result = s.findWords(board, words);

	return 0;
}
