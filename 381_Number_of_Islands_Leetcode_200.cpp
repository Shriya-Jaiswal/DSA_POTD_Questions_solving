#include<iostream>
#include<queue>
using namespace std;


// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Facebook ✯   Bloomberg ✯   Google ✯   LinkedIn   Apple   Oracle   Uber   Salesforce   ByteDance   tiktok   DoorDash   Docusign   SAP   Karat   Adobe   Qualtrics   Goldman Sachs   Paypal   Nvidia   VMware   ServiceNow   Shopee   eBay   Snapchat   Dropbox   Square   Twitch   Cruise Automation  

// // ▶️ Approach-1 (DFS)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n)

// vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     void dfs(vector<vector<char>>& grid, int i, int j) {
//         if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
//             return;
        
//         /*
//           You can also use lambda function for checking if next cell is valid or not
//           auto isSafe = [&](int &i, int &j) {
//             if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
//                 return false;
//             return true;
//           }; 
//         */
        
//         grid[i][j] = '$';
//         for(pair<int, int> &p : dir) {
//             int i_ = i + p.first;
//             int j_ = j + p.second;
//             dfs(grid, i_, j_);
//         }
// }

// int numIslands(vector<vector<char>>& grid) {
//     if(grid.size() == 0)
//         return 0;
        
//     int m = grid.size();
//     int n = grid[0].size();
//     int count = 0;
//     for(int i = 0; i<m; i++) {
//         for(int j = 0; j<n; j++) {
//             if(grid[i][j] == '1') {
//                 dfs(grid, i, j);
//                 count++;
//             }
//         }
//     }  
//     return count;
// }


// ▶️ Approach-2 (BFS)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(m*n)

vector<pair<int, int>> dir{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
void bfs(vector<vector<char>>& grid, int i, int j, queue<pair<int, int>>& que) {
    que.push({i, j});
    grid[i][j] = '$';
        
    //lambda function (You can also add if check instead of lambda)
    auto isSafe = [&](int &i, int &j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return false;
        return true;
    };
        
    while(!que.empty()) {
        auto curr = que.front();
        que.pop();
            
        for(auto &p : dir) {
            int i_ = curr.first  + p.first;
            int j_ = curr.second + p.second;
                
            if(isSafe(i_, j_)) {
                que.push({i_, j_});
                grid[i_][j_] = '$';
            }
        }
    }
}


int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0)
        return 0;
        
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    queue<pair<int, int>> que;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] == '1') {
                bfs(grid, i, j, que);
                count++;
            }
        }
    }
        
    return count;
}



int main()
{
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};

    int ans = numIslands(grid);
    cout << "ans is : " << ans  << endl;
    return 0;
}
