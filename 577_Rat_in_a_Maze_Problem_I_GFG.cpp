#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft

void help(vector<vector<int>> &matrix,int n,int i,int j,vector<string> &ans,string temp){
    if(i<0 or j<0 or i==n or j==n or matrix[i][j]==0)return;
    if(i==n-1 and j==n-1){
        ans.push_back(temp);
        return;
    }
    matrix[i][j]=0;
    help(matrix,n,i+1,j,ans,temp+'D');
    help(matrix,n,i-1,j,ans,temp+'U');
    help(matrix,n,i,j+1,ans,temp+'R');
    help(matrix,n,i,j-1,ans,temp+'L');
    matrix[i][j]=1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    help(mat,mat.size(),0,0,ans,"");
    return ans;
}


// ⏲️ Expected Time Complexity: O(3n^2)
// 🛢️ Expected Auxiliary Space: O(l * x)

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    vector<string> ans = findPath(mat);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
