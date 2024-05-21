#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// ▶️ Ask by : Amazon | OYO Rooms

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    vector<int> vec;
    int low=0,high=n-1,mid=0,mn=INT_MAX,ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        int diff=abs(arr[mid]-x);
        if(diff<=mn){
            if(ans==-1)ans=mid;
            else{
                if(diff==mn and arr[ans]<arr[mid]){
                    ans=mid;
                }
                if(diff<mn)ans=mid;
            }
            mn=diff;
        }
        if(arr[mid]<x)low=mid+1;
        else high=mid-1;
    }
    int total=0,i=ans-1,j=ans+1;
    if(arr[ans]!=x){
        vec.push_back(arr[ans]);
        total++;
    }
    while(total<k){
        if(i>=0 and j<n){
            if(abs(arr[i]-x)<abs(arr[j]-x))vec.push_back(arr[i--]);
            else vec.push_back(arr[j++]);
        }
        else if(i>=0)vec.push_back(arr[i--]);
        else vec.push_back(arr[j++]);
        total++;
    }
    return vec;
}


// ⏲️ Expected Time Complexity: O(log n + k)
// 🛢️ Expected Auxiliary Space: O(k)

int main()
{
    int n = 13;
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;

    vector<int> ans = printKClosest(arr,n,k,x);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
