#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Morgan Stanley | Amazon | Intel

int nthPoint(int n){
	int mod=1e9+7;
	if(n==1) return 1;
	if(n==2) return 2;
	int f=1;
	int s=2;
	for(int i=3;i<=n;i++){
		int t=(f+s)%mod;
		f=s;
		s=t;
	}
	return s;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Space Complexity: O(N)

int main()
{
    int n = 4;
    int ans = nthPoint(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
