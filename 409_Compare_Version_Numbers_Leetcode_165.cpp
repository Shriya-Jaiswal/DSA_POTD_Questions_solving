#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Arista Networks ✯   Nutanix ✯  Apple (They check how easily you are able to manage strict corner cases)

// ▶️ Approach (Using stringstream tokenizer in C++)
// ⏲️ Time Complexity : O(m+n)
// 🛢️ Space Complexity : O(m+n)

vector<string> getTokens(string version) {
    stringstream v(version);
    string token_v = "";
    vector<string> version_tokens;
    while(getline(v, token_v, '.')) {
        version_tokens.push_back(token_v);
    }
    return version_tokens;
}

int compareVersion(string version1, string version2) {

    vector<string> v1 = getTokens(version1);
    vector<string> v2 = getTokens(version2);  
        
    int m = v1.size();
    int n = v2.size();
            
    int  i = 0;
    while(i < m || i < n) {
            
        int a = i < m ? stoi(v1[i]) : 0 ;
        int b = i < n ? stoi(v2[i])  : 0 ;
            
        if(a > b)
            return 1;
        else if(b > a)
            return -1;
        else
            i++;
    }
    return 0;
}

int main()
{
    string version1 = "1.01";
    string version2 = "1.001";

    int ans = compareVersion(version1,version2);
    cout << "ans is : " << ans << endl;
    return 0;
}
