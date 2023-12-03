#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon ✯   Bloomberg ✯   Facebook ✯   Media.net ✯   Apple ✯  

// ▶️ Simple Math (Geometry)
// ⏲️ Time Complexity : O(n) - Checking all n points
// 🛢️ Space Complexity : O(1)
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();
    int steps = 0;
    for(int i = 0; i<n-1; i++) { //We have to reach the last point - points[n-1]
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[i+1][0];
        int y2 = points[i+1][1]; 
        int dx = abs(x2-x1);
        int dy = abs(y2-y1);
        int diagonal = min(dx, dy);
        int remain   = abs(dx-dy);
        steps += diagonal + remain;   
    }
    return steps;        
}

int main()
{
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    int ans = minTimeToVisitAllPoints(points);
    cout << "ans is : " << ans << endl;
    return 0;
}
