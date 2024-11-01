#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Wayfair ✯  

string makeFancyString(string s) {
    if(s.size() <=2) return s;
    string ans="";
    ans.push_back(s[0]);
    for(int i=1; i<s.size()-1; i++){
        if(s[i-1] == s[i] && s[i+1] == s[i]) continue;
        ans.push_back(s[i]);
    }
    ans.push_back(s[s.size()-1]);
    return ans;
}

int main()
{
    string s = "leeetcode";
    string ans = makeFancyString(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
