#include<iostream>
#include<vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if(n == 2){
        return min(cost[0],cost[1]);
    }
    for(int i = 2; i<n; i++){
        cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
    }
    return 0 + min(cost[n-1], cost[n-2]);
}

// ⏲️ Time cpmplexity O(n)

int main()
{
    vector<int> cost {10,15,20};
    int ans = minCostClimbingStairs(cost);
    cout << "ans is : " << ans << endl;
    return 0;
}
