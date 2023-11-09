#include<iostream>
#include<vector>
using namespace std;

// ➡️ Simple loop and count

int MOD = 1e9+7;

int countHomogenous(string s) {
        int n = s.length();
        int result = 0;
        int count  = 0;
        
        for(int i = 0; i<n; i++) {
            if(i > 0 && s[i] == s[i-1]) {
                count++;
            } 
            else {
                count = 1;
            }
            result = (result + count) % MOD;
        }
        return result;
}

// ⏲️ Time Complexity : O(n)
// 🛢️ space complexity : O(1)


int main()
{
    string s = "abbcccaa";
    int ans = countHomogenous(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
