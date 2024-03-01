#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Accolite | Amazon | Visa | Adobe | Google

int peakElement(int arr[], int n)
{
    int l=0,h=n-1;
    while(l<h){
        int mid=(l+h)/2;
        if(arr[mid]<arr[mid+1]) l=mid+1;
        else h=mid;
    }
    return l;
}

// ⏲️ Expected Time Complexity: O( log(n) ).
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int n = 3;
    int arr[] = {1, 2, 3};
    int ans = peakElement(arr,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
