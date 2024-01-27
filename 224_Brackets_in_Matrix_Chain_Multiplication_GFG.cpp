#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Microsoft

 static string matrixChainOrder(int p[], int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    return ans(s, 1, n - 1);
}

static string ans(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        return string(1, 'A' + i - 1);
    } else {
        return "(" + ans(s, i, s[i][j]) + ans(s, s[i][j] + 1, j) + ")";
    }
}

// ⏲️ Expected Time Complexity: O(n3)
// 🛢️ Expected Auxiliary Space: O(n2)

int main()
{
    int n = 5;
    int p[] = {40, 20, 30, 10, 30};
    string ans = matrixChainOrder(p,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
