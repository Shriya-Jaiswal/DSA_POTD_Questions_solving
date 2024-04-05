#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Adobe ✯   Google ✯  Apple, LinkedIn, Microsoft

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) -> Ignoring the space taken for result string

string makeGood(string s) {
    string result = "";
    for(char &ch : s) {
        if(result.size() > 0 && (ch + 32 == result.back() || ch - 32 == result.back())) {
            result.pop_back();
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main()
{
    string s = "leEeetcode";
    string ans = makeGood(s);
    cout << "ans is :" << ans << endl;
    return 0;
}
