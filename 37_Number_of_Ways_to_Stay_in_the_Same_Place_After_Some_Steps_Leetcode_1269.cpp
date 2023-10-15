#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int MOD = 1e9+7;
int solveUsingRec(int idx, int steps){
    if(idx < 0  || idx >= n){
        return 0;
    }
    if(steps == 0){
        return idx ==0;
    }

    int result = solveUsingRec(idx+1,steps-1); // 👉 go to right
    result = (result + solveUsingRec(idx-1,steps-1)) % MOD; // 👉 :go to left

    result = (result + solveUsingRec(idx,steps-1)) % MOD; // 👉 stay here

    return result;
}

// ⏲️ time Complexity O(3^n) exponential time ---> here n is a length of array


// 👉 solve Using memoization
int dp[501][501];
int solveUsingMem(int idx, int steps){
    if(idx < 0  || idx >= n){
        return 0;
    }
    if(steps == 0){
        return idx ==0;
    }

    if(dp[idx][steps]  != -1){
        return dp[idx][steps];
    }

    int result = solveUsingMem(idx+1,steps-1); // 👉 go to right
    result = (result + solveUsingMem(idx-1,steps-1)) % MOD; // 👉 :go to left

    result = (result + solveUsingMem(idx,steps-1)) % MOD; // 👉 stay here

    return dp[idx][steps] = result;
}

// ⏲️ time Complexity O(arrlen * states) we can reduce ---> ⏲️ O(min(arrlen,states) * states)



int numWays(int steps, int arrLen) {
    // arrLen = min(arrLen,steps);
    // n = arrLen;

    // // // 1️⃣ solve using recursion
    // // return solveUsingRec(0,steps);     

    // // 2️⃣ solve using Memoization 
    // memset(dp,-1,sizeof(dp));   
    // return solveUsingMem (0,steps) ;

    // 3️⃣ more optimization
    arrLen = min(arrLen,steps/2+1);
    n = arrLen;
    memset(dp,-1,sizeof(dp));   
    return solveUsingMem (0,steps) ;

}

int main()
{
    int steps = 3;
    int arrLen = 2;
    int ans = numWays(steps,arrLen);
    cout<< "ans is : " << ans << endl;
    return 0;
}
