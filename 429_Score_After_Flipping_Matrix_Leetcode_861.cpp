#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   IIT Bombay ✯  


// // ▶️ Approach-1 (Modifying the input)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(1)


// int matrixScore(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     //set first column value in each row
//     for(int i = 0; i < m; i++) {
//         if(grid[i][0] == 0) {
//             //flip that row
//             for(int j = 0; j < n; j++) {
//                 grid[i][j] = 1 - grid[i][j]; //flipping
//             }
//         }
//     }

//     for(int j = 1; j < n; j++) {   
//         int countZero = 0;
//         for(int i = 0; i < m; i++) {
//             if(grid[i][j] == 0) {
//                 countZero++;
//             }
//         }
//         int countOne = m - countZero;
//         if(countZero > countOne) {
//             //flipping that column
//             for(int i = 0; i < m; i++) {
//                 grid[i][j] = 1 - grid[i][j];
//             }
//         }
//     }
//     int score = 0;
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             int value = grid[i][j] * pow(2, n-j-1); //grid[i][j] << (n-j-1);
//             score += value;
//         }
//     }
//     return score;
// }

// ▶️ Approach-2 (Without Modifying the input)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(1)

int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    //MSB -> 2^n-1
    int score = pow(2, n-1) * m;

    for(int j = 1; j < n; j++) {

        int countSameBits = 0; //count of 1s
        for(int i = 0; i < m; i++) {
            if(grid[i][j] == grid[i][0]) {
                countSameBits++;
            }
        }

        int countOnes  = countSameBits;
        int countZeros = m - countOnes;

        int ones = max(countOnes, countZeros);

        score += (pow(2, n-j-1) * ones);            
    }
    return score;
}

int main()
{
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    int ans = matrixScore(grid);
    cout << "ans is : " << ans << endl;
    return 0;
}
