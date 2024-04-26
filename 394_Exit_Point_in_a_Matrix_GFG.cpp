#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Samsung

vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
    pair<int,int> direction={0,1};
    int row=0, col=0;
    while(true){
        // cout<<matrix[row][col]<<" "<<row<<" "<<col<<" "<<direction.first<<" "<<direction.second<<endl;
        if(matrix[row][col]==1){
            if(direction.first==0 && direction.second==1){
                direction.first=1;
                direction.second=0;
            }
            else if(direction.first==1 && direction.second==0){
                direction.first=0;
                direction.second=-1;
            }
            else if(direction.first==0 && direction.second==-1){
                direction.first=-1;
                direction.second=0;
            }
            else if(direction.first==-1 && direction.second==0){
                direction.first=0;
                direction.second=1;
            }
            matrix[row][col]=0;
        }
            
        int nrow=row+direction.first;
        int ncol=col+direction.second;
            
        if(nrow>=n || nrow<0 || ncol>=m || ncol<0){
            return {row,col};   
        }
            
        row=nrow;
        col=ncol;
    }
}

// ⏲️ Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{0, 1, 0},
                                  {0, 1, 1}, 
                                  {0, 0, 0}};

    vector<int> ans = FindExitPoint(n,m,matrix);
    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
