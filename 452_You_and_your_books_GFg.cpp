#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Junglee Games

long long max_Books(int arr[], int n, int k) {
    long long ans=0, curr=0;
    int i=0;
    while(i<n){
        if(arr[i]<=k){
            curr+=arr[i];
        }
        else{
            curr=0;
        }
            
        ans=max(ans, curr);
        i++;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    int n = 8 ;
    int k = 1;
    int arr[] = {3, 2,2 ,3, 1, 1, 1, 3};
    long long ans = max_Books(arr,n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
