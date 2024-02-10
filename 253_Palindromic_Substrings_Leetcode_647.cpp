#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// ▶️ Ask by :   Facebook ✯   Twitter ✯   Expedia ✯  

// // ▶️ Approach-1 (Simply check all substrings possilbe)
// // ⏲️ Time Complexity : O(n^3)
// // 🛢️ Space Complexity : O(1)

// bool check(string &s, int i, int j) {
//     if(i >= j) {
//         return true;
//     }
//     if(s[i] == s[j]) {
//         return check(s, i+1, j-1);
//     }
//     return false;
// }

// int countSubstrings(string s) {
//     int n = s.length();
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = i; j < n; j++) { //check all possible substrings
//             if(check(s, i, j)) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }



// // ▶️ Approach-2 (Memoize the approach above)
// // ⏲️ Time Complexity : O(n^2) - Every subproblem is being computed only once and after that it's being reused
// // 🛢️ Space Complexity : O(n^2)

// int t[1001][1001];
// bool check(string &s, int i, int j) {
//     if(i >= j) {
//         return true;
//     }
//     if(t[i][j] != -1) {
//         return t[i][j]; //1 : True, 0 : False
//     }
//     if(s[i] == s[j]) {
//         return t[i][j] = check(s, i+1, j-1);
//     }
//     return t[i][j] = false;
// }

// int countSubstrings(string s) {
//     int n = s.length();
//     memset(t, -1, sizeof(t));
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = i; j < n; j++) { //check all possible substrings
//             if(check(s, i, j)) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }



// // ▶️ Approach-3(Bottom Up - My Favourite Blue Print of Pallindrome Qns)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity ; O(n^2)

// int countSubstrings(string s) {
//     int n = s.length();
//     vector<vector<bool>> t(n, vector<bool>(n, false));
//     //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices
//     int count = 0;
//     for(int L = 1; L <= n; L++) {
//         for(int i = 0; i+L <= n; i++) {
//             int j = i + L - 1;
//             if(i == j) {
//                 t[i][i] = true; //Single characters are palindrome
//             } else if(i+1 == j) {
//                 t[i][j] = (s[i] == s[j]); //Strings of 2 Length
//             } else {
//                 t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
//             }
//             count += t[i][j];
//         }
//     }
//     return count;
// }


// ▶️ Approach-4 (Smart approach)
// ⏲️ Time Complexity : O(n^2)
// 🛢️ Space Complexity : o(1)

int count = 0;
void check(string& s, int i, int j, int n) {
    while(i >= 0 && j < n && s[i] == s[j]) {
        count++;
        i--; //expanding from center
        j++; //expanding from center
    }
}

int countSubstrings(string s) {
    int n = s.length();
    count = 0;
/*
👉            
Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.
*/

    for(int i = 0; i<n; i++) {
        check(s, i, i, n);
        check(s, i, i+1, n);
    }
    return count;
}



int main()
{
    string s = "abc";
    int ans = countSubstrings(s);
    cout << "ans is : " << ans << endl;   
    return 0;
}
