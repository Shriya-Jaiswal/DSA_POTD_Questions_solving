#include<iostream>
#include<cstring>
using namespace std;

// ▶️ Ask by Microsoft

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return (m+n-dp[m][n]);
}

// ⏲️ Expected Time Complexity: O(Length(X) * Length(Y)).
// 🛢️ Expected Auxiliary Space: O(Length(X) * Length(Y)).


int main()
{
    string X = "abcd";
    string Y = "xycd";

    // 👉 m, and n as arguments and returns the length of the required string.
    int m = 4;
    int n = 4;
    int ans = shortestCommonSupersequence(X,Y,m,n);
    cout << "ans  is : " << ans << endl;
    return 0;
}
