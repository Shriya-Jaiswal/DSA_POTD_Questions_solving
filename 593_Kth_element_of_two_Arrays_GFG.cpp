#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Flipkart | Microsoft

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size() , n2 = arr2.size() ;
    if(k == n1+n2)return max(arr1[n1-1],arr2[n2-1]);
    if(k==1)return min(arr1[0],arr2[0]);
    int i = 0 , j = 0 ;
    while(i<n1 && j<n2 && k>1){
        if(arr1[i]<=arr2[j]){
            i++;
        }
        else j++;
        k--;
    }
        
    while(i<n1 && k>1){
        i++;
        k--;
    }
    while(j<n2 && k>1){
        j++;
        k--;
    }
    if(i==n1)return arr2[j];
    else if(j==n2)return arr1[i];
    return min(arr1[i],arr2[j]);
}

// ⏲️ Expected Time Complexity: O(log(n) + log(m))
// 🛢️ Expected Auxiliary Space: O(log (n))

int main()
{
    int k = 5;
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};

    int ans = kthElement(k,arr1,arr2);
    cout << "ans is : " << ans << endl;
    return 0;
}
