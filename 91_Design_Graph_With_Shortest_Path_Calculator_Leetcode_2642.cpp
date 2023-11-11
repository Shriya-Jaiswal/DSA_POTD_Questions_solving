#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<queue>
using namespace std;


// // ➡️ Approach-1 (Using Dijkstra's Algorithm)
// // ⏲️ Time Complexity : Dijkatra's called M times - O(M * ElogV)
// class Graph {
// public:
//     unordered_map<int, vector<pair<int, int>>> adj;
//     int N;
//     vector<int> result;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
//     Graph(int n, vector<vector<int>>& edges) {
//         N = n;
//         for(auto &vec : edges) {
//             int u    = vec[0];
//             int v    = vec[1];
//             int cost = vec[2];
            
//             adj[u].push_back({v, cost});
//         }
//     }
    
//     void addEdge(vector<int> edge) {
//         int u    = edge[0];
//         int v    = edge[1];
//         int cost = edge[2];
//         adj[u].push_back({v, cost});
//     }
    
//     int shortestPath(int node1, int node2) {
// 		vector<int> result(N, INT_MAX);
// 		result[node1] = 0;
// 		pq.push({0, node1});
// 		while(!pq.empty()) {

// 		    int d  = pq.top().first;
// 		    int node = pq.top().second;
// 		    pq.pop();

// 		    for(auto &vec : adj[node]) {

// 			int adjNode = vec.first;
// 			int dist    = vec.second;

// 			if(d + dist < result[adjNode]) {
// 			    result[adjNode] = d + dist;
// 			    pq.push({d+dist, adjNode});
// 			}
// 		    }
// 		}
//         return result[node2] == INT_MAX ? -1 : result[node2];
//     }
// };




// ➡️ Approach-1 (Using Floyd Warshal Algorithm)
// ⏲️ Time Complexity : O(N^3) - Making adj Matrix
class Graph {
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));
        
        for(auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u][v] = cost;
        }
        
        for(int i = 0; i<n; i++) {
            adj[i][i] = 0;
        }
        
        //Floyd Warshal
        for(int k = 0; k<n; k++) {
            
            for(int i = 0; i<N; i++) {
                for(int j = 0; j<N; j++) {
                    
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        
                }
            }
            
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];
        //check with 2 new vertices - u and v
        
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {

                adj[i][j] = min(adj[i][j], adj[i][u] + cost + adj[v][j]);

            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
    }
};


int main()
{
    
    return 0;
}
