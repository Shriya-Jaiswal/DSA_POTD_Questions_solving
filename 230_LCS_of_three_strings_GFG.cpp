#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : DE Shaw

int dp[21][21][21];
int solve(string A, string B, string C, int i,int j, int k){
    if(i<0 || j<0 || k<0){
        return 0;
    }
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(A[i]==B[j] && B[j]==C[k]){
        return dp[i][j][k]=1+solve(A,B,C,i-1,j-1,k-1);
    }
    else{
        return dp[i][j][k]=max(solve(A,B,C,i-1,j,k),max(solve(A,B,C,i,j-1,k),solve(A,B,C,i,j,k-1)));
    }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    return solve(A,B,C, n1-1, n2-1, n3-1);         
}

// ⏲️ Expected Time Complexity: O(n1*n2*n3).
// 🛢️ Expected Auxiliary Space: O(n1*n2*n3).

int main()
{
    string A = "geeks";
    string B = "geeksfor";
    string C = "geeksforgeeks";
    int n1 = 5;
    int n2 = 8;
    int n3 = 13;
    int ans = LCSof3(A,B,C,n1,n2,n3);
    cout << "ans is : " << ans << endl;

    return 0;
}
