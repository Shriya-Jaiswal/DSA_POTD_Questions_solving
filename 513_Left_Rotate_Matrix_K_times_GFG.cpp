#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
    int n=mat.size(), m=mat[0].size();
    vector<vector<int>>ans(n, vector<int>(m,0));
    k%=m;
    if(k==0) return mat;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=k;j<m;j++,x++){
            ans[i][x]=mat[i][j];
        }
        for(int j=0;j<k;j++,x++){
            ans[i][x]=mat[i][j];
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*m)
// 🛢️ Expected Auxillary Space: O(n*m)

int main()
{
    int k=1;
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = rotateMatrix(k,mat);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size();j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
