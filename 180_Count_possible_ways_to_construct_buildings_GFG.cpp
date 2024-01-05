#include<iostream>
using namespace std;

// ▶️ Ask by : Payu

int TotalWays(int N)
{
	int mod = 1000000007;
    long a = 1, b = 2, c = 2;
        
    for (int i = 2; i <= N; i++) {
        c = (a + b) % mod;
        a = b;
        b = c;
    }
        
    return (c * c) % mod;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Space Complexity: O(N)

int main()
{
    int N = 1;
    cout << "ans is : " << TotalWays(N) << endl;
    return 0;
}
