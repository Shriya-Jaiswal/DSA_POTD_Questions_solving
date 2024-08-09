#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : SAP Labs

int Maximize(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long int ans=0;
    int mod=1e9+7;
    for(int i=0;i<arr.size();i++){
        ans+=1LL*i*arr[i];
        ans%=mod;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(nlog(n))
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    int ans = Maximize(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
