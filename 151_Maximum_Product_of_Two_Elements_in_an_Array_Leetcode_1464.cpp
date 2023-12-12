#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Yahoo 2 | Facebook 2 | Samsung 1

// // ▶️ Approach-1 (Keep finding the max current number)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int maxProduct(vector<int>& nums) {
//     int n = nums.size();
//     int maxNum = nums[0];
//     int result = 0; 
//     for(int i = 1; i<n; i++) {
//         result = max(result, (maxNum-1)*(nums[i]-1));
//         maxNum = max(maxNum, nums[i]);
//     }
//     return result;
// }


// ▶️ Approach-2 (Find max and secondmax number)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int firstMax  = 0;
    int secondMax = 0;
    for(int i = 0; i<n; i++) {
        if(nums[i] > firstMax) {
            secondMax = firstMax;
            firstMax = nums[i];
        } else {
            secondMax = max(secondMax, nums[i]);
        }   
    }
    return (firstMax-1)*(secondMax-1);
}

int main()
{
    vector<int>  nums = {3,4,5,2};
    int ans = maxProduct(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
