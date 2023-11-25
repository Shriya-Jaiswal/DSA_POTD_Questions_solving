#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// ▶️ Ask by : ✯ Adobe  

// // ▶️ Approach-1 (Using Prefix Sum)
// // ⏲️ Time Complexity : O(n);
// // 🛢️ Space Complexity : O(n) stored prefix Sum

// vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//     int n = nums.size();
        
//     vector<int> prefixSum(n);
//     prefixSum[0] = nums[0];
        
//     for(int i = 1; i<n; i++) {
//         prefixSum[i] = nums[i] + prefixSum[i-1];
//     }
        
//     vector<int> result(n);
        
//     for(int i = 0; i < n; i++) {
//         int leftSum   = prefixSum[i] - nums[i];
//         int rightSum  = prefixSum[n-1] - prefixSum[i];
            
//         int leftCount  = i;
//         int rightCount = n-i-1;
            
//         int leftTotal  = (leftCount * nums[i]) - leftSum;
//         int rightTotal = rightSum - (nums[i]*rightCount);
            
//         result[i] = leftTotal + rightTotal;
//     }
        
//     return result;        
// }



// ▶️ Approach-2 (Without using extra space for prefix sum)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)


 vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(begin(nums), end(nums), 0); // 👉 Numeric header file

    vector<int> result(n);
    int prefixSum = 0;
        
    for(int i = 0; i < n; i++) {
        int leftSum   = prefixSum;
        int rightSum  = sum - prefixSum - nums[i];
            
        int leftCount  = i;
        int rightCount = n-i-1;
            
        int leftTotal  = (leftCount * nums[i]) - leftSum;
        int rightTotal = rightSum - (nums[i]*rightCount);
            
        result[i] = leftTotal + rightTotal;
        prefixSum += nums[i];
    } 
    return result;   
}

int main()
{
    vector<int> nums = {2,3,5};
    vector<int> ans = getSumAbsoluteDifferences(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
