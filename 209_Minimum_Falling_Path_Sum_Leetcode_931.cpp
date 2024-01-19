#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Google ✯  


// // ➡️ Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(101) ~ O(1) (Excluding stack recursion space)


//  int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
//     if(row == A.size()-1)
//         return A[row][col];
//     if(t[row][col] != -1)
//         return t[row][col];
        
//     int minSum = INT_MAX;
        
//     for(int shift = -1; shift<=1; shift++) {
//         if(col + shift >=0 && col+shift < A[row].size()) {
//             minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
//         }
//     }
        
//     return t[row][col] = minSum;
// }

// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int m = matrix.size(); //row
//     int n = m; //column
//     vector<vector<int>> t(101, vector<int>(101));
//     for(int i = 0; i<101; i++) {
//         for(int j = 0; j<101; j++) {
//             t[i][j] = -1;
//         }
//     }
//     int result = INT_MAX;
//     for(int col = 0; col<n; col++) {
//         result = min(result, MFS(matrix, 0, col, t));
//     }
//     return result;
// }


// // ➡️ Approach-2 (Bottom UP DP) : O(m*n)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity :  O(m*n)


// int MFS(vector<vector<int>>& A) {
//     int m = A.size();
//     vector<vector<int>> t(m, vector<int>(m));
        
//     //initialization
//     for(int col = 0; col<m; col++) {
//         t[0][col] = A[0][col];
//     }
        
//     for(int row = 1; row < m; row++) {
//         for(int col = 0; col < m; col++) {
//             t[row][col] = A[row][col] + min({t[row-1][col], 
//                                             t[row-1][max(0, col-1)], 
//                                             t[row-1][min(m-1, col+1)]});
//         }
//     }
//     return *min_element(t[m-1].begin(), t[m-1].end());  
// }

// int minFallingPathSum(vector<vector<int>>& matrix) { 
//     return MFS(matrix);
// }


// ➡️ Approach-3 (Bottom Up Space Optimized)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity :  O(m*n)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(n);
    for(int col = 0; col<n; col++)
        prev[col] = matrix[0][col];
            
    for(int row = 1; row<n; row++) {
        vector<int> curr(n);
        for(int col = 0; col<n; col++) {
            curr[col] = matrix[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}

int main()
{
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int ans = minFallingPathSum(matrix);
    cout << "ans is : " << ans << endl;
    return 0;
}
