#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho | Amazon

int findExtra(int n, int arr1[], int arr2[]) {
    for(int i=0;i<n-1;i++){
        if(arr1[i]!=arr2[i]){
            return i;
        }
    }
    return n-1;
}

// ⏲️ Expected Time Complexity: O(log n).
// 🛢️ Expected Auxiliary Space: O(1).


int main()
{
    int  n = 7;
    int arr1[] = {2,4,6,8,9,10,12};
    int arr2[] = {2,4,6,8,10,12};

    int ans = findExtra(n,arr1,arr2);
    cout << "ans is : " << ans << endl;

    return 0;
}
