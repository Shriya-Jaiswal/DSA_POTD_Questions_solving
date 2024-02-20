#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Microsoft ✯   Amazon ✯   Facebook ✯   Adobe ✯   Apple ✯   Salesforce   VMware   Nvidia  

// // ▶️ Approach-1 (XOR)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int missingNumber(vector<int>& nums) {
//     int sum = nums.size();
//     for(int i = 0; i<nums.size(); i++) {
//         sum ^= i;
//         sum ^= nums[i];
//     }
//     return sum;
// }


// // ➡️ Approach-2 (Math)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int missingNumber(vector<int>& nums) {
//     int n = nums.size();
//     int sum = n*(n+1)/2;
//     for(int i = 0; i<n; i++) {
//         sum -= nums[i];
//     }
//     return sum;
// }


// ▶️ Approach-3 (Binary Search)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(1)

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l   = 0;
    int r   = n-1;
    int result = n;   
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] > mid) {
            result = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    } 
    return result;    
}


int main()
{
    vector<int> nums = {3,0,1};
    int ans = missingNumber(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
