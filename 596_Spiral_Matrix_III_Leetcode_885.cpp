#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Tesla ✯   Google, Meta

// ▶️ Simple SImulation
// ⏲️ Time Complexity : O(max(rows,cols)^2)
// 🛢️ Space Complexity : O(1) (I am not considering the result matrix we have to return as result)

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> directions =  {
                                            {0, 1},  //EAST
                                            {1, 0},  //SOUTH
                                            {0, -1}, //WEST
                                            {-1, 0}  //NORTH
                                          };
        
    vector<vector<int>> result;  
    int step = 0; //how much steps to move
    int dir  = 0; //Which direction

    result.push_back({rStart, cStart});

    while (result.size() < rows * cols) {
        // 👉 When we move EAST or WEST, we need to increase our steps by 1
        if (dir == 0 || dir == 2) step++;

        for (int i = 0; i < step; i++) {
            rStart += directions[dir][0];
            cStart += directions[dir][1];

            if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) // check valid
                result.push_back({rStart, cStart});
        }

        dir = (dir + 1) % 4; // 👉 turn to next direction
    }
    return result;
}

int main()
{
    int rows = 1;
    int cols = 4;
    int rStart = 0;
    int cStart = 0;
    vector<vector<int>> ans = spiralMatrixIII(rows,cols,rStart,cStart);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
