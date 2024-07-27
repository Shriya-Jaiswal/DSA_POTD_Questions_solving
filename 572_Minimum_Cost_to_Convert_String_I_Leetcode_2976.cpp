#include<iostream>
#include<vector>
#include<limits.h>

#include<queue>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Atlassian ✯  

// // ▶️ Approach-1 (Using Simple Floyd Warshall Algorithm)
// // ⏲️ Time Complexity : O(n)  -> Because other for loops run only for constant time 26*26*26
// // 🛢️ Space Complexity : O(1) -> We take distances matrix of 26*26 which is constant

// void FloydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost) {

//         for(int i = 0; i < original.size(); i++) {
//             int s = original[i] - 'a';
//             int t = changed[i] - 'a';

//             adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
//         }

//         //Apply Floyd Warshall
//         for (int k = 0; k < 26; ++k) {
//             for (int i = 0; i < 26; ++i) {
//                 for (int j = 0; j < 26; ++j) {
//                     adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]); 
//                 }
//             }
//         }
// }

// long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//     vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));
//     FloydWarshall(adjMatrix, original, changed, cost); //update adjMatrix with shortest path using Floyd Warshall
//     long long ans = 0;
//     for(int i = 0; i < source.length(); i++) {
//         if(source[i] == target[i]) {
//             continue;
//         }
//         if(adjMatrix[source[i] -'a'][target[i] - 'a'] == INT_MAX) {
//             return -1;
//         }
//         ans += adjMatrix[source[i] -'a'][target[i] - 'a'];
//     }
//     return ans;
// }


// ▶️ Approach-2 (Using Simple Dijkstra's Algorithm)
// ⏲️ Time Complexity : n * (time complexity of Dijkstra) = O(n * (V+E)logV) , where V = number of vertices and E = number of edges
// 🛢️ Space Complexity : O(V+E) -> We create a graph, where V = number of vertices and E = number of edges

void dijkstra(char &source, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &costMatrix) {

    //min-heap
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    pq.push({0, source});

    while(!pq.empty()) {
        int d        = pq.top().first;
        char adjNode = pq.top().second;
        pq.pop();

        for(auto &it : adj[adjNode]) {
            char adjNode = it.first;
            int cost      = it.second;

            if(costMatrix[source - 'a'][adjNode - 'a'] > d + cost) {
                costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
                pq.push({d + cost, adjNode});
            }
        }

    }
    return;
}
//V = # of vertices
//E = # of edges
//O(n * (V+E)log(V))
long long minimumCost(string source, string target, vector<char>& original, vector<char>&changed, vector<int>& cost) {
    unordered_map<char, vector<pair<char, int>>> adj;

    for(int i = 0; i < original.size(); i++) {
        adj[original[i]].push_back({changed[i], cost[i]});
    }

    vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));

    //Populate the costMatrix using Dijkstra's Algorithm
    for(int i = 0; i < source.length(); i++) { //n
        char ch = source[i];
        dijkstra(ch, adj, costMatrix);
    }

    long long ans = 0;

    for(int i = 0; i < source.length(); i++) {
        if(source[i] == target[i]) {
            continue;
        }

        if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
            return -1;
        }

        ans += costMatrix[source[i] - 'a'][target[i] - 'a'];

    }

    return ans;
}

int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};

    long long ans = minimumCost(source,target,original,changed,cost);
    cout << "ans is : " << ans << endl;
    return 0;
}
