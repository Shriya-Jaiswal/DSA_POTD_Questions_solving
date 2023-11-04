#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by ---> Amazon

int transitionPoint(int arr[], int n) {
    int ans=-1;
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==1){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

// ⏲️ Time complexity : Expected Time Complexity: O(Log(N))
// 🛢️ Space complexity : Expected Auxiliary Space: O(1)

int main()
{
    int N = 5;
    int arr[] = {0,0,0,1,1};
    int ans = transitionPoint(arr,N);
    cout<< "ans is : " << ans << endl;
    return 0;
}
