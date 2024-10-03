#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

// ▶️ Approach  (Using prefix sum modulo and storing in hashmap)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    int SUM = 0;

    // 👉 (a+b)%p = (a%p + b%p) % p
    for(int &num : nums) {
        SUM = (SUM + num) % p;
    }

    int target = SUM%p;

    if(target == 0) {
        return 0;
    }
    unordered_map<int, int> mp; // 👉 prev sum%p ko store karega
    int curr = 0;
    mp[0] = -1;
    int result = n;
    for(int j = 0; j < n; j++) {
        curr = (curr + nums[j]) % p;
        int remain = (curr - target + p) % p;
        if(mp.find(remain) != mp.end()) {
            result = min(result, j - mp[remain]);
        }
        mp[curr] = j;
    }
    return result == n ? -1 : result;
}

int main()
{
    vector<int> nums = {3,1,4,2};
    int p = 6;
    int ans = minSubarray(nums,p);
    cout << "ans is : " << ans << endl;
    return 0;
}
