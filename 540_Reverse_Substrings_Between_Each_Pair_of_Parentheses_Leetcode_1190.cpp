#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// // ▶️ Ask by :  Microsoft ✯   Paypal ✯   META, AMAZON

// // ▶️ Approach-1 (Brute Force)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(n)

// string reverseParentheses(string s) {
//     stack<int> openeBracket; //You can use a vector also as stack
//     string result;
//     for (char currentChar : s) {
//         if (currentChar == '(') {
//             openeBracket.push(result.length());
//         } else if (currentChar == ')') {
//             int start = openeBracket.top();
//             openeBracket.pop();
//             reverse(result.begin() + start, result.end());
//         } else {
//             result += currentChar;
//         }
//     }
//     return result;
// }


// ▶️ Approach-2 (Linear Approach)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

string reverseParentheses(string s) {
    int n = s.length();
    stack<int> openBracket;
    vector<int> door(n);

    // First pass: Pair up parentheses
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            openBracket.push(i);
        } else if (s[i] == ')') {
            int j = openBracket.top();
            openBracket.pop();
            door[i] = j;
            door[j] = i;
        }
    }

    // Second pass: Build the result string
    string result;
    int direction = 1; //Left to Right
    for (int i = 0; i < n; i += direction) {
        if (s[i] == '(' || s[i] == ')') {
            i = door[i];
            direction = -direction;
        } else {
            result += s[i];
        }
    }
    return result;
}

int main()
{
    string s = "(abcd)";
    string ans = reverseParentheses(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
