#include<iostream>
#include<vector>
using namespace std;

void booleanMatrix(vector<vector<int> > &matrix)
{
    int numberOfRows = matrix.size();
    int numberOfCols = matrix[0].size();
    vector<int>rows(numberOfRows);
    vector<int>cols(numberOfCols);

    for(int i=0; i<numberOfRows; i++){
        for(int j=0; j<numberOfCols;j++){
            if(matrix[i][j] == 1){
                rows[i] =1;
                cols[j] = 1;
            }
        }
    }

    for(int i=0; i<numberOfRows;i++){
        for(int j=0; j<numberOfCols;j++){
            if(rows[i] == 1 || cols[j] == 1){
                matrix[i][j] = 1;
            }
        }
    }
}
// ⏲️ Time complexity O(R X C) + O(R X C)
// 🛢️ sapce complexity O(R) + O(C) ===> O(R+C);

int main()
{
    // int R = 2;  // 👈 represent row
    // int C = 2;  // 👉 represent column
    vector<vector<int>> matrix {{1, 0},{0, 0}};
    booleanMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
