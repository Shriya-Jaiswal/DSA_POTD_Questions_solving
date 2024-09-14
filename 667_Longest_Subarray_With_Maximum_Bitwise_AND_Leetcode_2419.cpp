#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Siemens ✯   Fourkites ✯  

// ▶️ Approach-(Simple Observation of AND property)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int longestSubarray(vector<int>& nums) {
    int maxVal = 0;
    int result = 0;
    int streak = 0;
    for (int num : nums) {
        if (num > maxVal) {
            maxVal = num;
            result = 0;
            streak = 0;
        }
        if (maxVal == num) {
            streak++;
        } else {
            streak = 0;
        }
        result = max(result, streak);
    }
    return result;
}

int main()
{
    vector<int>  nums = {1,2,3,3,2,2};
    int ans = longestSubarray(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
