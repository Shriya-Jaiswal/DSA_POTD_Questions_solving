#include<iostream>
#include<vector>
using namespace std;


long long upto (string s, int k) {
    int l = 0;
    int r = 0; 
    int count = 0;
    long long ans = 0;
    vector<int> mp(26,0);

    while(r<s.length()){
        mp[s[r]-'a']++;
        if(mp[s[r]-'a']==1){
            count++;
        }
        while(count > k){
            mp[s[l] - 'a']--;
            if(mp[s[l]-'a'] <= 0){
                count--;
            }
            l++;
        }
        ans+=r-l+1; 
        r++;
    }
    return ans;
}
long long int substrCount (string s, int k) {
    return upto(s,k)-upto(s,k-1);
}

// ⏲️ Time complexity ---> O(s) --> 
// 🛢️ space complexity ---> O(1)

int main()
{
    string S = "aba";
    int K = 2;
    long long int ans = substrCount(S,K);
    cout<< ans << endl;
    return 0;
}
