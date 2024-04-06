#include<iostream>
#include<unordered_set>
#include<stack>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Bloomberg ✯   Amazon ✯   Microsoft ✯   Google ✯   Adobe   Snapchat  

// // ▶️ Approach-1 (Using Stack and set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// string minRemoveToMakeValid(string s) {
//     int n = s.length();
//     unordered_set<int> toRemove;
//     stack<int> st;
        
//     for(int i = 0; i<n; i++) {
//         if(s[i] == '(') //store index of '('
//             st.push(i);
//         else  if(s[i] == ')') {
//             if(st.empty()) { //invalid ')'
//                 toRemove.insert(i);
//             } else {
//                 st.pop(); //balancing with open '('
//             }
//         }
//     }
        
//     //suppose the input is  "(("
//     //Then, we won't be adding them in the toRemove set to remove later
//     //So, adding here
//     while(!st.empty()) {
//         toRemove.insert(st.top());
//         st.pop();
//     }
//     string result = "";   
//     for(int i = 0; i<n; i++) {
//         if(toRemove.find(i) == toRemove.end())
//             result.push_back(s[i]);
//     }  
//     return result;
// }


// // ▶️ Approach-2 (Iterate from front and eliminate and then iterate from back and eliminate)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ S.C : O(n)


// string minRemoveToMakeValid(string s) {
//     string result = "";
//     int n = s.length(); 
//     // 👉 Iterate fron front and eliminate
//     int lastOpen = 0;
//     for(int i = 0; i<n; i++) {
//         char c = s[i];
//         if((c >= 'a' && c <= 'z'))
//             result.push_back(c);
//         else if(c == '(') {
//             result.push_back(c);
//             lastOpen++;
//         } else if(lastOpen > 0) {
//             lastOpen--;
//             result.push_back(c);
//         }
//     }
//     if(result == "")
//         return "";
             
//     s = result;
//     result = "";
//     int lastClose = 0;
//     n = s.length();
//     //Iterate fron back and eliminate
//     for(int i = n-1; i>=0; i--) {
//         char c = s[i];
//         if((c >= 'a' && c <= 'z'))
//             result.push_back(c);
//         else if(c == ')') {
//             result.push_back(c);
//             lastClose++;
//         } else if(lastClose > 0) {
//             lastClose--;
//             result.push_back(c);
//         }
//     }
//     reverse(result.begin(), result.end());
//     return result;
// }


// ▶️ Approach-3 (Simplified : Playing smart and keeping it simple)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)


  string minRemoveToMakeValid(string s) {
        int open = 0;
        string temp = "";
        
        for(char c:s) {
            if(c == '(') {
                open++;
            } else if(c == ')') {
                if(open == 0)
                    continue;
                open--;
            }
            
            temp.push_back(c);
        }
        
        int n = temp.length();
        string result = "";
        for(int i = n-1; i>=0; i--) {
            if(temp[i] == '(' && open-- > 0)
                continue;
            result.push_back(temp[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

int main()
{
    string s = "lee(t(c)o)de)";
    string ans = minRemoveToMakeValid(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
