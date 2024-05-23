#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Infosys ✯  

// ▶️ Simple backtracking just like subsets
// ⏲️ Time Complexity : O(2^n)
// 🛢️ Space Complexity : O(n)

int result;
int K;
void dfs(vector<int> &nums, int idx, unordered_map<int, int> &mp) {

    if(idx == nums.size()) {
        result++;
        return;
    }

    //not_take
    dfs(nums, idx+1, mp);
        
    //checking if we can take it or not
    if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
            mp[nums[idx]]++;
            dfs(nums, idx + 1, mp);
            mp[nums[idx]]--;
    }
}

int beautifulSubsets(vector<int>& nums, int k) {

    result = 0;
    K = k;

    unordered_map<int, int> mp;
 
    dfs(nums, 0, mp);

    return result - 1; // 👉 -1 because we don't want to count empty subset in result
}

int main()
{
    vector<int> nums = {2,4,6};
    int k = 2;
    int ans = beautifulSubsets(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
