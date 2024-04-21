#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Google ✯   Microsoft ✯ Adobe, Morgan Stanley, Samsung

// // ▶️ Using DFS : ⏲️ O(m+n)

// bool check(unordered_map<int, vector<int>>& mp, int node, int dest, vector<bool>& visited) {
//     if(node == dest)
//         return true;
        
//     if(visited[node])
//         return false;
        
//     visited[node] = true;
//     for(auto &it : mp[node]) {
//         if(check(mp, it, dest, visited))
//             return true;
//     }
//     return false;
// }
    
// bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//     if(source == destination)
//         return true;
        
//     unordered_map<int, vector<int>> mp;
//     for(vector<int> &vec : edges) {
//         int u = vec[0];
//         int v = vec[1];
//         mp[u].push_back(v);
//         mp[v].push_back(u);
//     }   
//     vector<bool> visited(n, false);
//     return check(mp, source, destination, visited);
// }


// ▶️ Using BFS : ⏲️ O(m+n)

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> mp;
        
    for(vector<int> &vec : edges) {
        int u = vec[0];
        int v = vec[1];
            
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
        
    vector<bool> visited(n, false);
        
    queue<int> que;
    que.push(source);
    visited[source] = true;
        
    while(!que.empty()) {
        int node = que.front();
        que.pop();
        if(node == destination)
            return true;

        for(auto &it : mp[node]) {
            if(!visited[it]) {
                visited[it] = true;
                que.push(it);
            }
        }
    }
        
    return false;
}

int main(){
    int  n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;
    bool ans = validPath(n,edges,source,destination);
    cout << "ans is : " << ans << endl;
    return 0;
}
