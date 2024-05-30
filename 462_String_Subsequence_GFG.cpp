#include<iostream>
#include <vector>
using namespace std;

// ▶️ Ask by : Accolite

int MOD=1e9+7;
int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp)
{
    if(j<0)
        return 1;
    if(i<0)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    if(s1[i]==s2[j])
        return dp[i][j] =(solve(s1, s2, i-1, j-1, dp)%MOD +solve(s1, s2, i-1, j, dp)%MOD)%MOD;
    else
        return dp[i][j]=solve(s1, s2, i-1, j, dp)%MOD;
}


int countWays(string s1, string s2) {
    int n=s1.length(), m=s2.length();
    if(m>n)
        return 0;
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    return solve(s1, s2, n-1, m-1, dp);
}

// ⏲️ Expected Time Complexity: O(n*m)  [n and m are lengths of the strings s1 and s2]
// 🛢️ Expected Auxiliary Space: O(n*m)     [n and m are lengths of the strings s1 and s2]

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "gks";

    int ans = countWays(s1,s2);
    cout << "ans is : " << ans << endl;
    return 0;
}

