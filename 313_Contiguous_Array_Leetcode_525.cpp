#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Facebook ✯   Microsoft ✯   Apple ✯  Google

// ▶️ Using the same pattern code
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 0;
        
    unordered_map<int, int> mp;
    int currSum = 0;
    int maxL = 0;
    mp[0] = -1;
    for(int i = 0; i<n; i++) {
        currSum += (nums[i] == 1) ? 1 : -1;
            
        if(mp.find(currSum) != mp.end()) {
            maxL = max(maxL, i-mp[currSum]);
        } else
            mp[currSum] = i;
    }
    return maxL;
}

int main()
{
    vector<int>  nums = {0,1};
    int ans = findMaxLength(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
