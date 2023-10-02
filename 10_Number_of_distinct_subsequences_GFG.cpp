#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 👉 if we apply brute force to find all subsequence then ⏲️ time complexity will be O(2^n) 🛢️ ans space complexity will be O(2^n)
// ➡️ Apply dp
int distinctSubsequences(string s)
{
	int mod = 1000000007;
    int n = s.length();
    vector<int>dp(n+1); // 👉 n is a length of the string and +1 since we store base cases add in the index of 0 generally
    dp[0] = 1;

    unordered_map<char,int> map;
    for(int i=1; i<=n;i++){
        char ch = s[i-1]; // 👉 i-1 becuase i starting from 1 in loop
        dp[i] = (2*dp[i-1])%mod; 
        if(map.find(ch)!=map.end()){ // 👉 check character might already occur 
            int index = map[ch];
            dp[i] = (dp[i]-dp[index-1]+mod)%mod;
        }
        map[ch] = i;
    }
    return dp[n];
}

int main()
{
    string s = "gfg";
    int ans = distinctSubsequences(s);
    cout << " ans is : " << ans << endl; 
    return 0;
}
