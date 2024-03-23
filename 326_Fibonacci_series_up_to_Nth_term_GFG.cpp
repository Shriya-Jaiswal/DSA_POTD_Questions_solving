#include<iostream>
#include<vector>
using namespace std;

vector<int> Series(int n) {
    vector<int>ans(n+1);
    ans[0]=0;
    ans[1]=1;
        
    int mod=1e9+7;
    for(int i=2;i<=n;i++){
        int x= ans[i-1]+ans[i-2];
        x%=mod;
        ans[i]=x;
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> ans = Series(n);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
