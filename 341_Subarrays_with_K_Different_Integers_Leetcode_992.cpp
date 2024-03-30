#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Amazon

// // ▶️ Approach-1 (Standard Sliding Window twice - A very good Pattern of Sliding Window Problems)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// // 👉 Total count of subarrays having <= k distict elements
// int slidingWindow(vector<int>& nums, int k) {
//     unordered_map<int, int> mp;
        
//     int n = nums.size();
//     int i = 0; 
//     int j = 0;
        
//     int count = 0;
        
//     while(j < n) {
            
//         mp[nums[j]]++;
            
//            while(mp.size() > k) {
//             //shrink the window
//             mp[nums[i]]--;
//             if(mp[nums[i]] == 0) {
//                 mp.erase(nums[i]);
//             }
//             i++;
//         }  
//         count += (j-i+1); //ending at j
//         j++;
//     }
//     return count;
// }
    
// int subarraysWithKDistinct(vector<int>& nums, int k) {
//     return slidingWindow(nums, k) - slidingWindow(nums, k-1);
// }


// ▶️ Approach-2 (One Pass Flow)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int i_chota  = 0;
    int j        = 0;
    int i_bada   = 0;
    int result   = 0;
    while(j < n) {
        mp[nums[j]]++;   
        while(mp.size() > k) {
            mp[nums[i_chota]]--;
            if(mp[nums[i_chota]] == 0) {
                mp.erase(nums[i_chota]);
            }
            i_chota++;
            i_bada = i_chota;
        }   
        while(mp[nums[i_chota]] > 1) {
            mp[nums[i_chota]]--;
            i_chota++;
        }       
        if(mp.size() == k) {
            result += i_chota - i_bada + 1;
        }
        j++;
    } 
    return result;
}

int main()
{
    int k = 2;
    vector<int> nums = {1,2,1,2,3};
    int ans = subarraysWithKDistinct(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
