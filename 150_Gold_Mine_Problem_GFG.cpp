#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// ▶️ Ask by : Flipkart | Amazon | Samsung 

 int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=0;
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int mx=INT_MIN;
                if(i-1>=0 and j-1>=0)   mx = max(mx,M[i-1][j-1]);
                if(j-1>=0)              mx = max(mx,M[i][j-1]);
                if(i+1<n and j-1>=0)    mx = max(mx,M[i+1][j-1]);
                M[i][j]+=mx;
                ans=max(ans,M[i][j]);
            }
        }
        return ans;
    }

// ⏲️ Expected Time Complexity: O(n*m)
// 🛢️ Expected Auxiliary Space: O(n*m)

int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> M = {{1, 3, 3},
                            {2, 1, 4},
                            {0, 6, 4}};
    int ans = maxGold(n,m,M);
    cout << "ans is : " << ans << endl;
    return 0;
}
