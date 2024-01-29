#include<iostream>
#include<vector>
using namespace std;

int solve(int ind, int sum, string &str, int n, vector<vector<int>>&dp){
	if(ind==n) return 1;
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	int ans=0, curr=0;
	for(int i=ind;i<n;i++){
	    curr+=str[i]-'0';
	    if(curr>=sum){
	        ans+=solve(i+1, curr, str, n, dp);
	    }
	}
	return dp[ind][sum]=ans;
}
	
int TotalCount(string str){
	int n=str.length();
	vector<vector<int>>dp(n+1, vector<int>(9*n+1,-1));
	return solve(0, 0, str, n,dp);
}


// Expected Time Complexity: O(N3) where N is the length of the string.
// Expected Space Complexity: O(N2)

int main()
{
    string str = "1119";
    int ans = TotalCount(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
