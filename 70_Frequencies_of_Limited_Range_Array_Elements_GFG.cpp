#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by ---> Paytm , VMWare, Zoho , Amazon , Microsoft

void frequencyCount(vector<int>& arr,int N, int P)
{ 
    int i=0;
    while(i<N){
        if(arr[i]<=0 || arr[i]>N){
            i++;
            continue;
        }
        int index = arr[i]-1;
        if(arr[index]>0){
            arr[i] = arr[index];
            arr[index] = -1;
        }
        else{
            arr[i] = 0;
            arr[index]--;
            i++;
        }
    }
    for(int i=0; i<N; i++){
        if(arr[i]<0){
            arr[i] = -1 *arr[i];
        }
        else{
            arr[i] = 0;
        }
    }
}

// ⏲️ Time complexity : Expected time complexity: O(N)
// 🛢️ Space Complexity : Expected auxiliay space: O(1)

int main()
{
    int N = 5;
    vector<int> arr{2, 3, 2, 3, 5};
    int P = 5;

    frequencyCount(arr,N,P);

    for(int i=0; i<arr.size();i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
    return 0;
}
