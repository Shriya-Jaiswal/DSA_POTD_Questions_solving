#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Flipkart | Morgan Stanley | Amazon | Microsoft | Snapdeal | Oracle | Payu | Visa | Directi | GreyOrange | Mobicip

int help(int n,int w,vector<int> &wt,vector<int> &val,int index,vector<vector<int>> &dp){
    if(index==n)return 0;
    if(dp[index][w]!=-1)return dp[index][w];
    int nonPick = 0, pick = 0;
    nonPick = help(n,w,wt,val,index+1,dp);
    if(w>=wt[index]){
        pick = val[index]+help(n,w-wt[index],wt,val,index+1,dp);
    }
    return dp[index][w] = max(nonPick,pick);
}
// 👉 Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, vector<int>& wt, vector<int>& val){
    int n = wt.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return help(n,W,wt,val,0,dp);
}

// 👉 Expected Time Complexity: O(N*W).
// 🛢️ Expected Auxiliary Space: O(N*W)

int main()
{
    int  W = 4;
    vector<int> val = {1,2,3};
    vector<int> wt = {4,5,1};

    int ans = knapSack(W,wt,val);
    cout << "ans is : " << ans << endl;
    return 0;
}
