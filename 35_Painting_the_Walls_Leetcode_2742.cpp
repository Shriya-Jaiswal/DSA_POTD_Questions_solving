#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int solveUsingRec(int idx, int remain, vector<int> & cost, vector<int> & time){
    if(remain <= 0){
        return 0 ; // 👉 no cost
    }

    if(idx >= n){
        return 1e9; // 👉 invalid case 
    }

    int paintIdx = cost[idx] + solveUsingRec(idx+1, remain- 1 - time[idx], cost, time);
    int noPaint = solveUsingRec(idx+1, remain, cost, time);

    return min(paintIdx,noPaint);
}


int dp[501][501];
int solveUsingMem(int idx, int remain, vector<int> & cost, vector<int> & time){
    if(remain <= 0){
        return 0 ; // 👉 no cost
    }

    if(idx >= n){
        return 1e9; // 👉 invalid case 
    }

    if(dp[idx][remain] != -1){
        return dp[idx][remain];
    }
    int paintIdx = cost[idx] + solveUsingMem(idx+1, remain- 1 - time[idx], cost, time);
    int noPaint = solveUsingMem(idx+1, remain, cost, time);

    return dp[idx][remain] =  min(paintIdx,noPaint);
}



int paintWalls(vector<int>& cost, vector<int>& time) {
    n = cost.size();
    // return solveUsingRec (0,n,cost,time);

    memset(dp,-1,sizeof(dp));
    return solveUsingMem (0,n,cost,time);
}

int main()
{
    vector<int> cost {1,2,3,2};
    vector<int> time {1,2,3,2};

    int ans = paintWalls(cost,time);
    cout<< "ans is : " << ans << endl;
    return 0;
}
