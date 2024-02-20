#include<iostream>
#include<vector>
using namespace std;

// ➡️ Ask by : Zoho | Flipkart | Amazon | Microsoft | Hike | Walmart | MAQ Software | Google | IBM

int wordBreak(int n, string s, vector<string> &dictionary) {
    n = s.length();
    // 👉 dp[i] will be true if the first i characters of s can be segmented into words from the dictionary
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // 👉 An empty string can always be segmented
        
    for (int i = 1; i <= n; ++i) {
        for (const string& word : dictionary) {
            if (i >= word.length() && dp[i - word.length()] && s.substr(i - word.length(), word.length()) == word) {
                dp[i] = true;
                break;
            }
        }
    }
        
    return dp[n] ? 1 : 0;
}

// ⏲️ Expected Time Complexity: O(len(s)2)
// 🛢️ Expected Space Complexity: O(len(s))

int main()
{
    int n = 6 ;
    string s = "ilike";
    vector<string> dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"};
    int ans = wordBreak(n,s,dictionary);
    cout << "ans is : " << ans << endl;
    return 0;
}
