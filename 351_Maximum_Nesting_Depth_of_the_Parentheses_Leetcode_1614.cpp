#include<iostream>
#include<stack>
using namespace std;

// // ▶️ Ask by :  Bloomberg ✯   Facebook ✯  

// // ▶️ Approach-1 (using stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int maxDepth(string s) {
//     int result = 0;
//     stack<char> st;
//     for (char& ch : s) {
//         if (ch == '(') {
//             st.push(ch);
//         } else if (ch == ')') {
//             st.pop();
//         }       
//         result = max(result, (int)st.size());
//     }   
//     return result;
// }


// ▶️ Approach-2 (using constant space)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int maxDepth(string s) {
    int result = 0;
    int openBrackets = 0;
    for (char &ch : s) {
        if (ch == '(') {
            openBrackets++;
        } else if (ch == ')') {
            openBrackets--;
        }      
        result = max(result, openBrackets);
    }  
    return result;
}


int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    int ans = maxDepth(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
