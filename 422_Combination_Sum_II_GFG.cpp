#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void help(vector<int> &arr,int n,int k,int i,int sum,vector<int> &temp,set<vector<int>> &st){
    if(sum==k){
        st.insert(temp);
        return;
    }
    if(i==n)return;
    help(arr,n,k,i+1,sum,temp,st);
    if(sum+arr[i]<=k){
        temp.push_back(arr[i]);
        help(arr,n,k,i+1,sum+arr[i],temp,st);
        temp.pop_back();
    }
}


vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
{
    sort(arr.begin(),arr.end());
    vector<int> temp;
    set<vector<int>> st;
    help(arr,n,k,0,0,temp,st);
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


// ⏲️ Expected Time Complexity: O(2min(n,p))
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 5;
    int k = 7;
    vector<int> arr = { 1, 2, 3, 3, 5 };
    vector<vector<int>> ans = CombinationSum2(arr,n,k);
    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();i++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
