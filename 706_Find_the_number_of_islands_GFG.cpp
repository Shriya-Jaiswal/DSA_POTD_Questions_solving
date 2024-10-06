#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | Flipkart | Amazon | Microsoft | OYO Rooms | Samsung | Snapdeal Citrix | D-E-Shaw | MakeMyTrip | Ola Cabs | Visa | Intuit | Google | Linkedin | Opera | One97 | Streamoid Technologies | Informatica
 
// Function to find the number of islands.
int n,m;
vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
void solve(vector<vector<char>>& grid,int i,int j){
    //base case
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
    grid[i][j]='0';
    for(auto &it:dir){
        int newi=i+it[0];
        int newj=j+it[1];
        solve(grid,newi,newj);
    }
        
}
int numIslands(vector<vector<char>>& grid) {
    // CodeGenius
    n=grid.size();
    m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                solve(grid,i,j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {{0,1},{1,0},{1,1},{1,0}};
    int ans = numIslands(grid);
    cout << "ans is : " << ans << endl;
    return 0;
}

