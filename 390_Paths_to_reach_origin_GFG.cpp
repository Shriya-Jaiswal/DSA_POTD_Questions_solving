#include<iostream>
#include<vector>
using namespace std;


int mod=1e9+7;
int solve(int x, int y, vector<vector<int>>&dp){
    if(x==0 && y==0) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
        
    int left=0,up=0;
    if(y>0){
        left=solve(x,y-1,dp)%mod;
    }
    if(x>0){
        up=solve(x-1,y,dp)%mod;
    }
        
    return dp[x][y] = (left+up)%mod;
}

int ways(int x, int y)
{
    vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
    return solve(x,y,dp);
}

// ⏲️ Expected Time Complexity: O(x*y).
// 🛢️ Expected Auxiliary Space: O(x*y).

int main()
{
    int x = 3;
    int y = 0 ;

    int ans = ways(x,y);
    cout << "ans is : " << ans << endl;
    return 0; 
}
