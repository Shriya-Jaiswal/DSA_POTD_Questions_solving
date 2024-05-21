#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Google ✯   Bloomberg ✯   Microsoft ✯   Apple   Twitter   Reddit   Adobe   Uber  


// ▶️ Approach-1
// ⏲️ Time Complexity : O(2^n)
// 🛢️ Space Complexity :  O(2^n*length of each subset) to store each subset
// 👉 The recursion stack space complexity is O(N) , the maximum depth of the recursion is N, where N is the length of the input array.

vector<vector<int>> result;

void solve(vector<int>& nums, int idx, vector<int>& temp) {
    if(idx >= nums.size()) {
        result.push_back(temp);
        return;
    }

    temp.push_back(nums[idx]);
    solve(nums, idx+1, temp);
    temp.pop_back();
    solve(nums, idx+1, temp);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;

    solve(nums, 0, temp);

    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
