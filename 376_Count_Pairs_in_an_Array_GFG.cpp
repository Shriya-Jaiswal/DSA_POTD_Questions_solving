#include<iostream>
using namespace std;

int merge(int arr[], int low, int mid, int high){
    int temp[high-low+1];
    int k=0;
    int i=low;
    int j=mid+1;
    int inv=0;
        
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            inv+= mid-i +1;
            temp[k++]=arr[j++];
        }
    }
        
    while(i<=mid){
        temp[k++]=arr[i++];
    }
        
    while(j<=high){
        temp[k++]=arr[j++];
    }
        
    for(int x=low; x<=high; x++){
        arr[x]=temp[x-low];
    }
        
    return inv;
}
    
int mergeSort(int arr[], int low, int high){
    if(low>=high) return 0;
    int inv=0;
        
    int mid= (low+high)/2;
        
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    inv += merge(arr, low, mid, high);
        
    return inv;
}
    
int inversionCount(int arr[],int N){ 
    int ans = mergeSort(arr, 0, N-1);
    return ans;
}

int countPairs(int arr[] , int n ) {  
    for(int i=0;i<n;i++){
        arr[i]*=i;
    }
    return inversionCount(arr, n);       
}

// ⏲️ Expected Time Complexity: O(n*log(n))
// 🛢️ Expected Auxiliary Space: O(n*log(n))

int main(){
    int n = 4;
    int arr[] = {8, 4, 2, 1};
    int ans = countPairs(arr,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
