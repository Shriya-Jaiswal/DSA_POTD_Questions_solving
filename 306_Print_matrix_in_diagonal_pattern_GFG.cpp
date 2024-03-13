#include <iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

vector<int> matrixDiagonally(vector<vector<int>>&mat){
    //Your code here
    vector<int>ans;
    int row=0, col=0;
    int n=mat.size();
         
    while(ans.size()<n*n){
        // going upward diagonally till my first row or my last column is reached    //
        while(row>=0 && col<n){
            if(row>=0 && col>=0 && row<n && col<n){
                ans.push_back(mat[row][col]);
                mat[row][col]=1e9;
            }
            row--;
            col++;
        }
        if(ans.size()==n*n){
            break;
        }
            
        row=max(row, 0);
        col=min(col, n-1);
            
        while(mat[row][col]==1e9){
            row++;
        }
            
        // going diagonally downwards
           while(col>=0 && row<n){
            if(row>=0 && col>=0 && row<n && col<n){
                ans.push_back(mat[row][col]);
                mat[row][col]=1e9;
            }
            row++;
            col--;
        }
        if(ans.size()==n*n){
            break;
        }
            
        row=min(row, n-1);
        col=max(col, 0);
            
        while(mat[row][col]==1e9){
            col++;
        }
            
            
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    vector<int> ans = matrixDiagonally(mat);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
