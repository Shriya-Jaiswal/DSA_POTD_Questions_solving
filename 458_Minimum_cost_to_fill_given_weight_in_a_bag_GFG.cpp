#include<iostream>
#include<vector>
using namespace std;

int solve(int ind, vector<int>& cost, int w, vector<vector<int>>&dp){
    if(w==0){
        return 0;
    }
    if(ind>=cost.size() || ind+1>w){
        return 1e9;
    }
        
    if(dp[ind][w]!=-1) return dp[ind][w];
        
    int a, b;
    if(cost[ind]!=-1 && ind+1<=w){
        a=cost[ind]+solve(ind, cost, w-(ind+1), dp);
    }
    b=solve(ind+1, cost, w, dp);
        
    return dp[ind][w]=min(a,b);
}
  
int minimumCost(int n, int w, vector<int> &cost) {
    vector<vector<int>>dp(n+1, vector<int>(w+1,-1));
    int ans=solve(0, cost, w, dp);
        
    if(ans>=1e9) ans=-1;
        
    return ans;
}


// ⏲️ Expected Time Complexity: O(n*w)
// 🛢️ Expected Auxiliary Space: O(n*w)

int main()
{
    int n = 5;
    vector<int> cost = {20, 10, 4, 50, 100} ;
    int w = 5;
    int ans = minimumCost(n,w,cost);
    cout << "ans is : " << ans << endl;
    return 0;
}
