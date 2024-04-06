#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Accolite | Amazon


long long countWays(int n) {
    long long res[n+1];
    res[0]=1;
    res[1]=1;
        
    for(int i=2;i<=n;i++){
        res[i]=res[i-2]+1;
    }
    return res[n];
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 4;
    long long ans = countWays(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
