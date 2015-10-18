class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses < 0)return true;
		vector<set<int> > graphic(numCourses);
		for (int j = 0; j < prerequisites.size(); ++j){
           graphic[prerequisites[j].second].insert(prerequisites[j].first);
		}
		vector<int> degree(numCourses);/*just as shortest path dp[n] we do not need to delete the edge just use a value to record*/
		for (int i = 0; i < graphic.size(); ++i){
			for (auto it = graphic[i].begin(); it != graphic[i].end(); ++it){
				degree[*it]++;
			}
		}
		queue<int> q1;
		for (int i = 0; i < degree.size(); ++i){
			if (degree[i] == 0){
				q1.push(i);
			}
		}
		while (!q1.empty()){
			int value = q1.front();
			q1.pop();
			for (auto it = graphic[value].begin(); it != graphic[value].end(); ++it){
				if (!--degree[*it]){
					q1.push(*it);
				}

			}
		}
		for (int i = 0; i < numCourses; ++i){
			if (degree[i]){
				return false;
			}
		}
		return true;
	}
};
