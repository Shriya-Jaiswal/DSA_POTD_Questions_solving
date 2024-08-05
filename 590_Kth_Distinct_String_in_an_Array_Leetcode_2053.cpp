#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

// // ▶️ Approach-1 (Using Brute Force)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(1)

// int frquencyOfString(vector<string>& arr, const string& findStr) {
//     int count = 0;
//     for(string &s : arr) {
//         if(s == findStr) { //I have ignore the time taken for this comparison
//             count++;
//         }
//         if(count > 1) {//return early
//             return count;
//         }
//     }

//     return count;
// }

// string kthDistinct(vector<string>& arr, int k) {
//     int n = arr.size();
        
//     int count = 0;
//     for(string &s : arr) {
//         if(frquencyOfString(arr, s) == 1) {
//             count++;
//             if(count == k) {
//                 return s;
//             }
//         }
//     }

//     return "";
// }

// // ▶️ Approach-2 (Using unordered_set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// string kthDistinct(vector<string>& arr, int k) {
//     unordered_set<string> st;
//     unordered_set<string> unique;
//     for(string &s : arr) {
//         if(st.find(s) != st.end()) {
//             continue;
//         }
//         if(unique.find(s) != unique.end()) {
//             unique.erase(s);
//             st.insert(s);
//         } else {
//             unique.insert(s);
//         }
//     }
//     int count = 0;
//     for(string &s : arr) {
//         if(unique.find(s) != unique.end()) {
//             count++;
//         }
//         if(count == k) {
//             return s;
//         }
//     }
//     return "";
// }

// ▶️ Approach-3 (Using Hashmap)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mp;
    for(string &s : arr) {
        mp[s]++;
    }
    int count = 0;
    for(string &s : arr) {
        if(mp[s] == 1) {
            count++;
            if(count == k) {
                return s;
            }
        }
    }
    return "";
}


int main()
{
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    string ans = kthDistinct(arr,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
