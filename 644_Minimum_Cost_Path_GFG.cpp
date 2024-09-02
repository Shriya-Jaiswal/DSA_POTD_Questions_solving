#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | Samsung | MakeMyTrip | Goldman Sachs

int minimumCostPath(vector<vector<int>>& grid) 
{
    int n = grid.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
    dis[0][0]=grid[0][0];
    pq.push({grid[0][0],{0,0}});
    int dirX[] = {-1,1,0,0};
    int dirY[] = {0,0,-1,1};
    while(pq.size()){
        auto temp = pq.top();
        pq.pop();
        int d = temp.first;
        for(int k=0;k<4;k++){
            int i = temp.second.first+dirX[k];
            int j = temp.second.second+dirY[k];
            if(i<n and j<n and i>=0 and j>=0 and d+grid[i][j]<dis[i][j]){
                dis[i][j]=d+grid[i][j];
                pq.push({d+grid[i][j],{i,j}});
            }
        }
    }
    return dis[n-1][n-1];
}

// ⏲️ Expected Time Complexity: O(n2*log(n))
// 🛢️ Expected Auxiliary Space: O(n2) 

int main()
{
    vector<vector<int>> grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}};
    int ans = minimumCostPath(grid);
    cout << "ans is : " << ans << endl;
    return 0;
}
