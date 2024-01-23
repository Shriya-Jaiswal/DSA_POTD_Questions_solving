#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by : Google

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
{
    vector<int> adj[n];
	for (auto it : prerequisites) {
		adj[it[1]].push_back(it[0]);
	}
	vector<int> indegree(n , 0);
	for (int i = 0; i < n; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		// 👉 node is in your topo sort
		// 👉 so please remove it from the indegree

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) q.push(it);
		}
	}
	if (topo.size() == n) return topo;
	return {};
}

// ⏲️ Expected Time Complexity: O(n+m).
// 🛢️ Expected Auxiliary Space: O(n+m).

int main()
{
    int n = 2; 
    int m = 1;
    vector<vector<int>> prerequisites  = {{1, 0}};
    vector<int> ans = findOrder(n,m,prerequisites);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
