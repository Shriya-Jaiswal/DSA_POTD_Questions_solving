#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Flipkart

int longestSubseq(int n, vector<int> &a) {
    vector<int>dp(n,0);
        
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int maxi=0;
        for(int j=i+1;j<n;j++){
            if(abs(a[i]-a[j])==1){
                maxi=max(maxi, dp[j]);
            }
        }
        dp[i]=1+maxi;
        ans=max(ans, dp[i]);
    }
    return ans;   
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 7;
    vector<int> a = {10, 9, 4, 5, 4, 8, 6};
    int ans = longestSubseq(n,a);
    cout << "ans is : " << ans << endl;
    return 0;
}
