#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯  GOOGLE

// ▶️ Approach (Greedy observation)
// ⏲️ Time Complexity : O(max(l, log(n)), l = length of nums
// 🛢️ Space Complexity : O(1)


int minPatches(vector<int>& nums, int n) {
    long maxReach = 0;
    int patch     = 0;
    int i         = 0;

    while(maxReach < n) {
        if(i < nums.size() && nums[i] <= maxReach+1) {
            maxReach += nums[i];
            i++;
        } else {
            maxReach += (maxReach + 1);
            patch++;
        }
    }
    return patch;
}

int main()
{
    int n = 6;
    vector<int> nums = {1,3};
    int ans = minPatches(nums,n);
    cout << "ans is : " << ans << endl;
    return 0; 
}
