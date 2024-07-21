#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Apple ✯   Google ✯  

// // ▶️ Approach-1 (Topological Sorting using DFS)
// // ⏲️ Time Complexity : O(k*^2 + n)
// // 🛢️ Space Complexity : O(k*^2 + n)

// vector<int> topoSort(vector<vector<int>>& edges, int n) {
//     unordered_map<int, vector<int>> adj;
//     stack<int> st;
//     vector<int> order;
//     //0 : not visited;
//     //1 : visiting (currently in stack via some other DFS)
//     //2 : visited
//     vector<int> visited(n + 1, 0);
//     bool hasCycle = false;

//     for (vector<int>& edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         adj[u].push_back(v);
//     }

//     for (int i = 1; i <= n; i++) {
//         if (visited[i] == 0) {
//             dfs(i, adj, visited, st, hasCycle);
//             if (hasCycle) 
//                 return {}; //no ordering possible
//         }
//     }
        
//     while(!st.empty()) {
//         order.push_back(st.top());
//         st.pop();
//     }
//     return order;
// }

// void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited,
//              stack<int>& st, bool& hasCycle) {
        
//     visited[node] = 1;  // Mark node as visiting
//     //First, visit node's children
//     for (int& nbr : adj[node]) {
//         if (visited[nbr] == 0) {
//             dfs(nbr, adj, visited, st, hasCycle);
//         } else if (visited[nbr] == 1) {
//             // Cycle detected
//             hasCycle = true;
//             return;
//         }
//     }

//     visited[node] = 2; //visited
//     st.push(node); //Now node can be added
// }

// vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
//                                     vector<vector<int>>& colConditions) {        
//     vector<int> orderRows    = topoSort(rowConditions, k);
//     vector<int> orderColumns = topoSort(colConditions, k);

//     // We might have found cycle. That's why topo order is empty
//     if (orderRows.empty() or orderColumns.empty())
//         return {};

//     vector<vector<int>> matrix(k, vector<int>(k, 0));
//     for (int i = 0; i < k; i++) {
//         for (int j = 0; j < k; j++) {
//             if (orderRows[i] == orderColumns[j]) {
//                 matrix[i][j] = orderRows[i];
//             }
//         }
//     }
//     return matrix;
// }


// ▶️ Approach-2 (Topological Sorting using BFS)
// ⏲️ Time Complexity : O(k*^2 + n)
// 🛢️ Space Complexity : O(k*^2 + n)

vector<int> topoSort(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    vector<int> order;
    for (vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
        
    queue<int> que;
    int count = 0;
    // Push all integers with in-degree 0 in the queue.
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
            count++;
        }
    }
 
    while(!que.empty()) {
	    int u = que.front();
	    order.push_back(u);
	    que.pop();
	        
	    for(int &v : adj[u]) {
	        indegree[v]--;
	            
	        if(indegree[v] == 0) {
	            que.push(v);
                count++;
	        }
	            
	    }
	}

    if (count != n) 
        return {}; //cycle

    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> orderRows    = topoSort(rowConditions, k);
    vector<int> orderColumns = topoSort(colConditions, k);

    // We might have found cycle. That's why topo order is empty
    if (orderRows.empty() or orderColumns.empty())
        return {};

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (orderRows[i] == orderColumns[j]) {
                matrix[i][j] = orderRows[i];
            }
        }
    }
    return matrix;
}

int main()
{
    int  k = 3;
    vector<vector<int>> rowConditions = {{1,2},{3,2}};
    vector<vector<int>> colConditions = {{2,1},{3,2}};
    vector<vector<int>> ans = buildMatrix(k,rowConditions,colConditions);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
