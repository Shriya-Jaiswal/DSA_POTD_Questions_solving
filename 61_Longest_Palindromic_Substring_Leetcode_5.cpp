#include<iostream>
#include<limits.h>
#include<vector>
#include<cstring>
using namespace std;

// ▶️ DP ----> 🌟 ⭐ ⭐ Amazon, microsoft ,samsung, Google , adobe ....ect

// bool solveUsingRec(string &s, int i, int j){
//     if(i >= j){
//         return true;
//     }
//     if(s[i] == s[j]){
//         return solveUsingRec(s,i+1,j-1);
//     }
//     return false;
// }


// string longestPalindrome(string s) {
//     int n = s.length();

//     int maxLen = INT_MIN;
//     int starting_Point = 0;

//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             if(solveUsingRec(s,i,j) == true){ // 👉 it means palindrome
//                 if(j-i + 1 > maxLen){
//                     maxLen = j-i+1;
//                     starting_Point = i;
//                 }
//             }
//         }
//     }
//     return s.substr(starting_Point,maxLen);
// }


int dp[1001][1001];
bool solveUsingMem(string &s, int i, int j){
    if(i >= j){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == s[j]){
        return dp[i][j] = solveUsingMem(s,i+1,j-1);
    }
    return dp[i][j] = 0;
}

string longestPalindrome(string s) {
    int n = s.length();
    memset(dp,-1,sizeof(dp));
    int maxLen = INT_MIN;
    int starting_Point = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(solveUsingMem(s,i,j) == true){ // 👉 it means palindrome
                if(j-i + 1 > maxLen){
                    maxLen = j-i+1;
                    starting_Point = i;
                }
            }
        }
    }
    return s.substr(starting_Point,maxLen);
}

// ⏲️ time complexity ---> O(n^3)

int main()
{
    string s = "babad";
    string ans = longestPalindrome(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
