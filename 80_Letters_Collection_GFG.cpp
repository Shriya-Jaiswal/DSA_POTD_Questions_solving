#include<iostream>
#include<vector>
using namespace std;


vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
{
    vector<int> ans;
        for (int i = 0; i < q; i++) {
            int hop = queries[i][0];
            int r = queries[i][1];
            int c = queries[i][2];
            if (hop == 1) {
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
                int sum = 0;
                for (int j = 0; j < 8; j++) {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            } else {
                int dx[] = {-2, -2, 2, 2, -2, 2, 0, 0, -2, -2, 2, 2, -1, 1, -1, 1};
                int dy[] = {-2, 2, -2, 2, 0, 0, -2, 2, -1, 1, -1, 1, -2, -2, 2, 2};
                int sum = 0;
                for (int j = 0; j < 16; j++) {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            }
        }
        return ans;
}

// ⏲️ Time complexity :  Expected Time Complexity: O(q)
// 🛢️ space complexity : Expected Auxiliary Space: O(q)

int main()
{
    int n = 4;
    int m = 5;
    vector<vector<int>> mat = {{1, 2, 3, 4, 10}, 
                               {5, 6, 7, 8, 10}, 
                               {9, 1, 3, 4, 10}, 
                               {1, 2, 3, 4, 10}};
    int q = 2;
    vector<vector<int>> queries = {{1, 0, 1}, 
                                   {2, 0, 1}};

    // vector<int> ans = matrixSum(n,m,mat,q,queries);
    // for(int i=0; i<ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return 0;
}
