#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | OYO Rooms

int help(int n,int x,int y,int z,vector<int> &dp){
    if(n<0)return INT_MIN;
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = 1+max({help(n-x,x,y,z,dp),help(n-y,x,y,z,dp),help(n-z,x,y,z,dp)});
}
// 👉 Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n+1,-1);
    int ans = help(n,x,y,z,dp);
    return ans<0?0:ans;
}

// ⏲️ Expected Time Complexity : O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int  n = 4;
    int x = 2;
    int y = 1;
    int z = 1;
    int ans = maximizeTheCuts(n,x,y,z);
    cout << "ans is :" << ans << endl; 
    return 0;
}
