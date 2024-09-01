#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Google ✯  

// // ▶️ Approach-1 (Using simply simulation)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(1) //no including space of result

// vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//     vector<vector<int>> result(m, vector<int>(n));
//     int l = original.size();

//     if(m*n != l) {
//         return {};
//     }

//     int idx = 0;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             result[i][j] = original[idx];
//             idx++;
//         }
//     }

//     return result;
// }

// ▶️ Approach-2 (Using simply math observation)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(1) //no including space of result

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> result(m, vector<int>(n));
    int l = original.size();

    if(m*n != l) {
        return {};
    }

    for(int i = 0; i < l; i++) {
        result[i/n][i%n] = original[i];
    }

    return result;
}

int main()
{
    vector<int>  original = {1,2,3,4};
    int m = 2;
    int n = 2;
    vector<vector<int>> ans = construct2DArray(original,m,n);
    for(int i = 0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
