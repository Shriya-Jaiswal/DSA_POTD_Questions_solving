#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Facebook ✯   Amazon ✯   Yahoo ✯   Adobe ✯   Bloomberg ✯  

// // ▶️ Approach-1 (Using map)
// // ⏲️ Time Complexity:  O(n)
// // 🛢️ Space Complexity : O(n)

// vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//     unordered_map<int, int> mp;

//     for(int &num : nums1) {
//         mp[num]++;
//     }

//     vector<int> result;
//     for(int i = 0; i < nums2.size(); i++) {
//         int num = nums2[i];

//         if(mp[num] > 0) {
//             mp[num]--;
//             result.push_back(num);
//         }
//     }

//     return result;
// }

// ▶️ Approach-2 (Using sorting and 2-Pointers)
// ⏲️ Time Complexity :  O(n)
// 🛢️ Space Complexity : O(n)

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));

    int i = 0; // -> nums1
    int j = 0; // -> nums2

    vector<int> result;

    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if(nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}


int main()
{
    vector<int>  nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersect(nums1,nums2);
    for(int i=0; i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
