#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

// // ▶️ Ask by :  LinkedIn ✯   Amazon ✯   Facebook ✯   Google ✯   Yahoo ✯  

// // ▶️ Approach-1 (Using Recrusion + Memoization) -> Why DP ? (See my video above)
// // ⏲️ Time Complexity : O(n*n)
// // 🛢️ Space Complexity : O(n*n)

// int t[101][101];
// bool solve(int idx, int open, string& s, int n) {
//     if(idx == n) {
//         return open == 0;
//     }
        
//     if(t[idx][open] != -1) {
//         return t[idx][open] == 1 ? true : false;
//     }
        
//     bool isValid = false;
        
//     if(s[idx] == '*') {
//         if(open > 0)
//             isValid |= solve(idx+1, open-1, s, n); //Treating * as )
            
//         isValid |= solve(idx+1, open+1, s, n); //Treating * as (
            
//         isValid |= solve(idx+1, open, s, n);   //Treating * as ''
//     } else if(s[idx] == '(') {
//         isValid |= solve(idx+1, open+1, s, n);
//     } else if(open > 0) {
//         isValid |= solve(idx+1, open-1, s, n);
//     }
        
//     return t[idx][open] = isValid;
// }
    
// bool checkValidString(string s) {
//     int n = s.length();
//     memset(t, -1, sizeof(t));
//     return solve(0, 0, s, n);
        
// }

// // ▶️ Approach-2 (Using Bottom Up)
// // ⏲️ Time Complexity : O(n*n)
// // 🛢️ Space Complexity : O(n*n)

// bool checkValidString(string s) {
//     int n = s.size();
//     vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
//     //State Definition :
//     //t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
//     t[n][0] = true;
//     for (int i = n - 1; i >= 0; i--) {
//         for (int open = 0; open <= n; open++) {
//             bool isValid = false;
//             if (s[i] == '*') {
//                 isValid |= t[i + 1][open + 1]; //Treating * as ( --> solve(i+1, open+1)
//                 if (open > 0) {
//                     isValid |= t[i + 1][open - 1]; //Treating * as ) --> solve(i+1, open-1)
//                 }
//                 isValid |= t[i + 1][open]; //Treating * as empty --> solve(i+1, open)
//             } else {
//                 if (s[i] == '(') {
//                     isValid |= t[i + 1][open + 1]; //solve(i+1, open+1)
//                 } else if (open > 0) {
//                     isValid |= t[i + 1][open - 1]; //solve(i+1, open=-1)
//                 }
//             }
//             t[i][open] = isValid;
//         }
//     }
//     return t[0][0];
// }

// // ▶️ Approach-3 (Using two Stacks) - No DP required
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// bool checkValidString(string s) {
//     stack<int> openSt;
//     stack<int> asterisksSt;
//     for (int i = 0; i < s.length(); i++) {
//         char ch = s[i];
//         if (ch == '(') {
//             openSt.push(i);
//         } else if (ch == '*') {
//             asterisksSt.push(i);
//         } else {
//             if (!openSt.empty()) {
//                 openSt.pop();
//             } else if (!asterisksSt.empty()) {
//                 asterisksSt.pop();
//             } else {
//                 return false;
//             }
//         }
//     }
//     //This post processing will be required for cases like - "*(())(*"
//     while (!openSt.empty() && !asterisksSt.empty()) {
//         if (openSt.top() > asterisksSt.top()) {
//             return false;
//         }
//         openSt.pop();
//         asterisksSt.pop();
//     }
//     return openSt.empty();
// }




// ▶️ Approach-4 (Constant Space)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity :O(1)
// ➡️ NOTE : You can easily combine both for loops in just a single for loop. I have written them separately for sake of simplicity and understanding

bool checkValidString(string s) {
    int open = 0;
    int close = 0;
    int n = s.length();
    //Left to Right - Check Open Brackets
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '*') {
            open++;
        } else {
            open--;
        }           
        if (open < 0) {
            return false;
        }
    }
    //Right to Left - Check CLose Brackets
    for (int i = n - 1; i >= 0; i--) {   
        if (s[i] == ')' || s[i] == '*') {
            close++;
        } else {
            close--;
        }       
        if (close < 0) {
            return false;
        }
    }  
    return true;
}


int main()
{
    string s = "()";
    bool ans = checkValidString(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
