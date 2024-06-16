#include<iostream>
#include<vector>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int>primes(n+1,1);
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<=n;i++){
        if(primes[i]==0) continue;
        for(int j=2;j*i<=n;j++){
            primes[j*i]=0;
        }
    }
        
    for(int i=0;i<=n/2;i++){
        int j=n-i;
        if(primes[i] && primes[j]){
            return {i,j};
        }
    }
    return {-1,-1};
}

// ⏲️ Expected Time Complexity: O(n*loglog(n))
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 10;
    vector<int> ans = getPrimes(n);
    for(int i=0; i<=ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
