#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
    dist[0][0]=0;
    pq.push({0,{0,0}});
        
    while(!pq.empty()){
        int step=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
            
        pq.pop();
            
        if(row==n-1 && col==m-1){
            return step;
        }
            
        int nrow, ncol;
            
        nrow=row-1; ncol=col;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
            int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
            if(val<dist[nrow][ncol]){
                dist[nrow][ncol]=val;
                pq.push({val, {nrow,ncol}});
            }
        }
        nrow=row+1; ncol=col;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
            int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
            if(val<dist[nrow][ncol]){
                dist[nrow][ncol]=val;
                pq.push({val, {nrow,ncol}});
            }
        }
        nrow=row; ncol=col-1;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
            int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
            if(val<dist[nrow][ncol]){
                dist[nrow][ncol]=val;
                pq.push({val, {nrow,ncol}});
            }
        }
        nrow=row; ncol=col+1;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
            int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
            if(val<dist[nrow][ncol]){
                dist[nrow][ncol]=val;
                pq.push({val, {nrow,ncol}});
            }
        }
    }
    return dist[n-1][m-1];
        
}

// ⏲️ Expected Time Complexity: O(rowsxcolumns)
// 🛢️ Expected Space Complexity: O(rowsxcolumns)

int main()
{
    int row = 3;
    int columns = 3 ;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    int ans = MinimumEffort(row,columns,heights);
    cout << "ans is : " << ans << endl;
    return 0;
}
