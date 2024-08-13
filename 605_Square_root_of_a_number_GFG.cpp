#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask  : VMWare | Flipkart | Accolite | Amazon | Microsoft

long long int floorSqrt(long long int n) {
    long long int low=1,high=n,mid=0,ans=1;
    while(low<=high){
        mid=(low+high)/2;
        if(mid*mid==n)return mid;
        else if(mid*mid<n){
            low=mid+1;
            ans=mid;
        }
        else high=mid-1;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(logn)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    long long int n = 5;
    long long int ans = floorSqrt(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
