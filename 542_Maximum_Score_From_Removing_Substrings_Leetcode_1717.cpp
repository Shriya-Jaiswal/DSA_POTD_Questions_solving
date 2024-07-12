#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask :  Google ✯  Meta, Amazon

// // ▶️ Approach-1 (Using Stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int maximumGain(string s, int x, int y) {
//     int n     = s.length();
//     int score = 0;

//     string maxStr = (x > y) ? "ab" : "ba";
//     string minStr = (x < y) ? "ab" : "ba";

//     //First Pass
//     string temp_first     = removeSubstring(s, maxStr);
//     int removedPairsCount = (n - temp_first.length()) / 2;
//     score                += removedPairsCount * max(x, y);


//     //Second Pass
//     string temp_second = removeSubstring(temp_first, minStr);
//     removedPairsCount  = (temp_first.length() - temp_second.length()) / 2;
//     score             += removedPairsCount * min(x, y);

//     return score;
// }

// string removeSubstring(string& s, string& matchStr) {
//     stack<char> st;

//     for (char &ch : s) {
//         if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
//             st.pop();
//         } else {
//             st.push(ch);
//         }
//     }

//     string remainStr;
//     while (!st.empty()) {
//         remainStr.push_back(st.top());
//         st.pop();
//     }
//     reverse(remainStr.begin(), remainStr.end());
//     return remainStr;
// }



// ▶️ Approach-2 (Without Stack)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int maximumGain(string s, int x, int y) {
    int n     = s.length();
    int score = 0;

    string maxStr = (x > y) ? "ab" : "ba";
    string minStr = (x < y) ? "ab" : "ba";

    //First Pass
    string temp_first     = removeSubstring(s, maxStr);
    int L                 = temp_first.length();
    int removedPairsCount = (n - L) / 2;
    score                += removedPairsCount * max(x, y);


    //Second Pass
    string temp_second = removeSubstring(temp_first, minStr);
    removedPairsCount  = (L - temp_second.length()) / 2;
    score             += removedPairsCount * min(x, y);

    return score;
}

string removeSubstring(string& inputString, string& matchStr) {
    int j = 0;

    for (int i = 0; i < inputString.size(); i++) {
        inputString[j++] = inputString[i];

        if (j > 1 &&
            inputString[j - 2] == matchStr[0] &&
            inputString[j - 1] == matchStr[1]) {
            j -= 2;
        }
    }

    inputString.erase(inputString.begin() + j, inputString.end());

    return inputString;
}

int main()
{
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    int ans = maximumGain(s,x,y);
    cout << "ans is : " << ans << endl;
    return 0;
}
