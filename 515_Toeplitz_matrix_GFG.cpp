#include<iostream>
#include<vector>
using namespace std;

bool isToeplitz(vector<vector<int>>& mat) {
    int n=mat.size(), m=mat[0].size();
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] != mat[i-1][j-1])  return false;
        }
    }
    return true;
}

// ⏲️ Expected time complexity: O(n*m)
// 🛢️ Expected space complexity: O(1)

int main()
{
   vector<vector<int>> mat = {{6, 7, 8},
                                {4, 6, 7},
                                {1, 4, 6}};
    bool ans = isToeplitz(mat);
    cout << "ans is : " << ans << endl;
    return 0;
}
