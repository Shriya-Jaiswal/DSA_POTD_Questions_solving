#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int solveUsingRec(vector<int>&nums1, vector<int>&nums2, int i, int j){
    int option1 = 0;
    int option2 = 0;
    int option3 = 0;

    if(i==0 || j==0){
        return 0;
    }

    // 👉 Try including the nums1's element and nums2's element from in the res
    option1 = max(option1,nums1[i-1]*nums2[j-1]+ solveUsingRec(nums1,nums2,i-1,j-1));

    // 👉 Not including the nums1 element to the answer
    if(j>1){
        option2 = max(option2,solveUsingRec(nums1,nums2,i,j-1));
    }
    // 👉 Not including the nums2 element to the answer
    if(i>1){
        option3 = max(option3,solveUsingRec(nums1,nums2,i-1,j));
    }
    return max({option1,option2,option3});
}


vector<vector<int>> dp;
int solveUsingMem(vector<int>&nums1, vector<int>&nums2, int i, int j){
    if(i==0 || j==0){
        return 0;
    }

    if(dp[i][j] != INT_MIN){
        return dp[i][j];
    }

    // 👉 Try including the nums1's element and nums2's element from in the res
    dp[i][j] = nums1[i-1]*nums2[j-1]+ max(solveUsingMem(nums1,nums2,i-1,j-1),0);

    // 👉 Not including the nums1 element to the answer
    if(j>1){
        dp[i][j] = max(dp[i][j],solveUsingMem(nums1,nums2,i,j-1));
    }
    // 👉 Not including the nums2 element to the answer
    if(i>1){
        dp[i][j] = max(dp[i][j],solveUsingMem(nums1,nums2,i-1,j));
    }
    return dp[i][j];
}



int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    // return solveUsingRec(nums1,nums2,nums1.size(),nums2.size());
    dp.resize(nums1.size()+1, vector<int>(nums2.size()+1,INT_MIN));
    return solveUsingMem(nums1,nums2,nums1.size(),nums2.size());
}


const int INF = 10e7;
int maxDotProductBottomUp(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-INF)); // as range is of negative numbers too thus 0 or -1

    for(int i =1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max({
                nums1[i-1] * nums2[j-1],
                dp[i-1][j-1] + nums1[i-1]*nums2[j-1],
                dp[i-1][j],
                dp[i][j-1]
            });
        }
    }
    return dp[n][m];
}


int main()
{
    vector<int> nums1 {2,1,-2,5};
    vector<int> nums2 {3,0,-6};
    int ans = maxDotProduct(nums1,nums2);
    cout<< ans << endl;
    return 0;
}
