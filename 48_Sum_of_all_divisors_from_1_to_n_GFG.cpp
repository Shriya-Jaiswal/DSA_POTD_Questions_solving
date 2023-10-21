#include<iostream>
#include<vector>
using namespace std;

long long sumOfDivisors(int N)
{
    long long ans = 0;
    for(int i=1; i<=N; i++){
        ans += i*(N/i);
    }
    return ans;
}

// ⏲️ Time Complexity ---> Expected Time Complexity: O(N)
// 🛢️ Space complexity---> Expected Auxiliary Space: O(1)

int main()
{
    int N = 4;
    long long ans = sumOfDivisors(N);
    cout << "ans is: " << ans << endl;
    return 0;
}

