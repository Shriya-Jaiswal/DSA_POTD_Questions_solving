#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// // ▶️ Ask by :  Mercari ✯  GOOGLE

// // ▶️ Approach-1 (Using simple simulation)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int minOperations(vector<string>& logs) {
//     int depth = 0;

//     for(string &s : logs) {
//         if(s == "../") {
//             depth = max(0, depth-1);
//         } else if(s == "./") {
//              continue;
//         } else {
//             depth++;
//         }
//     }

//     return depth;
// }


// ▶️ Approach-2 (Using Stack for simulation)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

int minOperations(vector<string>& logs) {
    stack<string> st;

    for (const string& currentOperation : logs) {
        if (currentOperation == "../") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (currentOperation != "./") {
            st.push(currentOperation);
        }
    }

    return st.size();
}

int main()
{
    vector<string> logs = {"d1/","d2/","../","d21/","./"};
    int ans = minOperations(logs);
    cout << "ans is : " << ans << endl;
    return 0;
}
