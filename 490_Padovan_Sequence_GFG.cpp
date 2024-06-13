#include<iostream>
#include<vector>
using namespace std;

int padovanSequence(int n)
{
    if(n<=2) return 1;
    int n_1=1, n_2=1, n_3=1, ans;
    int mod=1e9+7;
    for(int i=0;i<n-2;i++){
        ans=(n_2+n_3)%mod;
           
        n_3=n_2;
        n_2=n_1;
        n_1=ans;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)


int main()
{
    int n = 3 ;
    int ans = padovanSequence(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
