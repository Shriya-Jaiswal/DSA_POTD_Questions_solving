#include<iostream>
#include<vector>
using namespace std;

long long modPow(long long base, int exp, int mod){
        long long result = 1;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }


 long long modInverse(long long a, int m){
            return modPow(a,m-2,m);
}
    

long long  numberOfPaths(int M, int N)
    {
        const int MOD = 1000000007;

        int n = M + N - 2;
        int r = M -1;
        long long ans = 1; // 👉 use long long to prevent integer overflow
    
        // 👉 calculate in choose r % Mod
        for(int i =1; i<=r; i++){
            ans = (ans * (n - i + 1)) % MOD;
            ans = (ans * modInverse(i,MOD)) % MOD;
        }
        return (ans);
    }
    

// ⏲️ Time Complexity :  Expected Time Complexity: O(M)
// 🛢️ space complexity :  Expected Space Complexity: O(1)

int main()
{
    int M = 3 ;
    int N = 3;

    long long ans = numberOfPaths(M,N);
    cout << "ans is : " << ans << endl;
    return 0;
}
