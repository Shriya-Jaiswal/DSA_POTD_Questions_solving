#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

// // ▶️ Ask by :  Uber ✯   Amazon ✯   Google ✯  

// // ▶️ Approach-1 (Using sliding window + heap)
// // ⏲️ Time complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n)

// typedef pair<int, int> P;

// int longestSubarray(vector<int>& nums, int limit) {
//     int n = nums.size();
//     priority_queue<P> maxPq;
//     priority_queue<P, vector<P>, greater<P>> minPq;

//     int i = 0;
//     int j = 0;
//     int maxLength = 0;

//     while (j < n) {
//         maxPq.push({nums[j], j});
//         minPq.push({nums[j], j});

//         while (maxPq.top().first - minPq.top().first > limit) {
//             i = min(maxPq.top().second, minPq.top().second) + 1;

//             while (maxPq.top().second < i) {
//                 maxPq.pop();
//             }
//             while (minPq.top().second < i) {
//                 minPq.pop();
//             }
//         }

//         // 👉 Update maxLength with the length of the current valid window
//         maxLength = max(maxLength, j - i + 1);
//         j++;
//     }
//     return maxLength;
// }

// ▶️ Approach-2 (Using sliding window + multiset)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)

int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();

    multiset<int> st;
    int i = 0;
    int j = 0;
    int maxLength = 0;

    while (j < n) {
        st.insert(nums[j]);

        while (*st.rbegin() - *st.begin() > limit) {
            st.erase(st.find(nums[i]));
            ++i;
        }

        maxLength = max(maxLength, j - i + 1);
        j++;
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    int ans = longestSubarray(nums,limit);
    cout << "ans is : " << ans << endl;
    return 0;
}
