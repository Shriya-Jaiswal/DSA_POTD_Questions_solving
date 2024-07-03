#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Google ✯   Amazon ✯  

int minDifference(vector<int>& nums) {
    int n = nums.size();
    if(n <= 4){
        return 0;
    }        
    sort(nums.begin(), nums.end());
    int diff1 = nums[n-4] - nums[0];
    int diff2 = nums[n-3] - nums[1];
    int diff3 = nums[n-2] - nums[2];
    int diff4 = nums[n-1] - nums[3];

    int minDiff = min({diff1,diff2,diff3,diff4});
    return minDiff;
}


int main()
{
    vector<int> nums = {5,3,2,4};
    int ans = minDifference(nums);
    cout<< "ans is : " << ans << endl;
    return 0;
}
