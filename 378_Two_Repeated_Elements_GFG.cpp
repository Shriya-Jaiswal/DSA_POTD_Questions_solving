#include<iostream>
#include<vector>
using namespace std;

vector<int> twoRepeated (int arr[], int n) {
    vector<int>ans;
    for(int i=0;i<n+2;i++){
        int ind=abs(arr[i]);
        if(arr[ind]>0){
            arr[ind]=-arr[ind];
        }
        else{
            ans.push_back(ind);
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1). 

int main()
{
    int n = 4;
    int arr[] = {1,2,1,3,4,3};
    vector<int> ans = twoRepeated(arr,n);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
