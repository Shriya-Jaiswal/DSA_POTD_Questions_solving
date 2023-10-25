#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// ▶️ ▶️ 👉 this Question is also known as unbounded Knapsack 

int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W+1,0);
    vector<int>curr(W+1,0);

    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int)i/wt[0]) * val[0];
    }

    for(int index = 1; index<N; index++ ){
        for(int weight=0; weight<=W; weight++){
            int notTake = prev[weight];
            int take = INT_MIN;
            if(wt[index] <= weight){
                take = val[index] + curr[weight - wt[index]];
            }
            curr[weight] = max(notTake,take);
        }
        prev = curr;
    }
    return prev[W];
}

// ⏲️ Time complexity :  Expected Time Complexity: O(N*W)
// 🛢️ Space complexity :  Expected Auxiliary Space: O(W)

int main()
{
    int N = 2;
    int W = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};

    int ans = knapSack(N,W,val,wt);
    cout << "ans is : " << ans << endl;
    return 0;
}
