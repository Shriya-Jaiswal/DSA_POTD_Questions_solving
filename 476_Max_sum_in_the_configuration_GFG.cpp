#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

long long max_sum(int a[], int n) {
    long long sum=0;
    for(long long i=0;i<n;i++){
        sum+=a[i];
    }
        
    long long initial=0, max=0;
    for(long long i=0;i<n;i++){
        initial+=i*a[i];
    }
    max=initial;
        
    for(long long i=1;i<n;i++){
        long long next=initial - (sum-a[i-1]) + 1LL*(n-1)*a[i-1];
        initial=next;
        if(max<initial){
            max=initial;
        }
    }
    return max;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 4;
    int a[] = {8, 3, 1, 2};
    long long ans = max_sum(a,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
