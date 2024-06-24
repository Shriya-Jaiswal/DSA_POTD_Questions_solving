#include<iostream>
#include<vector>
using namespace std;

long long sumMatrix(long long n, long long q) {
    if(2*n < q){
        return 0ll;
    }
    else if(q<=n){
        return q-1;
    }
    else{
        return 2*n-q+1;
    }
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    long long  n = 4;
    long long q = 7;
    long long ans = sumMatrix(n,q);
    cout << "ans is : " << ans << endl;
    return 0;
}
