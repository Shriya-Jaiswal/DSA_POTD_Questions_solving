#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSub(string s) {
    unordered_map<char, int> mp;
    int n = s.length();
    vector<int> dp(n+1);
    dp[0] = 1;
        
    for (int i = 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1];
            
        char ch=s[i-1];
            
        if (mp.find(ch) != mp.end()) {
            dp[i] = dp[i] - dp[mp[ch]];
        }

        mp[ch] = (i - 1);
    }

    return dp[n];
}
    

string betterString(string str1, string str2) {
    int x = countSub(str1);
    int y = countSub(str2);

    if (x < y) {
        return str2;
    }
    return str1;
}

// ⏲️ Expected Time Complexity: O( max( str1.length, str2.length ) )
// 🛢️ Expected Auxiliary Space: O( max( str1.length, str2.length ) )

int main()
{
    string str1 = "gfg";
    string str2 = "ggg";
    string ans = betterString(str1,str2);
    cout << "ans is : " << ans << endl;
    return 0;
}
