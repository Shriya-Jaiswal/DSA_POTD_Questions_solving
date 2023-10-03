#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include <algorithm>
using namespace std;


// // ➡️ Approach 2 cpp oneLiner code
//  int numIdenticalPairs(vector<int>& A) {
//         return accumulate(A.begin(), A.end(), 0, [count = unordered_map<int, int> {}] (auto x, auto y) mutable {
//             return x + count[y]++;
//         });
//     }

// ➡️ approach 1
int numIdenticalPairs(vector<int>& nums) {
    // 👉 calculate the frequency of each number
    int n = nums.size();
    int total = 0;
    // map<int,int> mp;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        total += mp[nums[i]];
        mp[nums[i]]++;
    } 
    return total;
}

// ⏲️ Time complexity : O(N)
// 🛢️ Space complexity : O(N)

int main()
{
    vector<int> nums {1,2,3,1,1,3};
    int ans = numIdenticalPairs(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
