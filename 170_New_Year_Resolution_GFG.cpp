#include<iostream>
#include<vector>
using namespace std;

int solve(int i,int N,int coins[],int sum,vector<vector<int>> &dp){
        if(sum==2024) return 1;
        if(sum!=0 and (sum%20==0 || sum%24==0)){
            return 1;
        }
        if(i>=N){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take   = solve(i+1,N,coins,sum+coins[i],dp);
        int notake = solve(i+1,N,coins,sum,dp);
        return dp[i][sum]=take || notake;
    }
    
int isPossible(int N , int coins[]) 
{
    int sum=0;
    for(int i=0;i<N;i++) sum+=coins[i];
    vector<vector<int>> dp(N,vector<int>(sum+1,-1));
    return solve(0,N,coins,0,dp);
}


// ⏲️ Expected Time Complexity: O(N*(Sum of coins))
// 🛢️ Expected Auxiliary Space: O(N*(Sum of coins))


int main()
{
    int N = 8;
    int coins[] = {5, 8, 9, 10, 14, 2, 3, 5};
    int ans = isPossible(N,coins);
    cout<< "ans is : "<< ans << endl;
    return 0;
}
