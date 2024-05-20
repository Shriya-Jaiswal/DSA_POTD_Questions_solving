#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Google

long long int PowMod(long long int x,long long int n,long long int M)
{
	if(n==0) return 1;
	if(n==1) return x;
		    
	long long val= PowMod(x, n/2, M);
	val=(val*val)%M;
		    
	if(n%2==1){
		return (val*x)%M;
	}
		    
	return val;
}


// ⏲️ Expected Time Complexity: O(log(n))
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    long long int x = 3;
    long long int n = 2;
    long long int m = 4;

    long long int ans = PowMod(x,n,m);
    cout << "ans is : " << ans << endl;
    return 0;
}
 