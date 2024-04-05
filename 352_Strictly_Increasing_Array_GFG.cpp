#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

int LIS(vector<int>&arr){
    int n=arr.size();
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && arr[i]-arr[j]>=i-j){
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
    }
    int maxi=0;
    for(auto it:dp){
        maxi=max(maxi, it);
    }
    return maxi;
}

int min_operations(vector<int>& nums) {
    int l=LIS(nums);
    int n=nums.size();
    return n-l;
}

int main()
{
    int n = 6;
    vector<int> nums = {1, 2, 3, 6, 5, 4};
    int ans = min_operations(nums);
    cout << "ans is : " << ans << endl; 
    return 0;
}
