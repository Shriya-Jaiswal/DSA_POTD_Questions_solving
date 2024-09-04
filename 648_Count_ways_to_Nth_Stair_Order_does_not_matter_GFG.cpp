#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  AccoliteAmazon

long long nthStair(int n) {
    return n/2+1;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(n)

int main()
{
    int  n = 4;
    int ans = nthStair(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
