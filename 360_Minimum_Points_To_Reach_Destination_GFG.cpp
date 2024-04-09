#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

int minPoints(int m, int n, vector<vector<int>> arr) {     
	int ans[m][n];
	ans[m-1][n-1] = arr[m-1][n-1] > 0? 1: 
	                abs(arr[m-1][n-1]) + 1; 
	  
	for (int i = m-2; i >= 0; i--) 
	        ans[i][n-1] = max(ans[i+1][n-1] - arr[i][n-1], 1); 
	for (int j = n-2; j >= 0; j--) 
	        ans[m-1][j] = max(ans[m-1][j+1] - arr[m-1][j], 1); 
	   
	for (int i=m-2; i>=0; i--) 
	{ 
	    for (int j=n-2; j>=0; j--) 
	    {  
	        ans[i][j] = max(min(ans[i+1][j], ans[i][j+1])-arr[i][j], 1); 
	    } 
	    } 
	  
	    return ans[0][0]; 
} 

// ⏲️ Expected Time Complexity: O(n*m)
// 🛢️ Expected Auxiliary Space: O(n*m)

int main()
{
   int m = 3;
   int n = 3 ;
   vector<vector<int>> points = {{-2,-3,3}, 
                                {-5,-10,1},
                                {10,30,-5}} ;

    int ans = minPoints(m,n,points);
    cout << "asn is : " << ans << endl;

    return 0;
}
