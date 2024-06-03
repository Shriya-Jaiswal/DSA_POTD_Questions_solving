#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

// ▶️ Simple iteration
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int appendCharacters(string s, string t) {
    int m = s.length();
    int n = t.length();
        
    int i = 0; //for s
    int j = 0; //for t

    while(i < m && j < n) {
        if(s[i] == t[j]) {
            j++;
        }
        i++;
    }

    return n-j;
}

int main()
{
    string s = "coaching", t = "coding";
    int ans = appendCharacters(s,t);
    cout << "ans is : " << ans << endl;
    return 0;
}

