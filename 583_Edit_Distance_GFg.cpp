#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | Goldman Sachs | Google

int editDistance(string str1, string str2) {
    int n=str1.length(),m=str2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }
    }
    return dp[n][m];
}

// ⏲️ Expected Time Complexity: O(|str1|*|str2|)
// 🛢️ Expected Space Complexity: O(|str1|*|str2|)

int main()
{
    string str1 = "geek";
    string str2 = "gesek";
    int ans = editDistance(str1,str2);
    cout << "ans is : " << ans << endl;
    return 0;
}
