#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Microsoft ✯   Amazon ✯   VMware ✯   Adobe ✯   Salesforce ✯   Nvidia   Grab   Uber   Facebook   Intel  

// // ▶️ Approach-1 : Sorting
// // ⏲️ Time Complexity : O(n*log(n))
// // 🛢️ Space Complexity : O(1)

// void sortColors(vector<int>& nums) {
//     sort(begin(nums), end(nums));
// }



// // ▶️ Approach-2 (Using counting)
// // ⏲️ Time Complexity : O(n+n)
// // 🛢️ Space Complexity : O(1)

// void sortColors(vector<int>& nums) {
//     int n = nums.size();
        
//     int count_0 = 0;
//     int count_1 = 0;
//     int count_2 = 0;
        
//     for(int &num : nums) {
//         if(num == 0)
//             count_0++;
//         else if(num == 1)
//             count_1++;
//         else
//             count_2++;
//     }
        
//     for(int i = 0; i<n; i++) {
//         if(count_0 > 0) {
//             nums[i] = 0;
//             count_0--;
//         } else if(count_1 > 0) {
//             nums[i] = 1;
//             count_1--;
//         } else if(count_2 > 0) {
//             nums[i] = 2;
//             count_2--;
//         }
//     }
// }


// ▶️ Approach-3 (Follow up) : O(n)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

void sortColors(vector<int>& nums) {
    int n = nums.size();
        
    int i = 0;   //denotes for 0
    int j = 0;   //denotes for 1
    int k = n-1; //denotes for 2
        
    while ( j <= k) {
        if(nums[j] == 1) {
            j++;
        } else if(nums[j] == 2) {
            swap(nums[j], nums[k]);
            k--;
        } else { //nums[j] == 0
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

