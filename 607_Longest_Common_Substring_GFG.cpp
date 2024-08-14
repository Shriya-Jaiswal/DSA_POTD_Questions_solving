#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Morgan Stanley | Amazon | Microsoft

int longestCommonSubstr(string str1, string str2) {
    int n=str1.size();
    int m=str2.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)dp[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*m).
// 🛢️ Expected Auxiliary Space: O(n*m).


int main()
{
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";    
    int ans = longestCommonSubstr(str1,str2);
    cout << "ans is : " << ans << endl;
    return 0;
}
