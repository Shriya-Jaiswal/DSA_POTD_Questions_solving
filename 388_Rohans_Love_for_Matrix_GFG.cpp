#include<iostream>
#include<vector>
using namespace std;

int firstElement(int n) {
    if(n==0 || n==1) return 1;
    int a=1, b=1;
    int mod = 1000000007;
    int c;
    for(int i=0;i<n-2;i++){
        c=(a+b)%mod;
        a=b%mod;
        b=c%mod;
    }
    return c%mod;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int n = 3;
    int ans = firstElement(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
