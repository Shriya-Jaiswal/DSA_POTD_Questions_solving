#include<iostream>
#include<vector>
using namespace std;


void convertToWave(int n, vector<int>& arr){
    for(int i=0; i<n;i+=2){
        if(i>0 && arr[i] < arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(i<n-1 && arr[i] < arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }        
}

int main()
{
    int n = 5;
    vector<int> arr  {1,2,3,4,5};
    convertToWave(n,arr);
    for(int i=0; i<arr.size();i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;

    return 0;
}
