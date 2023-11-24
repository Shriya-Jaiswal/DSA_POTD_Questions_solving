#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon | Microsoft | Adobe

vector<long long> nthRowOfPascalTriangle(int n) {
    vector<long long> prev;
    int mod=1e9+7;
    for (int i = 0; i < n; i++) {
        vector<long long> curr(i + 1, 1);
        for (int j = 1; j < i; j++) {
            curr[j] = (prev[j - 1] + prev[j])%mod ;
        }
        prev = curr;
    }
    return prev ;
}

// ⏲️ Expected Time Complexity: O(N2)
// 🛢️ Expected Auxiliary Space: O(N2)

int main()
{
    int n = 4;
    vector<long long > ans = nthRowOfPascalTriangle(n);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
