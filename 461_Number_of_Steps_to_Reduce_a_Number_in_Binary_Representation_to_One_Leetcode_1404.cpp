#include<iostream>
#include<vector>
using namespace std;

// // ▶️ Ask by :  Microsoft ✯   Amazon ✯  

// // ▶️ Approach-1 (Simple simulation - Do what is beinhg asked)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(1)

// void addOne(string &s) {
//     int i = s.length()-1;

//     while(i >= 0 && s[i] != '0') {
//         s[i] = '0';
//         i--;
//     }

//     if(i < 0) {
//         s = '1' + s;
//     } else {
//         s[i] = '1';
//     }
// }

// int numSteps(string s) {
//     int op = 0;
//     while(s.length() > 1) {
//         int n = s.length();

//         if(s[n-1] == '0') {
//             s.pop_back();
//         } else {
//             addOne(s);
//         }
//         op++;
//     }
//     return op;
// }



// ▶️ Approach-2 (Simply calculating for odd and even)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int numSteps(string s) {
    int n = s.length();

    int op = 0;
    int carry = 0;

    for(int i = n-1; i >= 1; i--) {
        if(((s[i] - '0') + carry) % 2 == 1) { //odd
            op += 2;
            carry = 1;
        } else {
            op += 1;
        }
    }
    return op + carry;
}

int main()
{
    string s = "1101";
    int ans = numSteps(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
