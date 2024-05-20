#include<iostream>
#include<vector>
using namespace std;

// // ▶️ Ask by :  Adobe ✯   Google, Meta

// // ▶️ Approach-1 (Using simple backtracking to generate subsets)
// // ⏲️ Time Complexity : O(n * 2^n)
// // 🛢️ Space Complexiy : O(n * 2^n)

// void solve(vector<int>& nums, int i, vector<int>& currSubset,
//                          vector<vector<int>>& subsets) {

//     if (i == nums.size()) {
//         subsets.push_back(currSubset);
//         return;
//     }

//     currSubset.push_back(nums[i]);
//     solve(nums, i + 1, currSubset, subsets);
//     currSubset.pop_back();
//     solve(nums, i + 1, currSubset, subsets);
// }

// int subsetXORSum(vector<int>& nums) {
//     vector<vector<int>> subsets;
//     vector<int> currSubset;
//     solve(nums, 0, currSubset, subsets);

//     int result = 0;
//     for (auto& currSubset : subsets) {
//         int Xor = 0;
//         for (int num : currSubset) {
//             Xor ^= num;
//         }
//         result += Xor;
//     }
//     return result;
// }


// // ▶️ Approach-2 (Using optimal backtracking)
// // ⏲️ Time Complexity : O(2^n)
// // 🛢️ Space Complexity : O(n)


// int solve(int i, vector<int>& nums, int Xor) {
//     if(i == nums.size()) {
//         return Xor;
//     }

//     int include = solve(i+1, nums, nums[i] ^ Xor);
//     int exclude = solve(i+1, nums, Xor);

//     return include + exclude;
// }

// int subsetXORSum(vector<int>& nums) {
//     return solve(0, nums, 0);
// }




// ▶️ Approach-3 (Observing pattern)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int result = 0;

    for(int &num : nums) {
        result |= num;
    }

    return result << (n-1);
}



int main()
{
    vector<int>  nums = {1,3};
    int ans = subsetXORSum(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
