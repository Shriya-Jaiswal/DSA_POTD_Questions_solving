#include<iostream>
#include<vector>
#include<map>
using namespace std;

// // ▶️ Ask by :  Adobe ✯  

// // ▶️ Approach-1 (Smart Approach)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// vector<int> findErrorNums(vector<int>& nums) {
//     int n = nums.size();
//     int dup     = -1;
//     int missing = -1;
//     for(int i = 0; i<n; i++) {
//         int num = abs(nums[i]);
//         if(nums[num-1] < 0)
//             dup = num;
//         else
//             nums[num-1] *= (-1);
//     }   
//     for(int i = 0; i<n; i++) {
//         if(nums[i] > 0) {
//             missing = i+1;
//             break;
//         }
//     }
//     return {dup, missing};
// }


// ▶️ Approach-2 (Basic Approach)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int miss = 0, dup = 0;
        
    map<int, int> mp;
    for(int x:nums) {
        mp[x]++;
    }
        
    for(int i = 1; i<=n; i++) {
        if(mp.count(i)) {
            if(mp[i] == 2)
                dup = i;
        } else
            miss = i;
    }
        
    return {dup, miss};
}

int main()
{
    vector<int> nums = {1,2,2,4};
    vector<int> ans = findErrorNums(nums);
    for(int i=0; i<ans.size(); i++){
        cout  << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
