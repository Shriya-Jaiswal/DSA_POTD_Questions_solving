#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft 2 | AMAZON


// ➡️ Approach-1 (Using simple for loops)
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(m*n)

vector<vector<int>> directions{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
};
    

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int count = 0;
        // ➡️ Iterate over all plausible nine indices.
        for(auto &it : directions) {
            // ➡️ If the indices form valid neighbor
            int i_ = i + it[0];
            int j_ = j + it[1];
            if (0 <= i_ && i_ < m && 0 <= j_ && j_ < n) {
                sum += img[i_][j_];
                count += 1;
            }
        }
        result[i][j] = sum / count;
    }
    }
    return result;
}


// // ➡️ Approach-2 (Using Optimized Space)
// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(n)


// vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//     // ➡️ Save the dimensions of the image.
//     int m = img.size();
//     int n = img[0].size();
//     // ➡️ Create temp array of size n.
//     vector<int> temp(n);
//     int prevCorner = 0;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {    
//             int sum = 0;
//             int count = 0;
//         // ◀️ Bottom neighbors
//         if (i + 1 < m) {
//             if (j - 1 >= 0) {
//                 sum += img[i + 1][j - 1];
//                 count += 1;
//             }
//             sum += img[i + 1][j];
//             count += 1;
//             if (j + 1 < n) {
//                 sum += img[i + 1][j + 1];
//                 count += 1;
//             }
//         }
//         // ◀️ Next neighbor
//         if (j + 1 < n) {
//             sum += img[i][j + 1];
//             count += 1;
//         }    
//         // ➡️ This cell
//         sum += img[i][j];
//         count += 1;
//         // ➡️ Previous neighbor
//         if (j - 1 >= 0) {
//             sum += temp[j - 1];
//             count += 1;
//         }
//         // ➡️ Top neighbors
//         if (i - 1 >= 0) {
//             // ➡️ Left-top corner-sharing neighbor.
//             if (j - 1 >=  0) {
//                 sum += prevCorner;
//                 count += 1;
//             }            
//             // ➡️ Top edge-sharing neighbor.
//             sum += temp[j];
//             count += 1;
//             // ➡️ Right-top corner-sharing neighbor.
//             if (j + 1 < n) {
//                 sum += temp[j + 1];
//                 count += 1;
//             }
//         }
//         // ➡️ store corner value
//         if (i - 1 >= 0) {
//             prevCorner = temp[j];
//         }
//         // ➡️ Store current value
//         temp[j] = img[i][j];
//         // ↘️ Overwrite with smoothed value.
//         img[i][j] = sum / count;
//     }
//     }
//     // ➡️ Return the smooth image.
//     return img;
// }

int main()
{
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> ans = imageSmoother(img);
    for(int i = 0; i< ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
