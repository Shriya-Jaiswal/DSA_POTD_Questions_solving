#include<iostream>
#include<vector>
using namespace std;


// // ▶️ Approach-1 (creating a reversed string)
// // ⏲️ Time Complexity : O(m*n) - m = number of words, n = max length length of words
// // 🛢️ Space Complexity : O(n) - Creating a reversed string


// string firstPalindrome(vector<string>& words) {
//     for(string &word : words) {
//         if(word == string(rbegin(word), rend(word))) {
//             return word;
//         }
//     }
//     return "";        
// }

// ▶️ Approach-2 (using equal)
// ⏲️ Time Complexity : O(m*n) - m = number of words, n = max length length of words
// 🛢️ Space Complexity : O(1)


string firstPalindrome(vector<string>& words) {    
    for(string &word : words) {
        if(equal(word.begin(), word.begin() + word.size() / 2, word.rbegin())) {
            return word;
        }
    }   
    return "";        
}

int main()
{
    vector<string>  words = {"abc","car","ada","racecar","cool"};
    string ans = firstPalindrome(words);
    cout << "ans is : " << ans << endl;
    return 0;
}
