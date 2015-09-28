#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      tr1::unordered_map<int,UndirectedGraphNode*> track;
      return cloneGraph(node,track);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node,tr1::unordered_map<int ,UndirectedGraphNode*> &track) {
        if(node==NULL)return node;
        if(track.count(node->label))return track[node->label];
        UndirectedGraphNode* new_node=new UndirectedGraphNode(node->label);
        track[node->label]=new_node;
        for(int i=0;i<node->neighbors.size();i++)
        {
            new_node->neighbors.push_back(cloneGraph(node->neighbors[i],track));
        }
        return new_node;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
