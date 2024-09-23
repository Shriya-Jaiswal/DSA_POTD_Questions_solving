#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon Samsung D-E-Shaw Goldman Sachs MAQ Software

vector<int> findTwoElement(vector<int>& arr) {
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int element = abs(arr[i]);
        if(arr[element-1]<0)ans.push_back(element);
        else arr[element-1]*=-1;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0)ans.push_back(i+1);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int>  arr = {2, 2};
    vector<int> ans = findTwoElement(arr);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
