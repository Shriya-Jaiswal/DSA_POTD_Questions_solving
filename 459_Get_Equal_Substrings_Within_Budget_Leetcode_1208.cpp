#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  IBM ✯   Traveloka ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int equalSubstring(string s, string t, int maxCost) {
    int n = s.length();
        
    int maxLen = 0;
    int currCost = 0;
        
    int i = 0, j = 0;
    while(j < n) {
        currCost += abs(s[j] - t[j]);
            
        while (currCost > maxCost) {
            currCost -= abs(s[i] - t[i]);
            i++;
        }
            
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
        
    return maxLen;
}

int main()
{
    string  s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    int ans = equalSubstring(s,t,maxCost);
    cout << "ans is : " << ans << endl;
    return 0;
}
