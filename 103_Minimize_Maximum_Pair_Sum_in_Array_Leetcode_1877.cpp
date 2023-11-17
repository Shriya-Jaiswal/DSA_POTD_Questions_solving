#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ➡️ Simple 2-pointer approach
// ⏲️ Time Complexity : O(nlogn) due to sorting
// 🛢️ Space Complexity : O(1)


// ▶️ Ask by --> Google ✯   eBay ✯  

int minPairSum(vector<int>& nums) {
    sort(begin(nums), end(nums));
        int maxResult = 0;
        int i = 0, j = nums.size()-1;
        while(i < j) {
            int sum = nums[i] + nums[j];   
            maxResult = max(maxResult, sum);
            i++;
            j--;
        }
        return maxResult;
}

int main()
{
    vector<int> nums {3,5,2,3};
    int ans = minPairSum(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
