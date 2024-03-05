#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : VMWare | Amazon | Microsoft | MakeMyTrip

// A[]: input array
// N: size of array
// Function to find the maximum index difference.

int maxIndexDiff(int a[], int n) { 
        
    vector<int>preMin(n,0);
    vector<int>suffMax(n,0);
        
    int maxi=a[n-1];
    for(int i=n-1;i>=0;i--){
        maxi=max(maxi, a[i]);
        suffMax[i]=maxi;
    }
        
    int mini=a[0];
    for(int i=0;i<n;i++){
        mini=min(mini, a[i]);
        preMin[i]=mini;
    }
        
    int i=0, j=0;
    int ans=-1;
    while(i<n && j<n){
        if(preMin[i]<=suffMax[j]){
            ans=max(ans, j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(N)

int main()
{
    int n = 2;
    int a[] = {1, 10};
    int ans = maxIndexDiff(a,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
