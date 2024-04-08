#include<iostream>
#include<vector>
using namespace std;


long long solve(int arr[], int left, int right, vector<vector<long long>>&dp){
    if(left>right) return 0;
    if(left==right) return arr[left];
    if(dp[left][right]!=-1) return dp[left][right];
        
    long long l=arr[left]+min(solve(arr, left+2, right, dp), solve(arr, left+1, right-1,dp));
    long long r=arr[right]+min(solve(arr, left, right-2, dp), solve(arr, left+1, right-1,dp));
        
    return dp[left][right] = max(l,r);
}
    
long long maximumAmount(int n, int arr[]){
    vector<vector<long long>>dp(n+1, vector<long long>(n+1, -1));
    long long ans=solve(arr, 0, n-1, dp);
    return ans;
}

// ⏲️ Expected Time Complexity : O(n*n)
// 🛢️ Expected Auxiliary Space: O(n*n)

int main()
{
    int n = 4;
    int arr[] = {5, 3, 7, 10};
    long long ans = maximumAmount(n,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
