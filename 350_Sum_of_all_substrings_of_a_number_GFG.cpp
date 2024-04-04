#include<iostream>
#include<vector>
using namespace std;

long long sumSubstrings(string s){
    long  long prev=0, curr=0, ans=0;
    long long mod=1e9+7;
        
    for(int i=0;i<s.length();i++){
        curr=(s[i]-'0')*(i+1) + prev*10;
        curr%=mod;
        ans+=curr;
        ans%=mod;
        prev=curr;
    }
    return ans;
}


// ⏲️ Expected Time Complexity: O(|s|).
// 🛢️ Expected Auxiliary Space: O(|s|).

int main()
{
    string s = "1234";
    long long ans = sumSubstrings(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
