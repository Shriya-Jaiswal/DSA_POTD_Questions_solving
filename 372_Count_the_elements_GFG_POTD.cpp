#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Yatra.com

vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,int q) {
    int maximum=0;
    for(int i=0;i<n;i++){
        maximum=max(maximum, max(a[i], b[i]));
    }  
    vector<int>arr(maximum+1,0);
    for(int i=0;i<n;i++){
        arr[b[i]]++;
    }
    for(int i=1;i<=maximum;i++){
        arr[i]+=arr[i-1];
    }  
    vector<int>res;
    for(auto it:query){
        res.push_back(arr[a[it]]);
    }  
    return res;
}

// ⏲️ Expected Time Complexity: O(n+q+maximum of a and b).
// 🛢️ Expected Auxiliary Space: O(maximum of a and b).

int main()
{
    vector<int> a = {4,1,2};    
    vector<int> b = {1,7,3};
    int n = 3;
    vector<int> query = {0,1};
    int q = 2;

    vector<int> ans = countElements(a,b,n,query,q);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
