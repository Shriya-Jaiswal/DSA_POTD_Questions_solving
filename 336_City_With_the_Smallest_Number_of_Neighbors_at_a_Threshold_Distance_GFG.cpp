#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int dijkstra(int n, vector<pair<int, int>> adj[], int k, int src) {
    priority_queue<int> q;
    q.push(src);

    // 👉 Initializing a vector to store the minimum distance from the source
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.top();
        q.pop();

        for (auto x : adj[node]) {
            int nbr = x.first;
            int wt = x.second;
            if (dist[nbr] > dist[node] + wt) {
                dist[nbr] = dist[node] + wt;
                q.push(nbr);
            }
        }
    }

    // 👉 Counting the number of cities within the distance threshold
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] <= k)
            c++;
    }
    return c;
}

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<pair<int,int>> adj[n];

    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<int> dis(n, 0);

    // 👉 Finding the number of cities within the distance threshold for each city
    for (int i = 0; i < n; i++) {
        dis[i] = dijkstra(n, adj, distanceThreshold, i);
    }

    int ans = INT_MAX;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (ans >= dis[i]) {
            ans = dis[i];
            idx = i;
        }
    }
       return idx;
}

// ⏲️ Expected Time Complexity: O(n2 + length(edges)*nlog(n) )
// 🛢️ Expected Auxiliary Space:  O(n3)

int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3},
                                {1, 2, 1},
                                {1, 3, 4},
                                {2, 3, 1}};
    int distanceThreshold = 4;

    int ans = findCity(n,m,edges,distanceThreshold);
    cout << "ans is :" << ans << endl;
    return 0;
}
