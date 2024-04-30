#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : DE Shaw ✯   Google ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

typedef long long ll;
long long wonderfulSubstrings(string word) {
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    int cum_xor = 0;
    ll result = 0;

    for(char &ch : word) {
        int shift = ch - 'a';
        cum_xor ^= (1 << shift);
        result += mp[cum_xor];
        for(char ch1 = 'a' ; ch1 <= 'j'; ch1++) {
            shift = ch1 - 'a';
            ll check_xor = (cum_xor ^ (1 << shift));
            result += mp[check_xor];
        }
        mp[cum_xor]++;
    }
    return result;
}

int main()
{
    string  word = "aba";
    long long ans = wonderfulSubstrings(word);
    cout << "ans is : " << ans << endl;
    return 0;
}
