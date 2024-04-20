#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Citrix ✯   Amazon, Microsoft

// // ▶️ Approach-1 (Using DFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(1) AUxiliary space and O(m*n) system stack space because of recursion

// int m;
// int n;
// vector<vector<int>> result;
// vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// void dfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
//     land[i][j] = 0;
//     r2 = max(r2, i);
//     c2 = max(c2, j);
//     for(auto &dir : directions) {
//         int i_ = i + dir[0];
//         int j_ = j + dir[1];
            
//         if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
//             dfs(land, i_, j_, r2, c2);
//         }
//     }
// }
    
// vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//     m = land.size();
//     n = land[0].size();
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             if(land[i][j] == 1) {
//                 int r1 = i;
//                 int c1 = j;
//                 int r2 = -1;
//                 int c2 = -1;    
//                 dfs(land, i, j, r2, c2);
//                 result.push_back({r1, c1, r2, c2});
//             } 
//         }
//     } 
//     return result;
// }



// // ▶️ Approach-2 (Using BFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n)

// int m;
// int n;
// vector<vector<int>> result;
// vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
// void bfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
//     queue<pair<int, int>> que;
//     que.push({i, j});    
//     while(!que.empty()) {       
//         pair<int, int> p = que.front();
//         que.pop();     
//         r2 = max(r2, p.first);
//         c2 = max(c2, p.second);
//         for(auto &dir : directions) {
//             int i_ = p.first  + dir[0];
//             int j_ = p.second + dir[1];
                
//             if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
//                 land[i_][j_] = 0; //visited
//                 que.push({i_, j_});
//             }
//         }
            
//     }        
// }
    
// vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//     m = land.size();
//     n = land[0].size();   
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
                
//             if(land[i][j] == 1) {
//                 int r1 = i;
//                 int c1 = j;
//                 int r2 = -1;
//                 int c2 = -1;
                    
//                 bfs(land, i, j, r2, c2);
//                 result.push_back({r1, c1, r2, c2});
//             }
//         }
//     } 
//     return result;
// }



// ▶️ Approach-3 (Brute Force Greedy)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ space Complexity : O(1)

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();
    vector<vector<int>> result;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(land[i][j] == 0) continue;
            //find the right most column of the current group
            int c1 = j;
            while(c1 < n && land[i][c1] == 1) {
                c1++;
            }
                
            //find the bottom most row of the current group
            int r1 = i;
            while(r1 < m && land[r1][j] == 1) {
                r1++;
            }
                
            c1 = c1 == 0 ?  c1 : c1-1;
            r1 = r1 == 0 ?  r1 : r1-1;
                
            result.push_back({i, j, r1, c1});
                
            //mark all the inbetween 1s to 0s
            for(int k = i; k <= r1; k++) {
                for(int l = j; l <= c1; l++) {
                    land[k][l] = 0; //visited
                }
            }
        }
    }
    return result;  
}

int main()
{
    vector<vector<int>> land = {{1,0,0},{0,1,1},{0,1,1}};
    vector<vector<int>> ans = findFarmland(land);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
