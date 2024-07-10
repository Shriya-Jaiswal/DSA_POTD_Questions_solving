#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | Samsung

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            if(mat[i][j] == 1 && i-1 >= 0 && j-1>=0){
                mat[i][j] = min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]})+1;
            }
            res = max(res,mat[i][j]);
        }
    }
    return res;
}


// ⏲️ Expected Time Complexity: O(n*m)
// 🛢️ Expected Auxiliary Space: O(n*m)

int main()
{
    int n = 6;
    int m = 5;
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, 
                                {1, 1, 0, 1, 0},
                                {0, 1, 1, 1, 0},
                                {1, 1, 1, 1, 0},
                                {1, 1, 1, 1, 1},
                                {0, 0, 0, 0, 0}};

    int ans = maxSquare(n,m,mat);
    cout << "ans is : " << ans << endl;
    return 0;
}
