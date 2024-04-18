#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Google ✯   Amazon ✯  

// // ▶️ Approach-1 (DFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(1) Auxiliary Space

// int m;
// int n;
// int peri;
    
// void dfs(vector<vector<int>>& grid, int i, int j) {
//     if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
//         peri++;
//         return;
//     }   
//     if(grid[i][j] == -1) {
//         return;
//     }    
//     grid[i][j] = -1; // 👉 mark visited   
//     dfs(grid, i+1, j);
//     dfs(grid, i-1, j);
//     dfs(grid, i, j+1);
//     dfs(grid, i, j-1);    
// }
    
// int islandPerimeter(vector<vector<int>>& grid) {
//     m    = grid.size();
//     n    = grid[0].size();
//     peri = 0;
        
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {          
//             if(grid[i][j] == 1) {
//                 dfs(grid, i, j);
//                 return peri;
//             }          
//         }
//     }  
//     return -1;
// }



// // ▶️ Approach-2 (BFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n)

// int m;
// int n;
// vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// int bfs(vector<vector<int>>& grid, int i, int j) {
//     int perim = 0;
        
//     queue<pair<int, int>> que;
//     que.push({i, j});
//     grid[i][j] = -1;
        
//     while(!que.empty()) {
//         auto it = que.front();
//         que.pop();
            
//         //it.first = i
//         //it.second = j
            
//         for(auto &dir : directions) {
//             int i_ = it.first + dir[0];
//             int j_ = it.second + dir[1];
//             if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
//                 perim++;
//             else if(grid[i_][j_] == -1) {
//                 continue;
//             } else {
//                 que.push({i_, j_});
//                 grid[i_][j_] = -1;
//             }
//         }    
//     }
//     return perim;
// }
    
// int islandPerimeter(vector<vector<int>>& grid) {
//     m    = grid.size();
//     n    = grid[0].size();
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {      
//             if(grid[i][j] == 1) {
//                 return bfs(grid, i, j);
//             }        
//         }
//     }     
//     return -1;
// }


// ▶️ Approach-3 (Iterative)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(1)

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();   
    int perimeter = 0;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] == 0)
                continue;
                
            if(i-1 < 0 || grid[i-1][j] == 0) //up
                perimeter++;
                
            if(i+1 >= m || grid[i+1][j] == 0) //down
                perimeter++;
                
            if(j-1 < 0 || grid[i][j-1] == 0) //left
                perimeter++;
                
            if(j+1 >= n || grid[i][j+1] == 0) //right
                perimeter++;
                
        }
    }
        
    return perimeter;
}

int main()
{
    vector<vector<int>>  grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ans = islandPerimeter(grid);
    cout << "ans is : " << ans << endl;
    return 0;
}
