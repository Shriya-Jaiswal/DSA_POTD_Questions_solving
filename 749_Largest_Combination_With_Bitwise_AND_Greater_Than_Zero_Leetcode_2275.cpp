#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Adobe ✯   Jump Trading ✯   Hudson River Trading ✯  

// // ▶️ Approach-1 (Using counter array)
// // ⏲️ Time Complexity : O(24*n) ~= O(n)
// // 🛢️ Space Complexity : O(24) ~= O(1)

// int largestCombination(vector<int>& candidates) {
//     vector<int> count(24, 0);
//     // ▶️ count[i] = how many numbers have ith bit set
//     int result = 0;
//     for(int i = 0; i < 24; i++) { // 👉 O(24)
//         for(int &num : candidates) { // 👉 O(n)
//             if((num & (1 << i)) != 0) {
//                 count[i]++;
//             }
//         }
//         result = max(result, count[i]);
//     }
//     return result;
// }

// ▶️ Approach-2 (without using counter array)
// ⏲️ Time Complexity : O(24*n) ~= O(n)
// 🛢️ Space Complexity : O(1)

int largestCombination(vector<int>& candidates) {
    // 👉 vector<int> count(24, 0); //O(24)
    // 👉 count[i] = how many numbers have ith bit set
    int result = 0;
    for(int i = 0; i < 24; i++) { // 👉 O(24)
        int count_ith = 0;
        for(int &num : candidates) { // 👉 O(n)
            if((num & (1 << i)) != 0) {
                count_ith += 1;
            }
        }
        result = max(result, count_ith);
    }
    return result;
}


int main()
{
    vector<int> candidates = {16,17,71,62,12,24,14};
    int ans = largestCombination(candidates);
    cout << "ans is : " << ans << endl;
    return 0;
}
