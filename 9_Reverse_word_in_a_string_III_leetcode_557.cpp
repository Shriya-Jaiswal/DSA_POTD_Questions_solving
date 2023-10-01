#include<iostream>
#include<algorithm>
using namespace std;


//  string reverseWords(string s) {
//         int l=0;
//         int r =0;
//         while( l < s.length() ){
//             while( r < s.size() && s[r] != ' '){
//                 r++;
//             }
//             reverse(s.begin()+l , s.begin()+r);
//             l = r + 1;
//             r = l;
//         }
//         return s;
//     }

// ➡️ Approach 2 
string reverseWords(string s) {
    string ans  = "";
    int i = 0;
    int n = s.length();
    while(i < n){
        int j = i;
        while(j < n && s[j] != ' '){
            j++;
        }
        string curr = s.substr(i,j-i);
            // cout << curr << " " << i << " " << j << endl;
            reverse(curr.begin(), curr.end());
            ans += curr;
            ans += " ";
            i = j + 1;
    }
    ans.pop_back();
    return ans;
}
// ⏲️ time complaxity ---> traverse string O(n) * reverse the string take O(n) ===> total O(n^2)
// 🛢️ space complaxity --> O(n) --> for ans variable to taking ans --> n is a length of string

int main()
{
    string s = "Let's take LeetCode contest";
    string ans = reverseWords(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
