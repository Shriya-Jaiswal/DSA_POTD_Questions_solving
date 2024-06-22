#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Adobe ✯   Robolox ✯   Booking.Com ✯  

// // ▶️ Approach-1 (Using prefix sum and storing in hashmap)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int numberOfSubarrays(vector<int>& nums, int k) {
//     unordered_map<int, int> mp;
//     int n       = nums.size();
//     int count   = 0;
//     int currSum = 0;
//     mp[currSum] = 1;
//     for(int i = 0; i < n; i++) {
//         currSum += (nums[i]%2); //if odd - 1, even - 0
//         if(mp.count(currSum - k)) {
//             count += mp[currSum-k];
//         }
//         mp[currSum]++;
//     }
//     return count;
// }


// ▶️ Approach-2 (Sliding Window Khandani Template with a slight twist)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    int oddCount = 0;
    int count    = 0;
    int result   = 0;

    int i = 0;
    int j = 0;
    //Best example to understand the use of count variable - {2, 1, 2, 1}, output : 6
    while(j < n) {
        if(nums[j] % 2 != 0) { //ODD
            oddCount++;
            count    = 0; //We need to reset this to avoid over counting. Example : [1,1,2,1,1], k = 3
        }

        while(oddCount == k) {
            count++;

            if(i < n && nums[i] % 2 == 1) { //ODD
                oddCount--;
            }
            i++;
        }

        result += count;
        j++;
    }

    return result;
}

int main()
{
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int ans = numberOfSubarrays(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
