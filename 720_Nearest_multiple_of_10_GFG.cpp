#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

string roundToNearest(string str) {
    // Complete the function
    int n = str.length()-1;
    if(str[n]<='5'){
        str[n]='0';
        return str;
    }
    str[n]='0';
    n--;
    while(n>=0 and str[n]=='9'){
        str[n]='0';
        n--;
    }
    if(n==-1)return '1'+str;
    str[n]++;
    return str;
}


// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    string  str = "29" ;
    string ans = roundToNearest(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
