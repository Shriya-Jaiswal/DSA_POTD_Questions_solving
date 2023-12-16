#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Google

long long int countStr(long long int n){
    return 1+n+n+n*(n-1)+n*(n-1)/2 + n*(n-1)*(n-2)/2;
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    long long int n = 1;
    long long int ans = countStr(n);
    cout << "ans is : " << ans << endl; 
    return 0;
}
