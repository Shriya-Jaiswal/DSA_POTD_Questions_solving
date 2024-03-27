#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Goldman Sachs ✯   Yatra

// ▶️ Approach  : Standard Sliding window Problem
// ⏲️ Time Complexity : O(N)
// 🛢️ Space Complexity : O(1)

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1)
        return 0;
    int n = nums.size();
    int count = 0;
    int left = 0;
    int right = 0;
    int prod = 1;
    while(right < n){
        prod *= nums[right];
        while(prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += (right-left)+1;
        right++;
    }
    return count;
}


int main()
{
    vector<int> nums = {10,5,2,6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
