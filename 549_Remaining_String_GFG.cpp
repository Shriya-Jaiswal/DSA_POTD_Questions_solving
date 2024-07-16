#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho | Oracle

string printString(string s, char ch, int count) {
    int i=0;
    for(i=0;i<s.length();i++){
        if(s[i]==ch)count--;
        if(!count)break;
    }
    if(i>=s.length()-1)return "";
    s=s.substr(i+1);
    return s;
}

// ⏲️ Expected Time Complexity: O(|s|)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string s = "Thisisdemostring";
    char ch = 'i';
    int count = 3;
    string ans = printString(s,ch,count);
    cout << "ans is :" << ans << endl;
    return 0;
}
