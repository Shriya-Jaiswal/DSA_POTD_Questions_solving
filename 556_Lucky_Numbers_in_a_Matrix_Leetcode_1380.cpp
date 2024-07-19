#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// // ▶️ Ask by :  Apple ✯  Cisco

// // ▶️ Approach-1 (Using Simple Traversal and extra space)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m+n)

// vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//     int m = matrix.size();
//     int n = matrix[0].size();

//     vector<int> rowMin;
//     for (int row = 0; row < m; row++) {

//         int rMin = INT_MAX;
//         for (int col = 0; col < n; col++) {
//             rMin = min(rMin, matrix[row][col]);
//         }
//         rowMin.push_back(rMin);
//     }

//     vector<int> colMax;
//     for (int col = 0; col < n; col++) {

//         int cMax = INT_MIN;
//         for (int row = 0; row < m; row++) {
//             cMax = max(cMax, matrix[row][col]);
//         }
//         colMax.push_back(cMax);
//     }

//     vector<int> result;
//     for (int row = 0; row < m; row++) {
//         for (int col = 0; col < n; col++) {
//             if (matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]) {
//                 result.push_back(matrix[row][col]);
//             }
//         }
//     }

//     return result;
// }



//Approach-2 (Only one Lucky Number is possible) - Find it Greedily
//T.C : O(m*n)
//S.C : O(1)

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int m = matrix.size(); //rows
    int n = matrix[0].size(); //columns
    int rMinMax = INT_MIN;
    for(int row = 0; row < m; row++) {
        int rMin = INT_MAX;
        for(int col = 0; col < n; col++) {
            rMin = min(rMin, matrix[row][col]);
        }
        rMinMax = max(rMinMax, rMin);
    }
    int cMaxMin = INT_MAX;
    for(int col = 0; col < n; col++) {
        int cMax = INT_MIN;
        for(int row = 0; row < m; row++) {
            cMax = max(cMax, matrix[row][col]);
        }
        cMaxMin = min(cMaxMin, cMax);
    }
    if(rMinMax == cMaxMin) {
        return {rMinMax}; //{cMaxMin}
    }
    return {};
}



int main()
{
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> ans = luckyNumbers(matrix);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]<< " "; 
    }
    cout << endl;
    return 0;
}
