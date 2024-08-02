#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// // ▶️ Ask by :  Amazon ✯  Microsoft, Adobe

// // ▶️ Approach-1 (Using extra space + Khandani Sliding Window)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(2*n) ~ O(n)

// int minSwaps(vector<int>& nums) {
//     int n = nums.size();

//     vector<int> temp(2*n);
//     for(int i = 0; i < 2*n; i++) {
//         temp[i] = nums[i%n];
//     }

//     int countOnes = accumulate(begin(nums), end(nums), 0);

//     int i = 0;
//     int j = 0;
//     int currCount = 0;
//     int maxCount = 0;

//     while(j < 2*n) {
//         if(temp[j] == 1) {
//                currCount++;
//         }

//         if(j-i+1 > countOnes) {
//             currCount -= temp[i];
//             i++;
//         }

//         maxCount = max(maxCount, currCount);
//         j++;
//     }

//     return countOnes - maxCount;

// }

// ▶️ Approach-2 (Khandani Sliding Window without extra space)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int countOnes = accumulate(begin(nums), end(nums), 0);
    int i = 0;
    int j = 0;
    int currCount = 0;
    int maxCount = 0;
    while(j < 2*n) {
        if(nums[j%n] == 1) {
            currCount++;
        }
        if(j-i+1 > countOnes) {
            currCount -= nums[i%n];
            i++;
        }
        maxCount = max(maxCount, currCount);
        j++;
    }
    return countOnes - maxCount;
}

int main()
{
    vector<int> nums = {0,1,0,1,1,0,0};
    int ans = minSwaps(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
