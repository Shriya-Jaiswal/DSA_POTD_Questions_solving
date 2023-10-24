#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// ▶️ GFG Hard

bool isPalindrome(int i, int j, string &s){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string &s, vector<int> &dp ){
    if(i==n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    int minCost = INT_MAX;

    for(int j=i; j<n;j++){
        if(isPalindrome(i,j,s)){
            int cost = 1 + solve(j+1,n,s,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i] = minCost;
}

int palindromicPartition(string str){
    int n = str.size();
    vector<int> dp(n,-1);
    return solve(0,n,str,dp)-1;
}

// ⏲️ Time Complexity :  Expected Time Complexity: O(n*n) [n is the length of the string str]
// 🛢️ space complexity :  Expected Auxiliary Space: O(n*n)

int main()
{
    string str = "ababbbabbababa";
    int ans = palindromicPartition(str);
    cout<< "ans is : " << ans << endl;
    return 0;
}
