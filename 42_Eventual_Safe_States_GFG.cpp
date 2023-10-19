#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


// ➡️ GFG Medium :   https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> arr[V];
    int indegree[V] = {0}; // 👉 it store indegree
    for(int i=0; i<V; i++){
        // 👉 edge reversal 
        for(auto it : adj[i]){
            arr[it].push_back(i);
            indegree[i]++; // 👉 increase indegree 
        }
    }
    // 👉 jiski indegree 0 thi usse queue me put kr do
    queue<int>q;
    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : arr[node]){
            // 👉 decrease indegree
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    // 👉 when queue is empty then sort the ans 
    sort(ans.begin(), ans.end());
    return ans;
}

// ⏲️ Expected Time Complexity: O(V + E)
// 🛢️ Expected Space Complexity: O(V)

int main()
{
    
    return 0;
}
