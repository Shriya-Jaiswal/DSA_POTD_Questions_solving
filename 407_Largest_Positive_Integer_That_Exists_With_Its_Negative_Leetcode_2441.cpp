#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// // ▶️ Approach-1
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(1)

// int findMaxK(vector<int>& nums) {
//     int result = -1;
        
//     for (int &i : nums) {
//         for (int &j : nums) {
//             // 👉 If there exists a number j such that i is the negative of j
//             if (i == -j) {
//                 // 👉 Update the answer to the maximum of current ans and absolute value of i
//                 result = max(result, abs(i));
//             }
//         }
//     }
//     return result;
// }

// // ▶️ Approach-2 (Using Sorting + 2-Pointers)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int findMaxK(vector<int>& nums) {
//     sort(begin(nums), end(nums));
//     int i = 0;
//     int j = nums.size() - 1;
//     while (i < j) {
//         if (-nums[i] == nums[j]) {
//             return nums[j];
//         } 
//         else if (-nums[i] < nums[j]) { 
//             j--;
//         }
//         else { 
//             i++;
//         }
//     }
//     return -1;
// }

// // ▶️ Approach-3 (Using set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int findMaxK(vector<int>& nums) {
//     unordered_set<int> seen;
//     int result = -1;
//     for(int num : nums) {
//         if (seen.count(-num)) {
//             result = max(result, abs(num));
//         }
//         seen.insert(num);
//     }  
//     return result;
// }

// ▶️ Approach-4 (Using nums[i] as index)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int findMaxK(vector<int>& nums) {
    int result = -1;
    int arr[2001] = {0};
    for (int num : nums) {
        if (arr[-num + 1000] == 1)
            result = max(result, abs(num));
        // Mark the current number as seen
        arr[num + 1000] = 1;
    }
    return result;
}

int main()
{
    vector<int> nums = {-1,2,-3,3};
    int ans = findMaxK(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
