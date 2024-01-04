#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

// ◀️ Ask by :  Amazon ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

int minOperations(vector<int>& nums) {
    int n = nums.size();
        
    unordered_map<int, int> mp;
        
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
        
    int result = 0;
        
    for(auto &it : mp) {
        int freq = it.second;
            
        if(freq == 1) { // 👉we can only remove equal elements
            return -1;
        }
            
        result += ceil((double)freq/3);
    }
        
    return result;
}

int main()
{
    vector<int> nums = {2,3,3,2,2,4,2,3,4};
    int ans = minOperations(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}


