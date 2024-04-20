#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

//arr1,arr2 : the arrays
// n, m: size of arrays
//Function to return a list containing the union of the two arrays. 
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // 👉 return vector with correct order of elements
    if(arr1[0]>arr2[0]){
        return findUnion(arr2, arr1, m, n);
    }
        
    vector<int>ans={arr1[0]};
       int i=1, j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
                
        }
    }
    while(i<n){
        if(ans.back()!=arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<m){
        if(ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    } 
    return ans;
}

// ⏲️ Expected Time Complexity: O(n+m).
// 🛢️ Expected Auxiliary Space: O(n+m).

int main()
{
    int n = 5; 
    int arr1[] = {1, 2, 3, 4, 5};
    int m = 5;
    int arr2 [] = {1, 2, 3, 6, 7};

    vector<int> ans = findUnion(arr1,arr2,n,m);
    for(int i = 0; i<ans.size(); i++ ){
        cout << ans[i] << " ";
    }
    return 0;
}
