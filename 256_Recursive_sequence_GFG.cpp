#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : MAQ Software

long long sequence(int n){
    long long ans=1;
    int mod=1e9+7;
    int k=2;
    for(int i=2;i<=n;i++){
        long long t=1;
        for(int j=1;j<=i;j++){
            t=(t*k)%mod;
            k++;
        }
            ans= (ans+t)%mod;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    int n = 5;
    long long ans = sequence(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
