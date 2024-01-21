#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Apple ✯   Google ✯   Cisco ✯   Microsoft ✯   Adobe   Bloomberg   Facebook   Walmart Global Tech  


int solveUsingMem(vector <int> &nums, int n, vector<int> &dp){
    // 👉 base case
     if(n < 0){
        return 0;
     }

     if(n == 0){
        // 👉 single home
        return nums[0];
     }

    // 3️⃣ check already exist case
     if(dp[n] != -1){
        return dp[n];
     }

    //  👉 include
    int include = solveUsingMem(nums, n-2,dp) + nums[n];
    //  👉 exclude
    int exclude = solveUsingMem(nums, n-1, dp) + 0;

    // 2️⃣ dp me answer store karo
    dp[n] = max(include,exclude);
    return dp[n];
}

int rob(vector<int>& nums) {
    int n = nums.size() -1;
    // ➡️ create dp array
    vector<int> dp(n+1, -1);
    return solveUsingMem(nums, n,dp);
}

// ⏲️ Time complexity --> O(n)
// 🛢️ space complexity --> O(n) recursive call stack + O(n) dp array ---> O(n)+O(n)


int main()
{
    vector<int> nums = {1,2,3,1};
    int ans = rob(nums);
    cout << "ans is : " << ans << endl; 
    return 0;
}
