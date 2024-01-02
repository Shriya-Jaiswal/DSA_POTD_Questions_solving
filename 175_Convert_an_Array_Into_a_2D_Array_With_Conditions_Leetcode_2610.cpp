#include<iostream>
#include<vector>
using namespace std;

// ▶️ Approach (Using frequency of elements)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

vector<vector<int>> findMatrix(vector<int>& nums) {
    int n = nums.size();
        
    //unordered_map<int, int> mp;
    //Since 1 <= nums[i] <= nums.length (you can also use vector of size n)
    vector<int> mp(n+1);
        
    vector<vector<int>> result;

    for(int &num : nums) {
        int freq = mp[num];
            
        if(freq == result.size()) {
            result.push_back({});
        }
            
        result[freq].push_back(num);
        mp[num]++;
    }
        
    return result;   
}

int main()
{
    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> ans = findMatrix(nums);
    // for(int i=0; i<ans.size(); i++){
    //     for(int j=0; j<ans[i]; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
