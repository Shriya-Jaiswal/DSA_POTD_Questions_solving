#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<int> > adjList;

        void addEdge(int u, int v, bool direction) {
            // 👉 direction = 1 -> undirected graph
            // 👉 direction => 0 -> directed graph;
            adjList[u].push_back(v);
            if(direction == 1) {
                adjList[v].push_back(u);
            }
        }
    void printAdjacencyList(){
        for(auto node : adjList){
            cout << node.first << "-> ";
            for(auto neighbour : node.second){
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }


int nodeLevel(int V, vector<int> adj[], int X) 
{
	queue<pair<int,int>> q;
    vector<int> visited(V,0);
    q.push({0,0});
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        if(node == X){
            return level;
        }
        for(auto it : adj[node]){
            if(!visited[it]){
                q.push({it,level+1});
                visited[it] = 1;
            }
        }
    }
    return -1;
}
};

// Expected Time Complexity: O(V)
// Expected Auxiliary Space: O(V)

int main()
{
    // Graph g;

    // // 👉 n -> number of nodes in graph
    // int n = 7;

    // g.addEdge(0,1,1);
    // g.addEdge(1,3,1);
    // g.addEdge(1,4,1);
    // g.addEdge(0,2,1);
    // g.addEdge(2,5,1);
    // g.printAdjacencyList();
    // cout << endl;

    // int x = 4;
    // vector<int> ans;
    // int ans = nodeLevel();
    return 0;
}
