#include<iostream>
using namespace std;

// ▶️ Ask by : Bajaj

// 📓 Topic : Arrays, DP

long long countWays(int n, int k){
    long long total = k, same = 0, diff = k, mod = 1e9 + 7;
    for(int i = 2; i <= n; i++){
        same = diff;
        diff = (total%mod*(k - 1)%mod)%mod;
        total = (same + diff)%mod;
    }
    return total;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(N).

int main()
{
    int n = 3;
    int k = 2 ;
    long long ans  = countWays(n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
