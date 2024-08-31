#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | FactSet | Walmart

vector<int> find3Numbers(vector<int> &arr) {
    // Code here
    int n = arr.size();
    vector<int> leftSmall(n), rightLarge(n);
    leftSmall[0]=arr[0];
    for(int i=1;i<n;i++)leftSmall[i]=min(arr[i],leftSmall[i-1]);
    rightLarge[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)rightLarge[i]=max(arr[i],rightLarge[i+1]);
    for(int i=1;i<=n-2;i++){
        if(leftSmall[i-1]<arr[i] and arr[i]<rightLarge[i+1])return {leftSmall[i-1],arr[i],rightLarge[i+1]};
    }
    return {};
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    vector<int> arr = {1, 2, 1, 1, 3};
    vector<int> ans = find3Numbers(arr);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
