#include<iostream>
#include<vector>
using namespace std;

void printArr(int n, int arr[]) {
    // Your code for printing array here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void setToZero(int n, int arr[]) {
    // Use memset to set arr to zero
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}

void xor1ToN(int n, int arr[]) {
    // Xor arr[i]^i
    for(int i=0;i<n;i++){
        arr[i]=arr[i]^i;
    }
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int n = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    xor1ToN(n,arr);
    printArr(n,arr);
    setToZero(n,arr);
    printArr(n,arr);
    return 0;
}
