#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by --->  Microsoft ✯  

// ➡️ Approach - Using sorting
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(1)

int reductionOperations(vector<int>& nums) {
    int n = nums.size();
        
    sort(begin(nums), end(nums));
        
    int count = 0;
        
    for(int i = n-1; i > 0; i--) {
        if(nums[i] == nums[i-1]) {
            continue;
        }   
        count += n-i;
    }
    return count;   
}

int main()
{
    vector<int> nums = {5,1,3};
    int ans = reductionOperations(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
