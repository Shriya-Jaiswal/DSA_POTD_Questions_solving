#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Yahoo

void threeWayPartition(vector<int>& arr,int a, int b){
    int n=arr.size();
    int start=0;
    int end=n-1;
    for(int i=0;i<=end;i=i){
        if(arr[i]<a){
            swap(arr[i], arr[start]);
            i++;
            start++;
        }
        else if(arr[i]>b){
            int temp=arr[i];
            arr[i]=arr[end];
            arr[end--]=temp;
        }
        else{
            i++;
        }
    }
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int>array = {1, 2, 3, 3, 4};
    int a = 1;
    int b = 2;
    threeWayPartition(array,a,b);
    for(int i=0; i<array.size();i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
