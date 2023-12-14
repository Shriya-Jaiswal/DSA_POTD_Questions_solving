#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 


// ▶️ Approach - Keep count of ones and zeros in row/col
// ⏲️ Time Complexity : O(m*n)
// 🛢️ Space Complexity : O(m+n) -> Not considering the result space

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rowOnes(m, 0);
    vector<int> colOnes(n, 0);
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {           
            if(grid[i][j] == 1) {
                rowOnes[i]++;
                colOnes[j]++;
            } 
        }
    }
    vector<vector<int>> diff(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            int onesRowi = rowOnes[i];
            int onesColj = colOnes[j];
            int zerosRowi = n-onesRowi;
            int zerosColj = m-onesColj;           
            diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
        }
    }
    return diff;    
}

int main()
{
    vector<vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
    vector<vector<int>> ans = onesMinusZeros(grid);
    // for(int i = 0 ; i< ans.size(); i++){
    //     for(int j = 0; j< ans[i]; j++){
    //         cout<< ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
