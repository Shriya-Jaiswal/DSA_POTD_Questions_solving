#include<iostream>
#include<vector>
using namespace std;

void swapElements(int arr[], int n){ 
    for(int  i=0;i+2<n;i++){
        swap(arr[i], arr[i+2]);
    }
    return;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxilary Space: O(1)

int main()
{
    int n = 3;
    int arr[] = {1 , 2 , 3};

    cout << "Before Swapping : " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    
    swapElements(arr,n);

    cout << "After Swapping : " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
