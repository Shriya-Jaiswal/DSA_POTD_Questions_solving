#include<iostream>
using namespace std;

// ▶️ GFG POTD ---> EASY
void pushZerosToEnd(int arr[], int n) {
	int i = 0;
    int j = 1;
    while(i<j && j<n){
        if(arr[i] == 0){
            while(j<n && arr[j] == 0){
                j++;
            }
            if(j<n){
                swap(arr[i],arr[j]);
            }
        }
        i++;
        j++;
    }
}

// ⏲️ Time complexity : Expected Time Complexity: O(n)
// 🛢️ Space complexity : Expected Auxiliary Space: O(1)

int main()
{
    int n = 5;
    int arr[] = {3, 5, 0, 0, 4};
    pushZerosToEnd(arr,n);
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
    return 0;
}
