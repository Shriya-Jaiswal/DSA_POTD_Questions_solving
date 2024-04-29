#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

 int minOperations(vector<int>& nums, int k) {
    int totalXor = 0; 
    for(int &num : nums) {
        totalXor ^= num;
    }   
    int diff = (totalXor ^ k);   
    return __builtin_popcount(diff);   
}



int main()
{
    vector<int> nums = {2,1,3,4};
    int k = 1;
    int ans = minOperations(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
