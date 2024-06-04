#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Amazon ✯   GOOGLE

// // ▶️ Approach-1 (Using simple set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity: O(n)

//  int longestPalindrome(string s) {
//     int n = s.length();
//     unordered_set<char> st;

//     int result = 0;
//     for(char &ch : s) {
//         if(st.count(ch)) {
//             st.erase(ch);
//             result += 2;
//         } else {
//                st.insert(ch);
//         }
//     }

//     if(!st.empty())
//         result++;
        
//     return result;
// }

// // ▶️ Approach-2 (Using hashmap and countintg frequency)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity: O(n)

// int longestPalindrome(string s) {
//     int n = s.length();
//     unordered_map<char, int> mp;

//     int result = 0;
//     for(char &ch : s) {
//         mp[ch]++;
//     }

//     bool takeCentralChar = false;
//     for(auto &it : mp) {
//         if(it.second % 2 == 0) {
//             result += it.second;
//         } else {
//             result += it.second - 1;
//             takeCentralChar = true;
//         }
//     }

//     if(takeCentralChar)
//         result++;

//     return result;
// }


// ▶️ Approach-3 (one uteration)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity: O(n)

int longestPalindrome(string s) {
    int n = s.length();
    unordered_map<char, int> mp;

    int result  = 0;
    int oddFrq  = 0;

    for(char &ch : s) {
        mp[ch]++;

        if(mp[ch] % 2 != 0) {
            oddFrq++;
        } else {
            oddFrq--;
        }
    }

    if(oddFrq > 0) {
        return n - oddFrq + 1;
    }

    return n;
}

int main()
{
    string  s = "abccccdd";
    int ans = longestPalindrome(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
