#include<iostream>
#include<algorithm>
using namespace std;


// ▶️ Microsoft Adobe

int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int ans= arr[n-1]-arr[0];
    int smallest=arr[0]+k;
    int largest=arr[n-1]-k;
    int mi,mx;
    for(int i=0;i<n-1;i++){
        mi=min(smallest,arr[i+1]-k);
        mx=max(largest,arr[i]+k);
        if(mi<0) continue;
        ans=min(ans,mx-mi);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N*logN)
// 🛢️ Expected Auxiliary Space: O(N)

int main()
{
    int K = 2, N = 4;
    int arr[] = {1, 5, 8, 10};
    int ans = getMinDiff(arr, N,K);
    cout << "ans is : " << ans << endl;
    return 0;
}
