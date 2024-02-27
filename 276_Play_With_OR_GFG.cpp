#include<iostream>
using namespace std;

// ▶️ Ask by : none

int* game_with_number(int arr[], int n){
     for(int i=0;i<=n-2;i++){
        arr[i]=arr[i] | arr[i+1];
    }
    return arr;    
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 5;
    int arr[] = {10, 11, 1, 2, 3};
    int *ans = game_with_number(arr,n);
    cout << "ans is : " << *ans << endl;
    return 0;
}
