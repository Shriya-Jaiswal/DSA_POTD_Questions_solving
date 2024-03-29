#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Approach-1 (Classic sliding window)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// long long countSubarrays(vector<int>& nums, int k) {
//     int maxE = *max_element(begin(nums), end(nums));
//     int n = nums.size();
//     int i = 0, j = 0;
//     long long result = 0;
//     int countMax = 0;
//     while(j < n) {
//         if(nums[j] == maxE) {
//             countMax++;
//         }
//         while(countMax >= k) {
//             result += n-j;
//             if(nums[i] == maxE) {
//                 countMax--;
//             }
//             i++;
//         }
//         j++;
//     }
//     return result;
// }


// ▶️ Approach-2 (Without Sliding Window)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)


long long countSubarrays(vector<int>& nums, int k) {
    int maxE = *max_element(begin(nums), end(nums));
        
    int n = nums.size();
        
    long long result = 0;

    vector<int> maxIndices;
        
    for(int i = 0; i < n; i++) {
        if(nums[i] == maxE) {
            maxIndices.push_back(i);
        }
            
        int size = maxIndices.size();
        if(size >= k) {
            int last_i = maxIndices[size-k];
            result += last_i+1;
        }
    }
        
    return result;
}

int main()
{
    int k = 2;
    vector<int> nums = {1,3,2,3,3};
    long long ans = countSubarrays(nums,k);
    cout << "ans is : " << ans << endl;

    return 0;
}
