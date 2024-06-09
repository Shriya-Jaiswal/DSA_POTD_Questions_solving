#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Twilio ✯   Amazon ✯   Facebook ✯   Snapchat ✯   Microsoft | Paytm


// // ▶️ Approach-1 (O(n^3)) ----> TLE

// int subarraysDivByK(vector<int>& nums, int k) {
//     int n       = nums.size();
//     int count   = 0;
//     for(int i = 0; i<n; i++) {
//         for(int j = i; j<n; j++) {
//             int sum = accumulate(begin(nums)+i, begin(nums)+j+1, 0);
//             if(sum%k == 0) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // ▶️ Approach-2 (O(n^2)) ---> TLE

// int subarraysDivByK(vector<int>& nums, int k) {
//     int n       = nums.size();
//     int count   = 0;
//     for(int i = 1; i<n; i++) {
//         nums[i] += nums[i-1];
//     }
//     for(int i = 0; i<n; i++) {
//         for(int j = i; j<n; j++) {
//             int sum = (i==0) ? nums[j] : nums[j] - nums[i-1];

//             if(sum%k == 0) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }


// ▶️ Approach-3 (Time : O(n), Space : O(n))
/*
    Concept behind this method
    K
    
    a  b  c  d   e   f   g    h
    -----s1-------
    -----------------s2--------
    
    Lets say, 
    s1%k = x
    s2%k = x
    s1 = k*n + x
    s2 = k*m + x
    subarraySum = s2-s1
                = k*(m-n)
                Which proves that the subarray is divisible by k
*/


int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
        
    unordered_map<int, int> mp;
    int sum = 0;
        
    mp[0] = 1;
        
    int result = 0;
        
    for(int i = 0; i<n; i++) {
        sum += nums[i];
            
        int rem = sum%k;
            
        if(rem < 0) {
            rem += k;
        }
            
        if(mp.find(rem) != mp.end()) {
            result += mp[rem];
        }
            
        mp[rem]++;
            
    }
        
    return result;     
}

int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int ans = subarraysDivByK(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
