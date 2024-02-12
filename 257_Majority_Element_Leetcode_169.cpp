#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Adobe ✯   Apple ✯   Google ✯   Bloomberg   Facebook   Uber   Rubrik  


// // ▶️ Approach-1
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int majorityElement(vector<int>& nums) {
//     int n = nums.size();
//     int count = 0;
//     int maj = NULL;
        
//     for(int i = 0; i<n; i++) {
//         if(count == 0) {
//             count = 1;
//             maj = nums[i];
//         }
//         else if(nums[i] == maj) {
//             count++;
//         } else {
//             count--;
//         }
//     }
        
//     // 👉 Since it is gauranteed that majority element exists, so we don't check for freq of "maj" and return
//     return maj;
// }


////// 👉 OR you can also code it like this (Eaxct similar to Majority Element-II)
// ▶️ Approach-2
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int maj = NULL;
    for(int i = 0; i<n; i++) {
        if(nums[i] == maj) {
            count++;
        } else if(count == 0) {
            maj = nums[i];
            count = 1;
        } else {
            count--;
        }
    }
    return maj;
}

int main()
{
    vector<int> nums = {3,2,3};
    int ans = majorityElement(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
