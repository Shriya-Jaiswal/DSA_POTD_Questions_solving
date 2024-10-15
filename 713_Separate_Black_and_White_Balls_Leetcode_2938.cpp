#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  1Kosmos ✯ 

// // ▶️ Approach-1 (straight forward traversal)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

//  long long minimumSteps(string s) {
//         int n = s.length();

//         long long swap  = 0;
//         int black = 0;

//         for(int i = 0; i < n; i++) {
//             if(s[i] == '0') { //move white to left
//                 swap += black;
//             } else {
//                 black++;
//             }
//         }

//         return swap;
//     }

// ▶️ Approach-2 (Reversed traversal)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

long long minimumSteps(string s) {
    int n = s.length();

    long long swap  = 0;
    int white = 0;

    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') { // 👉 move black to right
            swap += white;
        } else {
            white++;
        }
    }

    return swap;
}

int main()
{
    string s = "101";
    long long ans = minimumSteps(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
