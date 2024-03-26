#include<iostream>
#include<vector>
using namespace std;

// ▶️ ask by :  Amazon ✯   Microsoft ✯   Adobe ✯   Google ✯   Facebook ✯   Databricks   Grab   Walmart Global Tech  


// 👉 NOTE - Using O(n) space is an easy aprproach. The followup is to use O(1) space to solve


// ▶️ Using O(1) space and same pattern - "Using numbers as indices"
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    bool contains1 = false;

    for (int i = 0; i < n; i++) {
        // Check whether 1 is in the original array
        if (nums[i] == 1) {
            contains1 = true;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1 ;
        }      
    }

    if (!contains1) return 1;

    // Mark whether integers 1 to n are in nums
    // Use index as a hash key and negative sign as a presence detector.
    for (int i = 0; i < n; i++) {
            
        int val = abs(nums[i]);
        int idx = val-1;
            
        if(nums[idx] < 0) continue;
        nums[idx] *= -1;
            
    }

    // First positive in nums is smallest missing positive integer
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0)
            return i+1;
    }

    return n + 1;
}

int main(){
    vector<int> nums = {1,2,0};
    int ans = firstMissingPositive(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
