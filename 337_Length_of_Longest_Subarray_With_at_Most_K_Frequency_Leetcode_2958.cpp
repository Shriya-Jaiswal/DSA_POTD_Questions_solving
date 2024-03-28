#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // ▶️ Approach-1 (With Nested Loop - Classic Sliding Window Template)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int maxSubarrayLength(vector<int>& nums, int k) {
//     int n = nums.size();
//     unordered_map<int, int> mp;
//     int i = 0;
//     int j = 0;
//     int result = 0;
//     while(j < n) {
//         mp[nums[j]]++;   
//         while(i < j && mp[nums[j]] > k) {
//             mp[nums[i]]--;
//             i++;
//         }       
//         result = max(result, j - i + 1);
//         j++;
//     }    
//     return result;
// }


// ▶️ Approach-2 (Without nested loop)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int i = 0;
    int j = 0;
    int result = 0;
    int culprit = 0;
    while(j < n) {   
        mp[nums[j]]++;
        if(mp[nums[j]] == k+1) {
            culprit++;
        }   
        if(culprit > 0) {
            mp[nums[i]]--;
            if(mp[nums[i]] == k) {
                culprit--;
            }
            i++;
        }       
        if(culprit == 0) {
            result = max(result, j-i+1);
        }
        j++;
    } 
    return result;
}

int main()
{
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    int ans = maxSubarrayLength(nums,k);
    cout << "ans is : " << ans << endl; 
    return 0;
}
