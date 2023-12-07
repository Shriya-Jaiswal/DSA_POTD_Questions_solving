#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

long countSubarrays(int a[], int n, int L, int R){
    long ans=0;
    long btwLR=0, lessL=0 ;
    for(int i=0;i<n;i++){
        if(a[i]<L){
            ans+=btwLR;
            lessL++;
        }
        else if(a[i]>R){
            btwLR=lessL=0;
        }
        else{
            ans+=btwLR+lessL+1;
            btwLR+=lessL+1;
            lessL=0;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int arr[] = {2, 0, 11, 3, 0};
    int n= 5;
    int L = 1;
    int R = 10;
    long ans = countSubarrays(arr,n,L,R);
    cout << "ans is : " << ans << endl;
    return 0;
}
