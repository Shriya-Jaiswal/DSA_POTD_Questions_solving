#include<iostream>
#include<vector>
using namespace std;

int findClosest( int n, int k,int arr[]) 
{ 
    int lo=0, hi=n-1;
    int ans=arr[0];
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(abs(k-arr[mid])==abs(k-ans)){
            ans=max(ans, arr[mid]);
        }
        else if(abs(k-arr[mid])<abs(k-ans)){
            ans=arr[mid];
        }
            
        if(arr[mid]==k) return arr[mid];
        else if(arr[mid]<k) lo=mid+1;
        else hi=mid-1;
    }
    return ans;
} 

// ⏲️ Expected Time Complexity: O(log(n)).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 4;
    int k = 4;
    int arr[] = {1, 3, 6, 7};
    int ans = findClosest(n,k,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
