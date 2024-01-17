#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Adobe ✯   Facebook ✯   Apple ✯   Bloomberg ✯   Google  

// // ➡️ Approach-1 (Simple using hash map and set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// bool uniqueOccurrences(vector<int>& arr) {
//     unordered_map<int, int> mp;   
//     // ➡️ store frequency of each numbers
//     for(int &x : arr) {
//         mp[x]++;
//     }
//     unordered_set<int> st; 
//     for(auto &it : mp) {
//         int freq = it.second; //it.first = number
//         if(st.find(freq) != st.end())
//             return false;
//         st.insert(freq);
//     }
//     return true;
// }

// // ➡️ Approach-2 (Making benefit of constraints)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

//  bool uniqueOccurrences(vector<int>& arr) {
//         vector<int> vec(2001, 0);
//         for(int &x : arr) {
//             vec[x + 1000]++;
//         }
//         sort(begin(vec), end(vec));
//         for(int i = 1; i<2001; i++) {
//             if(vec[i] != 0 && vec[i] == vec[i-1])
//                 return false;
//         }     
//         return true;
// }


// ➡️ Approach-3 (Improvement on Approach-2)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)


 bool uniqueOccurrences(vector<int>& arr) {
    vector<int> vec(2001, 0);
    for(int &x : arr) {
        vec[x + 1000]++;
    }
    for(int i = 1; i<2001; i++) {
        if(vec[i] == 0) continue;
        int idx = abs(vec[i]);
        if (vec[idx] < 0) {
            return false;
        }
        vec[idx] = -1;
    }    
    return true;
}

int main()
{
    vector<int> arr = {1,2,2,1,1,3};
    bool ans = uniqueOccurrences(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
