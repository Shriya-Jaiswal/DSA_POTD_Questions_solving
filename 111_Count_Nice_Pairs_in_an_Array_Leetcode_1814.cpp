#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Uber ✯  AMAZON 

// ➡️ Approach (Rearrange i and j and compute with Map)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) using map

int M = 1e9+7;
    int reverse(int num) {
    int rev = 0;
        
    while(num > 0) {
        int rem = num%10;
        rev = rev*10 + rem;
        num /= 10;
    }
        
    return rev;
}

int countNicePairs(vector<int>& nums) {
    int n = nums.size();    
    unordered_map<int, int> mp;
    //nums[i] - rev(nums[i]) ==  nums[j] - rev(nums[j])
    for(int i = 0; i<n; i++) {
        nums[i] = nums[i] - reverse(nums[i]);
    }
    int result = 0;
    for(int i = 0; i<n; i++) {       
        result = (result + mp[nums[i]]) % M;
        mp[nums[i]]++;
    }
    return result;
}

int main()
{
    vector<int> nums = {42,11,1,97};
    int ans = countNicePairs(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
