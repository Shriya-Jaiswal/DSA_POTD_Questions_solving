#include<iostream>
#include<vector>
using namespace std;


// ▶️ Ask by :  OpenText ✯   PayPay ✯  

// ➡️ //Simple iteration and check

string largestGoodInteger(string num) {
    char maxChar = ' ';    
    for(int i = 2; i<num.length(); i++) {
        if(num[i] == num[i-1] && num[i] == num[i-2]) {
            maxChar = max(maxChar, num[i]);
        }
    }
    return maxChar == ' ' ? "" : string(3, maxChar);
}

int main()
{
    string  num = "6777133339";
    string ans = largestGoodInteger(num);
    cout << "ans is : " << ans << endl;
    return 0;
}
