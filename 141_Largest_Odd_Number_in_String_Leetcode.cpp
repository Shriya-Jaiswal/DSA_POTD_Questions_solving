#include<iostream>
#include<vector>
using namespace std;


// ▶️ Ask by :  Amazon ✯   Adobe ✯  


// ➡️ Approach - Simple Greedy
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

string largestOddNumber(string num) {
    int n = num.length();
    for(int i = n-1; i>=0; i--) {   
        if((num[i] - '0') % 2 != 0) {
             return num.substr(0, i+1);
        }
    }
    return "";
}

int main()
{
    string num = "52";
    string ans = largestOddNumber(num);
    cout << "ans is : " << ans << endl;
    return 0;
}
