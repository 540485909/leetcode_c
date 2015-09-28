#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

const int MAX_V=10000;
using namespace std;
ifstream fcin("test.txt");
struct vertex{
    int p;
    int q;
    vector<vertex*> edge;
};
vertex G[MAX_V];
int N;
bool cmp(vertex *a,vertex *b){

  return a->q>b->q;
}
int dfs(vertex *v){



}
void findMin(int root){
   if(root>=N)return ;
   sort(G[root].edge.begin(),G[root].edge.end(),cmp);
   for(int i=0;i<G[root].edge.size();i++){
    dfs(G[root].edge[i]);
   }
}

int main()
{
    int n;
    fcin>>n;
    N=n;
    for(int i=1;i<=n;i++){
        int p,q;
        fcin>>p>>q;
        G[i].p=p;
        G[i].q=q;

    }
    for(int i=1;i<n;i++){
        int s,t;
        fcin>>s>>t;
        G[s].edge.push_back(&G[t]);
    }

    return 0;
}
