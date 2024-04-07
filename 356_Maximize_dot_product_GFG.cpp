#include<iostream>
#include<cstring>
using namespace std;

// ▶️ Ask by : Directi

int maxDotProduct(int n, int m, int a[], int b[]) 
{ 
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
		    dp[i][j]=max(dp[i-1][j-1]+a[j-1]*b[i-1], dp[i][j-1]);
		}
	}
	return dp[m][n];
} 

// ⏲️ Expected Time Complexity: O(n*m)
// 🛢️ Expected Auxiliary Space: O(n*m)

int main(int argc, char const *argv[])
{
    int n = 5;
    int a[] = {2, 3, 1, 7, 8} ;
    int m = 3, b[] = {3, 6, 7};

    int ans = maxDotProduct(n,m,a,b);
    cout << "ans is : " << ans << endl;

    return 0;
}
