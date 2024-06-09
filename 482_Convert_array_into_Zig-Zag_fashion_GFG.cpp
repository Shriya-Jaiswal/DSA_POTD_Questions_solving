#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | Amazon | Adobe

void zigZag(int n, vector<int> &arr) {
    for(int i=0;i<n-1;i++){
        if(i%2==0){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        else{
            if(arr[i] < arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }
    return;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int  n = 7;
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};

    zigZag(n,arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    return 0;
}
