#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | Google | Airtel

int countMin(string str){
    string s = str;
    reverse(s.begin(), s.end());
    int n = str.length();
    vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str[i - 1] == s[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return n - dp[n][n];
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Auxiliary Space: O(n2)

int main()
{
    string str = "abcd";
    int ans = countMin(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
