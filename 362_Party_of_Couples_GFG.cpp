#include<iostream>
using namespace std;

// ▶️ Ask by : Ola Cabs

 int findSingle(int n, int arr[]){
    // code here
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^(arr[i]);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 2, 1};
    int ans = findSingle(n,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
