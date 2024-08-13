#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Reddit ✯   Bloomberg ✯   Oracle ✯  Microsoft Adobe

// ▶️ Khaandani Template Backtracking
// ⏲️ Time Complexity : O(2^n)
// 🛢️ Space Complexity : O(n)

void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
    if(target < 0)
        return;
    if(target == 0) {
        result.push_back(curr);
        return;
    }
        
    for(int i = idx; i<candidates.size(); i++) {
        if(i > idx && candidates[i] == candidates[i-1])
            continue; //ignore duplicate elements
        curr.push_back(candidates[i]);
        solve(candidates, target-candidates[i], curr, result, i+1);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> curr;
    sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
    solve(candidates, target, curr, result, 0);
    return result;
}


int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates,target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
