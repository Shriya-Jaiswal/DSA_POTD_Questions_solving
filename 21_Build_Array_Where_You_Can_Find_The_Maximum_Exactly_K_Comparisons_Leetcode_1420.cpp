#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// int N,M,K;
// int MOD = 1e9 + 7; 

// int solveUsingRec(int idx, int search_cost, int maxSoFar){
//     if(idx == N){
//         if(search_cost == K){
//             return 1;
//         }
//         return 0;
//     }

//     int result = 0;
//     for(int i=1; i<=M; i++){
//         if(i > maxSoFar){
//             result = (result + solveUsingRec(idx+1, search_cost+1, i)) % MOD;
//         }
//         else{
//             result = (result + solveUsingRec(idx+1, search_cost, maxSoFar)) % MOD;
//         }
//     }
//     return result % MOD;
// }

int N,M,K;
int MOD = 1e9+7; 
int dp[51][51][101];

int solveUsingMem(int idx, int searchCost, int maxSoFar){
    if(idx == N){
        if(searchCost == K){
            return 1;
        }
        return 0;
    }

    if(dp[idx][searchCost][maxSoFar] != -1){
        return dp[idx][searchCost][maxSoFar];
    }

    int result = 0;
    for(int i=1; i<=M; i++){
        if(i > maxSoFar){
            result = result + solveUsingMem(idx+1, searchCost+1, i);
        }
        else{
            result = result + solveUsingMem(idx+1, searchCost, maxSoFar);
        }
        result = result % MOD;
    }
    return dp[idx][searchCost][maxSoFar] = result % MOD;
}


int numOfArrays(int n, int m, int k) {
    N = n;       
    M = n;
    K = k;
    // return solveUsingRec(0,0,0);
    memset(dp,-1,sizeof(dp));
    return solveUsingMem(0,0,0);
}

int main()  
{
    
    return 0;
}
