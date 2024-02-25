#include<iostream>
#include<vector>
using namespace std;

long long int count(long long int n){
    	vector<long long>v(n+1, 0);
    	v[0]=1;
    	for(int i=3;i<=n;i++){
    	    v[i]+=v[i-3];
    	}
    	for(int i=5;i<=n;i++){
    	    v[i]+=v[i-5];
    	}
    	for(int i=10;i<=n;i++){
    	    v[i]+=v[i-10];
    	}
    	return v[n];   	
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    long long int n = 10;
    long long int ans = count(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
