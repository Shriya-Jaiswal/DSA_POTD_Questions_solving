#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Goldman Sachs ✯  

// ▶️ Using simple 2 Pointers
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int minimumLength(string s) {
    int n = s.length();
        
    int i = 0, j = n-1;
        
    while(i < j && s[i] == s[j]) {
        char ch = s[i];
            
        while(i < j && s[i] == ch) {
            i++;
        }
            
        while(j >= i && s[j] == ch) {
            j--;
        }
    }  
    return j-i+1;
}


int main()
{
    string s = "ca";
    int ans = minimumLength(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
