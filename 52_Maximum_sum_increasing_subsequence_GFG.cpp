#include<iostream>
#include<vector>
using namespace std;

int maxSumIS(int arr[], int n)  
{  
	vector<int> dp(arr,arr+n);
    int ans = dp[0];
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i],dp[j]+arr[i]);
            }
        }
        ans = max(ans,dp[i]);
    } 
    return ans;
}  

// ⏲️ Time Complexity ---> Expected Time Complexity: O(N2)
// 🛢️ Space complexity ---> Expected Auxiliary Space: O(N)

int main()
{
    int arr[] = {1, 101, 2, 3, 100};
    int N = 5; 
    int ans =maxSumIS(arr,N);
    cout<< "ans is : " << ans << endl;
    return 0;
}
