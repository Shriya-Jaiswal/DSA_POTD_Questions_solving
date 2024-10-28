#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<math.h>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

// // ▶️ Approach-1 (Using sorting and map)
// //⏲️ Time complexity: O(nlogn)
// //🛢️ Space complexity : O(n)

// int longestSquareStreak(vector<int>& nums) {
//         unordered_map<int, int> mp;

//         sort(begin(nums), end(nums));

//         int maxStreak = 0;

//         for(int &num : nums) { //2, 4 
//             //check if this number is a perfect square
//             int root = (int)sqrt(num);

//             if(root*root == num && mp.find(root) != mp.end()) {
//                 mp[num] = mp[root] + 1;
//             } else {
//                 mp[num] = 1;
//             }

//             maxStreak = max(maxStreak, mp[num]);

//         }

//         return maxStreak < 2 ? -1 : maxStreak;
//     }

// ▶️ Approach-2 (Using set)
// ⏲️ Time complexity : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
// 🛢️ Space complexity : O(n)

int longestSquareStreak(vector<int>& nums) {
    unordered_set<int> st(begin(nums), end(nums));

    int maxStreak = 0;

    for(int &num : nums) {
        int streak = 0;
        long long curr = num;

        while(st.find(curr) != st.end()) {
            streak++;

            if(curr*curr > 1e5) {
                break;
            }

            curr = curr*curr; //square
        }

        maxStreak = max(maxStreak, streak);
    }

    return maxStreak < 2 ? -1 : maxStreak;
}

int main()
{
    vector<int> nums = {4,3,6,16,8,2};
    int ans = longestSquareStreak(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
