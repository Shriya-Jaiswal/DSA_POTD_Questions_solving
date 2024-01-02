#include<iostream>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Facebook | Paytm | Myntra

long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int ans = INT_MIN;
    long long int sum = 0;
    long long int last = 0;
    long long int j = 0;
    for(long long int i = 0; i < n; i++)
    {
        sum += a[i];
        if(i - j + 1 == k)
            ans = max(ans, sum);
        else if(i - j + 1 > k)
        {
            last += a[j];
            j++;
            if(last < 0)
            {
                sum -= last;
                last = 0;
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    long long int n = 4;
    long long int a[] = {1, -2, 2, -3};
    long long int k = 2;

    long long int ans = maxSumWithK(a,n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
