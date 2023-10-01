#include<iostream>
#include<vector>
using namespace std;


vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
{
        vector<int> ans;
        int startRow = 0;
        int startCol = 0;
        int endRow = n-1;
        int endCol = m-1;
    
        for(int i=0; i<m;i++){
            ans.push_back(matrix[startRow][i]);
        }
        startRow++;
    
        for(int i=1; i<n;i++){
            ans.push_back(matrix[i][endCol]);
        }
        endCol--;
    
        if(endRow >=startRow){
            for(int i=m-2; i>=0;i--){
            ans.push_back(matrix[endRow][i]);
        }
        endRow--;
        }
    
        if(startCol <=endCol){
            for(int i=n-2; i>=1;i--){
            ans.push_back(matrix[i][startCol]);
        }
        startCol++;
        }
    return ans;
}


int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int> > matrix {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15,16}};
    vector<int> ans = boundaryTraversal(matrix,n,m);

    for(int i=0; i<ans.size();i++){
        cout << ans[i] << " " ;
    }
    cout<< endl;
    return 0;
}
