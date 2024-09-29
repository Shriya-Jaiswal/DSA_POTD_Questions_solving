#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho

int totalCount(int k, vector<int>& arr) {
    int ans = 0;
    for(auto x : arr) {
        ans += (x + k - 1) / k;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int  k = 3;
    vector<int> arr = {5, 8, 10, 13};
    int ans = totalCount(k,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
