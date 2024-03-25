#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Google ✯   Adobe ✯   Apple ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result; 
    for(int i = 0; i < n; i++) {
        int num = abs(nums[i]);
            
        if(nums[num-1] < 0) {
            result.push_back(num);
        } else {
            nums[num-1] *= -1;
        }
    }
    return result; 
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDuplicates(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
