struct node{
	set<int> neighbour;
	bool is_leaf()const{ return neighbour.size() == 1; }
	bool is_delete;
	node():is_delete(false){
		
	}
};
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int > result;
		
		if (n <= 0) return result;
		if (n == 1) {
			result.push_back(0);
			return result;
		}
		if (n == 2){
			result.push_back(0);
			result.push_back(1);
			return result;
		}

		vector<node> Graph(n);
		for (int i = 0; i < edges.size(); ++i){
			Graph[edges[i].first].neighbour.insert(edges[i].second);
			Graph[edges[i].second].neighbour.insert(edges[i].first);
		}
	
		queue<int> leaf;
		for (int i = 0; i < n; ++i){
			if (Graph[i].neighbour.size() == 1){
				leaf.push(i);
			}
		}
		
			
		while (1){
			while (!leaf.empty()){
				int cur_value = leaf.front();
				leaf.pop();
				int parent = *Graph[cur_value].neighbour.begin();
				Graph[cur_value].neighbour.erase(parent);
				Graph[parent].neighbour.erase(cur_value);
				Graph[cur_value].is_delete = true;
			}
			for (int i = 0; i < n; ++i){
				if (Graph[i].neighbour.size() == 1){
					leaf.push(i);
				}
			}
			int count_delete = 0;
			for (int i = 0; i < n; ++i){
				if (Graph[i].is_delete == false){
					count_delete++;
				}
			}
			if (count_delete == 1 || count_delete == 2){
				break;
			}
			
		}
		for (int i = 0; i < n; ++i){
			if (Graph[i].is_delete == false){
				result.push_back(i);
			}
		}
			
		return result;
		
	}
};