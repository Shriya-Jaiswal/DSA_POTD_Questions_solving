#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   DoorDash ✯   Bloomberg ✯   Karat ✯  


// // ⏲️ Time Complexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n)
// // ▶️ Approach-1 (Recursion + Memoization)

// int t[1001][1001];
// int LCS(string& s1, string& s2, int m, int n) {
//     if(m == 0 || n == 0)
//         return t[m][n] = 0;
        
//     if(t[m][n] != -1)
//         return t[m][n];
        
//     if(s1[m-1] == s2[n-1])
//         return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
//     return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
// }


// int longestCommonSubsequence(string text1, string text2) {
//     int m = text1.length();
//     int n = text2.length();  
//     memset(t, -1, sizeof(t));
//     return LCS(text1, text2, m, n);
// }


// // ▶️ Approach-2 (Bottom Up)
// // ⏲️ Time Comeplexity : O(m*n)
// // 🛢️ Space Complexity : O(m*n)

// int longestCommonSubsequence(string text1, string text2) {
//     int m = text1.length();
//     int n = text2.length();
        
//     vector<vector<int>> t(m+1, vector<int>(n+1));
        
//     for(int i = 0; i<m+1; i++) {
//         for(int j = 0; j<n+1; j++) {
//             if(i == 0 || j == 0)
//                 t[i][j] = 0;
//             else if(text1[i-1] == text2[j-1])
//                 t[i][j] = 1 + t[i-1][j-1];
//             else
//                 t[i][j] = max(t[i][j-1], t[i-1][j]);
//         }
//     }     
//     return t[m][n];
// }



// ▶️ Approach-3 (Bottom Up space optmized)

// 👉 Since, in bottm up approach, we are using results of only two rows, t[i] and t[i-1]. So, we can take only two rows.

// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(n)


int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();   
    vector<vector<int>> t(2, vector<int>(n+1));
    for(int i = 0; i<m+1; i++) {
        for(int j = 0; j<n+1; j++) {
            if(i == 0 || j == 0)
                t[i%2][j] = 0;
            else if(text1[i-1] == text2[j-1])
                t[i%2][j] = 1 + t[(i+1)%2][j-1];
            else
                t[i%2][j] = max(t[i%2][j-1], t[(i+1)%2][j]);
        }
    }
    return t[m%2][n];
}


int main()
{
    string text1 = "abcde";
    string text2 = "ace" ;
    int ans = longestCommonSubsequence(text1,text2);
    cout << "ans is : " << ans << endl;
    return 0;
}
