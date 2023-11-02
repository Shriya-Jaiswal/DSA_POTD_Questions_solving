#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


// ➡️ Ask by Paytm, Amazon

int minDist(int arr[], int n, int x, int y) {
    int ans = INT_MAX;
    int a = -1;
    int b = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            a = i;
            if(b != -1){
                int diff = abs(a-b);
                ans = min(ans,diff);
            }
        }
        if(arr[i] == y){
            b = i;
            if(a != -1){
                int diff = abs(a - b);
                ans = min(ans,diff);
            }
        }
    }
    if(a == -1 || b == -1){
        return -1;
    }
    return ans;
}

// ⏲️ Time complexity : Expected Time Complexity: O(N)
// 🛢️ Space complexity : Expected Auxiliary Space: O(1)

int main()
{
    int n = 4;
    int arr[] = {1,2,3,2};
    int x = 1, y = 2;
    int ans = minDist(arr,n,x,y);
    cout<< "ans is : "<< ans << endl;
    return 0;
}
