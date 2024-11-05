#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | Zoho | Morgan Stanley | Amazon | Microsoft | Samsung | Snapdeal | D-E-Shaw

void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    int n = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1 , 2 ,3}, {4, 5, 6}, {7, 8, 9}};
    rotate(mat);
    for(int i = 0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
