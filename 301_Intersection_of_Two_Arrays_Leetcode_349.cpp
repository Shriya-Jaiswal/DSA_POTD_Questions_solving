#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// // ▶️ ask by :  Amazon ✯   Facebook ✯   Apple ✯   Adobe ✯   Google ✯   Microsoft   Bloomberg   JPMorgan  

// // ▶️ Approach-1 (Using two sets)
// // ⏲️ Time Complexity : O(m+n)
// // 🛢️ Space Complexity : O(m+n)

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     unordered_set<int> st1(begin(nums1), end(nums1));
//     unordered_set<int> st2;
//     for(int &num : nums2) {
//         if(st1.find(num) != st1.end()) {
//             st2.insert(num);
//         }    
//     }
//     vector<int> result;
//     for(auto &it : st2) {
//         result.push_back(it);
//     }  
//     return result;
// }



// // ▶️ Approach-2 (Using one set)
// // ⏲️ Time Complexity : O(m+n)
// // 🛢️ Space Complexity : O(m+n)

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     unordered_set<int> st(begin(nums1), end(nums1));
//     vector<int> result;   
//     for(int &num : nums2) {
//         if(st.find(num) != st.end()) {
//             result.push_back(num);
//             st.erase(num);
//         }    
//     }
//     return result;
// }


// // ▶️ Approach-3 (Sorting and binary search)
// // ⏲️ Tim Complexity : O(n + mlogm)
// // 🛢️ Space Complexity : O(n)

// bool binarySearch(vector<int>& nums, int target) {
//     int l = 0, r = nums.size()-1;
//     while(l <= r) {
//         int mid = l + (r-l)/2;
            
//         if(nums[mid] == target) {
//             return true;
//         } else if(nums[mid] < target) {
//             l = mid+1;
//         } else {
//             r = mid-1;
//         }
//     }
//     return false;
// }
    
// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     sort(begin(nums1), end(nums1));
//     unordered_set<int> st;
//     for(int &num : nums2) {
//         if(binarySearch(nums1, num)) {
//             st.insert(num);
//         }
//     }     
//     vector<int> result(begin(st), end(st));   
//     return result;
        
// }



// ▶️ Approach-4 (Sorting and two-pointers)
// ⏲️ Time Complexity : O(n + m)
// 🛢️ Space Complexity : O(1)


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
        
    int m = nums1.size();
    int n = nums2.size();
        
    vector<int> result;
    int i = 0, j = 0;
        
    while(i < m && j < n) {

        if(nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
                
            while(i < m-1 && nums1[i] == nums1[i+1]) {
                i++;
            }
            while(j < n-1 && nums2[j] == nums2[j+1]) {
                j++;
            }
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
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersection(nums1,nums2);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
