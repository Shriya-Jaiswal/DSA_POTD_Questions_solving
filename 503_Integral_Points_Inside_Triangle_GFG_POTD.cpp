#include<iostream>
#include<algorithm>
using namespace std;

long long int InternalCount(long long int p[], long long int q[],long long int r[]) {
    long long int area = (abs(p[0]*(q[1] - r[1]) + q[0]*(r[1] - p[1]) + r[0]*(p[1] - q[1])))/2;
        
    long long int b1 = __gcd(abs(p[0] - q[0]), abs(p[1] - q[1]));
    long long int b2 = __gcd(abs(q[0] - r[0]), abs(q[1] - r[1]));
    long long int b3 = __gcd(abs(r[0] - p[0]), abs(r[1] - p[1]));
        
    long long int boundaryPoints = b1 + b2 + b3;

    long long int internalPoints = area - boundaryPoints/2 + 1;

    return internalPoints;
}

// ⏲️ Expected Time Complexity: O(Log2109)
// 🛢️ Expected Auxillary Space: O(1)

int main()
{
    long long int p[] = {0,0};
    long long int q[] = {0,5};
    long long int r[] = {5,0};

    long long int ans = InternalCount(p,q,r);
    cout << "ans is : " << ans << endl;
    return 0;
}
