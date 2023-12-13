#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Uber 2


// // ▶️ Approach-1 (Brute Force)
// // ⏲️ T.C : O((m*n) (m+n))
// // 🛢️ S.C : O(1)

// int numSpecial(vector<vector<int>>& mat) {
    // int result = 0;
    // int m = mat.size();
    // int n = mat[0].size();
        
    // for (int row = 0; row < m; row++) {
    //     for (int col = 0; col < n; col++) {
    //         if (mat[row][col] == 0) {
    //             continue;
    //         }
                
    //         bool good = true;
    //         //Check Row
    //         for (int r = 0; r < m; r++) {
    //             if (r != row && mat[r][col] == 1) {
    //                 good = false;
    //                 break;
    //             }
    //         }
                
    //         //Check Col
    //         for (int c = 0; c < n; c++) {
    //             if (c != col && mat[row][c] == 1) {
    //                 good = false;
    //                 break;
    //             }
    //         }
                
    //         if (good) {
    //             result++;
    //         }
    //     }
    // }
        
    // return result;        
// }


// ▶️ Approach-2(Storing count of 1s in rows and cols)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(m+n)

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> rowCount(m, 0);
    vector<int> colCount(n, 0);
        
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (mat[row][col] == 1) {
                rowCount[row]++;
                colCount[col]++;
            }
        }
    }
        
    int result = 0;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (mat[row][col] == 1) {
                if (rowCount[row] == 1 && colCount[col] == 1) {
                    result++;
                }
            }
        }
    }
        
    return result;
}


int main()
{
    vector<vector<int>>  mat = {{1,0,0},{0,0,1},{1,0,0}};
    int ans = numSpecial(mat);
    cout << "ans is : " << ans << endl;
    return 0;
}
