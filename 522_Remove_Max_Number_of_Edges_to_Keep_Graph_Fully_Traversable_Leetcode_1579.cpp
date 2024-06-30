#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Google ✯  

// // ▶️ Using DSU
// // ⏲️ Time Complexity : O(m log m) - sorting edges
// //      O(m * α(n)) union-find operations takes O(α(n)) time.The loop over all edges takes O(m) time, with each find and union operation inside the loop taking O(α(n)) time.
// // 🛢️ Space Complexity : O(n)


class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;

    public : 
        
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            components = n;
            for(int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }
    
        bool isSingle() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
    auto lambda = [&](vector<int>& v1, vector<int>& v2) {
        return v1[0] > v2[0];
    };
        
    sort(begin(edges), end(edges), lambda);
    DSU Alice(n);
    DSU Bob(n);
        
    int addedEdge = 0;
        
    for (auto &edge: edges) { // For each edge -
        int type = edge[0];
        int u = edge[1];
        int v = edge[2];
            
        if(type == 3) {
            bool add = false;
                
            if(Alice.find(u) != Alice.find(v)) {
                Alice.Union(u, v);
                add = true;
            }
                
            if(Bob.find(u) != Bob.find(v)) {
                Bob.Union(u, v);
                add = true;
            }
                
            if(add)
                addedEdge++;
                
        } else if(type == 2) {
            if(Bob.find(u) != Bob.find(v)) {
                Bob.Union(u, v);
                addedEdge++;
            }
        } else {
            if(Alice.find(u) != Alice.find(v)) {
                Alice.Union(u, v);
                addedEdge++;
            }
        }
    }
        
        
    if(Alice.isSingle() && Bob.isSingle()) {
        return edges.size() - addedEdge;
    }
        
    return -1;
}
};


int main()
{
    // int n = 4;
    // vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    // int ans = maxNumEdgesToRemove(n,edges);
    // cout << "ans is : " << ans << endl;
    return 0;
}
