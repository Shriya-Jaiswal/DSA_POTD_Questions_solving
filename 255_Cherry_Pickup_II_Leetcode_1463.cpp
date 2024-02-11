#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// ▶️ Ask by :  Flipkart ✯   Amazon ✯   Google ✯  

// // ▶️ Approach-1 (Using Recursion + Memoization)
// // ⏲️ Time Complexity : O(row*col*col * 9) -> 9 is from the double for loop for colDir
// // 🛢️ Space Complexity : O(row * col * col)


// int m, n;
// int t[71][71][71];
// vector<int> colDir{-1, 0, 1};
// bool isSafe(int& i) {
//     return i >= 0 && i < n;
// }
    
// int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
//     if(row >= m)
//         return 0;     
        
//     if(t[row][c1][c2] != -1) {
//         return t[row][c1][c2];
//     }
        
//     int count = grid[row][c1];
//     if(c1 != c2) {
//         count += grid[row][c2];
//     }
        
//     int ans = 0;
//     for(int& x : colDir) {
//         for(int& y : colDir) {        
//             int c1_ = x + c1;
//             int c2_ = y + c2;      
//             if(isSafe(c1_) && isSafe(c2_)) {
//                 ans = max(ans, solve(grid, row+1, c1_, c2_));
//             }
//         }
//     }
//     return t[row][c1][c2] = count+ans;  
// }
    
// int cherryPickup(vector<vector<int>>& grid) {
//     m = grid.size();
//     n = grid[0].size();
//     memset(t, -1, sizeof(t));
//     return solve(grid, 0, 0, n-1);
// }



// // ▶️ Approach-2 (Bottom Up - 3D Array)
// // ⏲️ Time Complexity : O(row*col*col * 9)
// // 🛢️ Space Complexity : O(row * col * col)


// int cherryPickup(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
        
//     int t[71][71][71] = {0};
        
//     //t[row][c1][c2] =  max cherries that can be collected till (row, c1) by robot1 and (row, c2) by robot2
//     //return max in last row 
        
//     //For first row (robot1 is in 0th column) and robot2 is in (n-1)th column
//     t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1]; 
        
//     for (int row = 1; row < m; row++) {
//         for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
//             for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                    
//                 int prev_max = 0;
//                 //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
//                 for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
//                     for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
//                             prev_max = max(prev_max, t[row - 1][column1][column2]);
//                     }
//                 }
                    
//                 if (c1 == c2)
//                     t[row][c1][c2] = prev_max + grid[row][c1];
//                 else
//                     t[row][c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
//             }
//         }
//     }
        
//     int res = 0;
//     //return max in last row 
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             res = max(res, t[m - 1][i][j]);    
//         }
//     }
//     return res;
// }



// ▶️ Approach-3 (Bottom Up - 2D Array) We only need previous row
// ⏲️ Time Complexity : O(row*col*col * 9)
// 🛢️ Space Complexity : O(col * col)


int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> prev(n, vector<int>(n));
    prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
    for (int row = 1; row < m; row++) {
        vector<vector<int>> curr(n, vector<int>(n));
        for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
            for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                int prev_max = 0;
                //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
                for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                    for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                            prev_max = max(prev_max, prev[column1][column2]);
                    }
                }
                if (c1 == c2)
                    curr[c1][c2] = prev_max + grid[row][c1];
                else
                    curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
            }
        }
        prev = curr;
    }
        
    int res = 0;
    //return max in last row 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, prev[i][j]);    
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int ans = cherryPickup(grid);
    cout << "ans is :" << ans<< endl;
    return 0;
}
