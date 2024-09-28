#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// ▶️ Ask by : NOne

int help(int i,int k,vector<int> &arr, vector<int> &dp){
    if(i==arr.size()-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans = INT_MAX;
    for(int j=i+1;j<=i+k and j<arr.size();j++){
        int cost = abs(arr[i]-arr[j])+help(j,k,arr,dp);
        ans=min(ans,cost);
    }
    return dp[i] = ans;
}
int minimizeCost(int k, vector<int>& arr) {
    vector<int> dp(arr.size(),-1);
    return help(0,k,arr,dp);
}

// ⏲️ Expected Time Complexity: O(n*k)
// 🛢️ Expected Auxilary Space: O(n)

int main()
{
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};
    int ans = minimizeCost(k,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
