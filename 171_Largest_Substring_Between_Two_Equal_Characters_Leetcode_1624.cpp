#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// ➡️ Ask by :  Google ✯  

// // ➡️ Approach-1 (Using Brute Force) - ACCEPTED
// // ⏲️ Timw Complexity : O(n^2)
// // 🛢️ Space Complexity : O(1)

// int maxLengthBetweenEqualCharacters(string s) {
//     int result = -1;
//     int n      = s.length();
//     for(int i = 0; i < n-1; i++) {
//         for(int j = i+1; j<n; j++) {   
//             if(s[i] == s[j]) {
//                 result = max(result, j-i-1);
//             }       
//         }
//     }
//     return result;
// }

// // ➡️ Approach-2 (Using Hashmap) - ACCEPTED
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity  : O(n)


// int maxLengthBetweenEqualCharacters(string s) {
//     int n = s.length();
//     unordered_map<char, int> mp;
//     int result = -1;
//     for(int i = 0 ; i < n;  i++) {
//         char ch = s[i];
//         if(mp.find(ch) == mp.end()) {
//             mp[ch] = i;
//         } else {
//             result = max(result, i - mp[ch] - 1);
//         }
//     }
//     return result;
// }

// ➡️ Approach-3 (Using integer array instead of map)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(26) ~ O(1)

int maxLengthBetweenEqualCharacters(string s) {
    int n = s.length();
    vector<int> count(26, -1);
    int result = -1;
    for(int i = 0 ; i < n;  i++) {
        char ch = s[i];
        if(count[ch-'a'] == -1) {
            count[ch-'a'] = i;
        } else {
            result = max(result, i - count[ch-'a'] - 1);
        }
    }
    return result;
}

int main()
{
    string s = "abca";
    int ans = maxLengthBetweenEqualCharacters(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
