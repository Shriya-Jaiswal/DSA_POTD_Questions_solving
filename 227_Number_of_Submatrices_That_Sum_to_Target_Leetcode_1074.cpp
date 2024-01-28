#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Google ✯   Amazon ✯  

// // ▶️ Approach-1 (Brute Force) ---> TLE
// // ⏲️ Time Complexity : O(m^3 * n^3)
// // 🛢️ Space Complexity : O(1)

// int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int result = 0;
//     //Trying All possible start points (x, y)
//     for(int start_row = 0; start_row < m; start_row++) {
//         for(int start_col = 0; start_col < n; start_col++) {
//             //Trying All possible ending points (x', y')
//             for(int end_row = start_row; end_row < m; end_row++) {
//                 for(int end_col = start_col; end_col < n; end_col++) {
//                     //Now iterating the start points and end points
//                     int sum = 0;
//                     for(int i = start_row; i <= end_row; i++) {
//                         for(int j = start_col; j <= end_col; j++) {
//                             sum += matrix[i][j];
//                         }
//                     }   
//                     if(sum == target) {
//                         result++;
//                     }     
//                 }
//             }
//         }
//     }   
//     return result;
// }

// ▶️ Approach-2 (Using prefix sum)
// ⏲️ Time Complexity : O(n^2 * m)
// 🛢️ Space Complexity : O(m)

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(); //m
    int cols = matrix[0].size(); //n
        
    //First taje the cumulative sum row-wise
    for(int row = 0; row<rows; row++) {
        for(int col = 1; col<cols; col++) {
            matrix[row][col] += matrix[row][col-1];
        }
    }
        
    //Now, you need to find the "No. of subarrays with sum k" in downward direction
    int result = 0;
    for(int startCol = 0; startCol<cols; startCol++) {
            
        for(int currCol = startCol; currCol<cols; currCol++) {
            //We need to find all sub matrices sum
                
            //Now comes the concept of "No. of subarrays with sum k"
            unordered_map<int, int> mp;
            mp[0] = 1;
            int sum = 0;
            //Go downwards row wise
            for(int row = 0; row<rows; row++) {
                sum += matrix[row][currCol] - (startCol > 0 ? matrix[row][startCol-1] : 0);   
                if(mp.count(sum-target)) {
                    result += mp[sum-target];
                }
                mp[sum]++;       
            }      
        }
    }  
    return result;
}

int main()
{
    int target = 0;
    vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
    int ans = numSubmatrixSumTarget(matrix,target);
    cout << "ans is : " << ans << endl;
    return 0;
}
