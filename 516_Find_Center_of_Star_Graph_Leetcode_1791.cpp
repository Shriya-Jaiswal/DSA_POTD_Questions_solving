#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Microsoft ✯  

// // ▶️ Approach-1 (Using map)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int findCenter(vector<vector<int>>& edges) {
//     int n = edges.size();
//     unordered_map<int, int> degree;

//     for(auto &vec : edges) {
//         int u = vec[0];
//         int v = vec[1];

//         degree[u]++;
//         degree[v]++;
//     }

//     for(auto &it : degree) {
//         int node = it.first;
//         int deg  = it.second;

//         if(deg == n)
//             return node;
//     }

//     return -1;
// }


// ▶️ Approach-2 (Constant time)
// ⏲️ Time Complexity : O(1)
// 🛢️ Space Complexity : O(1)

int findCenter(vector<vector<int>>& edges) {
    vector<int> first  = edges[0]; //{a, b}
    vector<int> second = edges[1]; //{c, a}

    if(first[0] == second[0] || first[0] == second[1]) {
        return first[0];
    }
    return first[1];
}

int main()
{
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    int ans = findCenter(edges);
    cout << "ans is : " << ans << endl;
    return 0;
}
