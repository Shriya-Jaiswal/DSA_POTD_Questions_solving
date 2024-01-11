#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

// ➡️ Ask by : Microsoft

string removeKdigits(string S, int k) {
    int n = S.length();
    if (k == n) {
        return "0";
    }
    stack<char> st;
    for (char digit : S) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int len=ans.length();
    int startIndex = len;
    for (int  i = 0; i <len; i++) {
        if (ans[i] != '0') {
            startIndex = i;
            break;
        }
    }
    ans = (startIndex ==len ) ? "0" : ans.substr(startIndex);
    return ans;
}

// ⏲️ Expected Time Complexity: O(|S|).
// 🛢️ Expected Auxiliary Space: O(|S|).

int main()
{
    string S = "149811";
    int K = 3;
    string ans = removeKdigits(S,K);
    cout << "ans is : " << ans << endl;
    return 0;
}
