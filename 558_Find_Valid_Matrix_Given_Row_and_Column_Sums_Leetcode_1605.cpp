#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Facebook, Uber, Google, Microsoft ✯  

// ▶️ Approach (Using simple Greedy)
// ⏲️ Time Complexity : O(m+n)
// 🛢️ Space Complexity : O(m*n) //You can exclude this because it is what is expected to return from the function


vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> vec(m, vector<int>(n));
        
    int i = 0, j = 0;
    while(i < m && j < n) {
        vec[i][j] = min(rowSum[i], colSum[j]);

        rowSum[i] -= vec[i][j];
        colSum[j] -= vec[i][j];

        if(rowSum[i] == 0) i++;
        if(colSum[j] == 0) j++;
            
    }
    return vec;
}

int main()
{
    vector<int> rowSum = {3,8};
    vector<int> colSum = {4,7};
    vector<vector<int>> ans = restoreMatrix(rowSum,colSum);
    for(int i=0; i< ans.size(); i++){
        for(int j=0; j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
