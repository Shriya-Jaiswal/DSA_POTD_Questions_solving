#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ▶️ Ask by -->  Amazon ✯   Deutsche Bank ✯   Uber ✯   Adobe ✯   Factset ✯   Fourkites   Infosys   MAQ  

// // ➡️ Approach-1 (Using Binary Search)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n) for prefixSum for effienctly calculating windowSum

// int findBest(int target_idx, int k, vector<int>& nums, vector<long>& prefixSum) {
//         int target = nums[target_idx];
        
//         int i = 0;
//         int j = target_idx;
//         int result = target_idx;
        
//         while(i <= j) {
//             int mid = i + (j-i)/2;
            
//             long count      = (target_idx - mid + 1);
//             long windowSum  = (count * target);
//             long currSum    = prefixSum[target_idx] - prefixSum[mid] + nums[mid];
            
//             int ops         = windowSum - currSum;
            
//             if(ops > k) {
//                 i = mid+1;
//             } else {
//                 result = mid;
//                 j = mid-1;
//             }
//         }
        
//         return target_idx-result+1;
//     }

// int maxFrequency(vector<int>& nums, int k) {
//     int n = nums.size();
        
//         sort(begin(nums), end(nums));
//         vector<long> prefixSum(n);
//         prefixSum[0] = nums[0];
        
//         for(int i = 1; i < n; i++) {
//             prefixSum[i] = prefixSum[i-1] + nums[i];
//         }
        
//         int result = 0;
        
//         for(int i = 0; i<n; i++) {
//             result = max(result, findBest(i, k, nums, prefixSum));
//         }
        
//         return result;
// }


// // ➡️ Approach-2 (Using sliding window)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

//  int maxFrequency(vector<int>& nums, int k) {
//         sort(begin(nums), end(nums));
        
//         int n = nums.size();
        
//         int result = 0;
        
//         int i = 0;
//         long currSum = 0;
        
//         for(int j = 0; j<n; j++) {
            
//             long target = nums[j];
//             currSum   += nums[j];
            
//             while((j-i+1)*target - currSum > k) {
//                 currSum -= nums[i];
//                 i++;
//             }
            
//             result = max(result, j-i+1);
            
//         }
//         return result;
//     }


// ➡️ Approach-3 (Improved sliding window)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(1)

int maxFrequency(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
        
    int n = nums.size();
        
    int result = 0;
        
    int i = 0;
    long currSum = 0;
        
    for(int j = 0; j<n; j++) {
            
        long target = nums[j];
        currSum   += nums[j];
            
        if((j-i+1)*target - currSum > k) {
            currSum -= nums[i];
            i++;
        }
            
        result = max(result, j-i+1);
            
    }
    return result;
}


int main()
{
    vector<int>  nums {1,2,4};
    int k = 5;

    int ans = maxFrequency(nums,k);
    cout << "ans is : " << ans << endl;

    return 0;
}
