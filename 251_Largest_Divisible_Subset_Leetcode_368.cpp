#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️  Ask by : Google ✯  

// // ▶️ Approach-1 (Using Brute Force same as LIS) ----> TLE
// // ⏲️ Time Complexity : O(2^n) without memoization
// // 🛢️ Space Complexity : O(n)


// void generate(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
//     if(idx >= nums.size()) {
//         if(temp.size() > result.size()) {
//             result = temp;
//         }
//         return;
//     }
        
//     if(prev == -1 || nums[idx] % prev == 0) {
//         temp.push_back(nums[idx]);
//         generate(idx+1, nums, result, temp, nums[idx]);
//         temp.pop_back();
//     }
//     generate(idx+1, nums, result, temp, prev);
// }
    
// vector<int> largestDivisibleSubset(vector<int>& nums) {
//     sort(begin(nums), end(nums));
//     vector<int> result;
//     vector<int> temp;
//     generate(0, nums, result, temp, -1);
//     return result;
// }


// ▶️ Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
// ⏲️ Time Complexity : O(n^2)
// 🛢️ Space Complexity : O(n)

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(begin(nums), end(nums));

    int n = nums.size();
    vector<int> t(n, 1);

    vector<int> prev_idx(n, -1);
    int last_chosen_index = 0;
    int maxL = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i]%nums[j] == 0) {
                if(t[i] < t[j]+1) {
                    t[i] = t[j]+1;
                    prev_idx[i] = j;
                }

                if(t[i] > maxL) {
                    maxL = t[i];
                    last_chosen_index = i;
                }
            }
        }
    }
    vector<int> result;
    while(last_chosen_index >= 0) {
        result.push_back(nums[last_chosen_index]);
        last_chosen_index = prev_idx[last_chosen_index];
    }
    return result;  
}

int main()
{
    vector<int> nums = {1,2,4,8};
    vector<int> ans = largestDivisibleSubset(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
