#include<iostream>
#include<algorithm>
using namespace std;

// ▶️ Ask by ; Paytm

int smallestSubstring(string S) {
    int zero = -1, one = -1, two = -1, res = 100001;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '0') zero = i;
        if (S[i] == '1') one = i;
        if (S[i] == '2') two = i;

        if (zero == -1 || one == -1 || two == -1) continue;
        int minimum = min({one, zero, two});
        int maximum = max({one, zero, two});
        res = min(res, maximum - minimum + 1);
    }

    return res == 100001 ? -1 : res;
}


// ⏲️ Expected Time Complexity: O( length( S ) )
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string S = "10212";
    int ans = smallestSubstring(S);
    cout << "ans is : " << ans << endl;
    return 0;
}
