#include<iostream>
#include<vector>
using namespace std;

vector<int> snakePattern(vector<vector<int> > matrix)
{   
    vector<int> ans;
    int n = matrix.size();

    for(int i=0; i<n; i++){
        if(i%2==0){
            for(int j=0; j<n; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{45, 48, 54},
                                  {21, 89, 87},
                                  {70, 78, 15}};

    vector<int> ans = snakePattern(matrix);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
