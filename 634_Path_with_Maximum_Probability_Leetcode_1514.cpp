#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Google ✯  

// ▶️ Using Dijkstra's Algorithm
// ⏲️ Time Complexity : O(E*log(V))
// 🛢️ Space Complexity : O(V + E)

typedef pair<double, int> P;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    unordered_map<int, vector<pair<int, double>>> adj;
    vector<double> result(n, 0);
        
    for(int i=0;i<edges.size();i++)
    {
        int u       = edges[i][0];
        int v       = edges[i][1];
        double prob = succProb[i];
        adj[u].push_back({v, prob});
        adj[v].push_back({u, prob});
    }

    priority_queue<P> pq; // 👉 max heap because we need maximum probability

	result[start] = 1;
	pq.push({1.0, start});

	while(!pq.empty()) {
		int curnode    = pq.top().second;
        double curProb = pq.top().first;
        pq.pop();

        for(auto &child : adj[curnode])
        {
            if(result[child.first] < curProb*child.second) //we want maximum this time
            {
                result[child.first] = curProb*child.second;
                pq.push({result[child.first], child.first});
            }
        }
	}
	return result[end];
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;

    return 0;
}
