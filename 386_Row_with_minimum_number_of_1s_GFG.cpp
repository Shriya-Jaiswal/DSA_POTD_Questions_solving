#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// ▶️ Ask by : Amazon

int minRow(int n, int m, vector<vector<int>> a) {
    int ans=-1, mini=INT_MAX;
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                curr++;
            }
        }
        if(curr<mini){
            mini=curr;
            ans=i+1;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity:O(n*m)
// 🛢️ Expected Auxillary Space:O(1)


int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> a = {{1, 1, 1, 1},
                            {1, 1, 0, 0}, 
                            {0, 0, 1, 1},
                            {1, 1, 1, 1}};

    int ans = minRow(n,m,a);
    cout << "ans is : " << ans << endl;
    return 0;
}
