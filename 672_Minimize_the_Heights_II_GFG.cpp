#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Microsoft | Adobe

int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    if(n==1)return 0;
    sort(arr.begin(),arr.end());
    int ans = arr[n-1]-arr[0], mn=0, mx=0;
    for(int i=1;i<n;i++){
        if(arr[i]-k<0)continue;
        mn = min(arr[0]+k,arr[i]-k);
        mx = max(arr[n-1]-k,arr[i-1]+k);
        ans=min(ans,mx-mn);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*logn)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    vector<int> arr = {1, 5, 8, 10};
    int  k = 2;
    int ans = getMinDiff(arr,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
