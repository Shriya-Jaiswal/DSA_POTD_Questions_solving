#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

 vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
    vector<int> ans;
    int start = 0;
    int  end = m-1;

    int ele1 = INT_MIN;
    int ele2 = INT_MIN;

    int closestDiff = INT_MAX;

    while(start < n && end >= 0){
        int sum = arr[start] + brr[end];
        int absDiff = abs(sum-x);
        if(absDiff < closestDiff){
            closestDiff = absDiff;
            ele1 = arr[start];
            ele2 = brr[end];
        }
        if(sum > x){
            end--;
        }
        else{
            start++;
        }
    }

    ans.push_back(ele1);
    ans.push_back(ele2);
    return ans;
}

int main()
{
    int N= 4;
    int M =4;

    int arr[] = {1,4,5,7};
    int brr[] = {10,20,30,40};
    int x =32;

    vector<int> ans = printClosest(arr,brr,N,M,x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] << " ";
    }cout<< endl;
    
    return 0;
}


// int index1, index2, l, r;
//     int diff = INT_MAX;
//     l=0;
//     r = m-1;
//     vector<int>ans;
//     while(l<n && r>=0){
//         int sum = arr[l] + brr[r];
//         if(abs(sum-x) < diff){
//             index1 = l;
//             index1 = r;
//             diff = abs(sum-x);
//         }
//         if(sum > x){
//             r--;
//         }
//         else{
//             l++;
//         }
//     }
//     // int a1= 
//     ans.push_back(arr[index1] + brr[index2]);
//     return ans;