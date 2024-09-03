#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Microsoft ✯  

// ⏲️ Time Complexity : O(k*n)
// 🛢️ Space Complexity : O(n)

int getLucky(string s, int k) {
    string num = "";

    for(char &ch : s) {
        int char_int = ch - 'a' + 1; // 👉 a : 1, b : 2 and so on...
        num         += to_string(char_int);
    }
        
    int sum = 0;

    while(k--) {
        sum = 0;
        for(char &ch : num) {
            sum += ch - '0';
        }

        num = to_string(sum);
    }

    return stoi(num);
}


int main()
{
    string s = "iiii";
    int k = 1;
    int ans = getLucky(s,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
