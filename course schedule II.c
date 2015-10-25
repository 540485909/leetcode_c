class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> vec;
		if (numCourses <= 0){
			return vec;
		}
		vector<set<int> > Graph(numCourses);
		for (int i = 0; i < prerequisites.size(); ++i){
			Graph[prerequisites[i].second].insert(prerequisites[i].first);
		}
		vector<int> inDegree(numCourses);
		for (int i = 0; i < Graph.size(); ++i){
			for (auto it = Graph[i].begin(); it != Graph[i].end();++it){
				inDegree[*it]++;
			}
		}
		queue<int> q1;
		for (int i = 0; i < inDegree.size(); ++i){
			if (!inDegree[i]){
				q1.push(i);
			}
		}
	
		while (!q1.empty()){
			int value = q1.front();
			vec.push_back(value);
			q1.pop();
			for (auto it = Graph[value].begin(); it != Graph[value].end(); ++it){
				if (!--inDegree[*it]){
					q1.push(*it);
				}
			}
		}
		for (int i = 0; i < numCourses; ++i){
			if (inDegree[i]){
				vec.clear();
				return vec;
			}
		}
		return vec;
	}
};
