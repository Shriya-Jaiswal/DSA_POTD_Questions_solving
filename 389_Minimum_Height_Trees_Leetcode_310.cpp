#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

// ▶️  Amazon ✯   Snapchat ✯  GOOGLE


// ▶️ Using Topological Sorting
// ⏲️ Time Complexity : O(V+E)
// 🛢️ Space Complexity : O(V+E)

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1)
        return {0};
        
    vector<int> result;
    vector<int> indegree(n);
    map<int, vector<int>> adj;
        
    for(vector<int> vec:edges) {
        int u = vec[0];
        int v = vec[1];
        indegree[u]++;
        indegree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        
    queue<int> que;
    for(int i = 0; i<n; i++) {
        if(indegree[i] == 1) //adding all leafs node so that we can remove them later
            que.push(i);
    }
        
    while(n > 2) {
        int size = que.size();
        n -= size; //removing nodes with indegreee 1
            
        while(size--) {
            int u = que.front();
            que.pop();
            for(int v:adj[u]) {
                indegree[v]--;
                if(indegree[v] == 1)
                    que.push(v);
            }
        }
    }
        
    while(!que.empty()) {
        result.push_back(que.front());
        que.pop();
    }
    return result;
}


int main()
{
    int n = 4;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};

    vector<int> ans = findMinHeightTrees(n,edges);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
