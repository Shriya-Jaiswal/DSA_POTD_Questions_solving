#include<iostream>
using namespace std;

// ▶️ Ask by : Flipkart | Morgan Stanley | Microsoft | Snapdeal

#define ll long long
int mod = 1e9+7;

ll countStrings(int n) {
	ll f=1;
    ll s=2;
        
    for(int i=2;i<=n;i++){
    ll t=(f+s)%mod;
        f=s;
        s=t;
    }
    return s;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(N)

int main()
{
    int n = 3;
    long long ans = countStrings(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
