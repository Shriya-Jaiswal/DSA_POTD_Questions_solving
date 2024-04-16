#include<iostream>
#include<vector>
using namespace std;

int minimizeDifference(int n, int k, vector<int> &arr) {
    vector<int>post_maxi(n,0);
    vector<int>post_mini(n,0);
    post_maxi[n-1]=arr[n-1];
    post_mini[n-1]=arr[n-1];
        
    for(int i=n-2;i>=0;i--){
        post_maxi[i]=max(arr[i], post_maxi[i+1]);
        post_mini[i]=min(arr[i], post_mini[i+1]);
    }
        
    int ans=post_maxi[k]-post_mini[k];
    int maxi=arr[0], mini=arr[0];
    for(int i=1;i<n-k;i++){
        ans=min(ans, max(post_maxi[i+k],maxi) - min(post_mini[i+k],mini));
            
        maxi=max(arr[i], maxi);
        mini=min(arr[i], mini);
    }
        
    ans=min(ans, maxi-mini);
        
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 5;  
    int k = 3;
    vector<int> arr = {1, 2, 3, 4, 5};
    int ans = minimizeDifference(n,k,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
