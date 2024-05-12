#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Google ✯  

// ▶️ Approach(Simply traversing and finding the result)
// ⏲️ Time Complexity : O(n*n)
// 🛢️ Space Complexity : O(n*n) for thr result but you can ignore it because it's the result that we have to return

int findLocalMax(vector<vector<int>>& grid, int x, int y) {
    int maxElement = 0;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            maxElement = max(maxElement, grid[i][j]);
        }
    }
    return maxElement;
}
    
vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            maxLocal[i][j] = findLocalMax(grid, i, j);
        }
    }
    return maxLocal;
}

int main()
{
    vector<vector<int>>  grid = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>> ans = largestLocal(grid);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
