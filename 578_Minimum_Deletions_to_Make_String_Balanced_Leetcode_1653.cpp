#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

// // ▶️ Ask by :  Microsoft ✯   Adobe ✯  

// // ▶️ Approach-1 (Using stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n) 

// int minimumDeletions(string s) {
//     int n = s.length();
//     int count = 0;

//     stack<char> st;

//     for(int i = 0; i < n; i++) {
//         if(!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
//             st.pop();
//             count++;
//         } else {
//             st.push(s[i]);
//         }
//     }

//     return count;
// }


// // ▶️ Approach-2 (3 Pass + O(2*n) space)
// // ⏲️ Time Complexity : O(3*n)
// // 🛢️ Space Complexity : O(2*n)

// int minimumDeletions(string s) {
//     int n = s.length();
//     vector<int> left_b(n, 0);
//     vector<int> right_a(n, 0);
//     int countb = 0;
//     for(int i = 0; i < n; i++) {
//         left_b[i] = countb;
//         if(s[i] == 'b')
//             countb++;
//     }
//     int counta = 0;
//     for(int i = n-1; i >= 0; i--) {
//         right_a[i] = counta;
//         if(s[i] == 'a')
//             counta++;
//     }
//     int count = INT_MAX;
//     for(int i = 0; i < n; i++) {
//         count = min(count, left_b[i] + right_a[i]);
//     }
//     return count;
// }


// // ▶️ Approach-3 (2 Pass + O(n) space)
// // ⏲️ Time Complexity : O(2*n)
// // 🛢️ Space Complexity : O(n)

// int minimumDeletions(string s) {
//     int n     = s.length();  
//     int counta = 0;
//     for(int i = n-1; i >= 0; i--) {
//         if(s[i] == 'a')
//             counta++;
//     }
//     int count = INT_MAX;
//     int countb = 0;
//     for(int i = 0; i < n; i++) {
//         if(s[i] == 'a')
//             counta--;
//         count = min(count, countb + counta);
//         if(s[i] == 'b')
//             countb++;
//     }
//     return count;
// }

// ▶️ Approach-4 (Constant space)
// ⏲️ Time Complexity : O(2*n)
// 🛢️ Space Complexity : O(1)

int minimumDeletions(string s) {
    int n = s.length();
    vector<int> right_a(n, 0);
    int counta = 0;
    for(int i = n-1; i >= 0; i--) {
        right_a[i] = counta;
        if(s[i] == 'a')
            counta++;
    }
    int count = INT_MAX;
    int countb = 0;

    for(int i = 0; i < n; i++) {
        count = min(count, countb + right_a[i]);
        if(s[i] == 'b')
            countb++;
    }
    return count;
}


int main()
{
    string s = "aababbab";
    int ans = minimumDeletions(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
