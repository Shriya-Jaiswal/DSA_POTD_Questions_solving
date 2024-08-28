#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  DoorDash ✯   Twitter ✯  

// ▶️ Approach-1 (DFS)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(1) //I am not considering the space taken by System Recursion stack

// 👉 DFS
bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
        return true;
    }
        
    if(grid2[i][j] != 1) { // 👉 we only need land
        return true;
    }

    grid2[i][j] = -1; // 👉 mark visited

    bool result = (grid1[i][j] == 1); // 👉 grid1[i][j] must have 1

    result = result & checkSubIsland(grid1, grid2, i+1, j); // 👉 Down
    result = result & checkSubIsland(grid1, grid2, i-1, j); // 👉 Up
    result = result & checkSubIsland(grid1, grid2, i, j+1);  // 👉 Right
    result = result & checkSubIsland(grid1, grid2, i, j-1); // 👉 Left

    return result;

}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    // 👉 DFS
    int subIslands = 0;
    int m = grid2.size(); // 👉 rows
    int n = grid2[0].size(); // 👉 cols

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { //Found an island
                subIslands++;
            }
        }
    }

    return subIslands;
}

// // ▶️ Approach-2 (BFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n) //Queue

// vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left

// // 👉 BFS
//    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
//     int m = grid1.size();
//     int n = grid1[0].size();

//     bool result = true;

//     queue<pair<int, int>> que; //{i, j} // 👉 BFS me we use queue
//     que.push({i, j});
//     grid2[i][j] = -1; // 👉 mark visited

//     while(!que.empty()) {
//         auto [x, y] = que.front();
//         que.pop();

//         if(grid1[x][y] != 1) { // 👉 grid1 must have 1 at that same co-ordinate
//             result = false;
//         }

//         for(vector<int>& dir : directions) {
//             int newX = x + dir[0];
//             int newY = y + dir[1];

//             if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
//                 grid2[newX][newY] = -1; // 👉 mark visited
//                 que.push({newX, newY});
//             }
//         }
//     }
//     return result;
// }

// int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//     //DFS
//     int subIslands = 0;
//     int m = grid2.size(); //rows
//     int n = grid2[0].size(); //cols

//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { //Found an island
//                 subIslands++;
//             }
//         }
//     }

//     return subIslands;
// }

int main()
{
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    int ans = countSubIslands(grid1,grid2);
    cout << "ans is : " << ans << endl;
    return 0;
}
