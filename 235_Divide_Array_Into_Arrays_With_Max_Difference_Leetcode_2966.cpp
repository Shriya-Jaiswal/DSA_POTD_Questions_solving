#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Google ✯  

// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(1)

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> result;
    sort(begin(nums), end(nums));   
    for(int i = 0; i <= n-3; i += 3) {
        if(nums[i+2] - nums[i] > k) {
            return {};
        }    
        result.push_back({nums[i], nums[i+1], nums[i+2]});
    }
    return result;
}

int main()
{
    int k = 2;
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    vector<vector<int>> ans = divideArray(nums,k);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
