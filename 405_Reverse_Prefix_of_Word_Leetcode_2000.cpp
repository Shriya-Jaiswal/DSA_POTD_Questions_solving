#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Optum ✯  Amazon

// // ▶️ Using simple loop and swap
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// string reversePrefix(string word, char ch) {
//     int i = 0;
//     int j = word.find(ch); 
//     while(i < j) {
//         swap(word[i], word[j]);
//         i++;
//         j--;
//     }  
//     return word;
// }

// ▶️ Using Library Functions
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

string reversePrefix(string word, char ch) {
    reverse(begin(word), word.begin()+word.find(ch)+1);
    return word;       
}

int main()
{
    string  word = "abcdefd";
    char ch = 'd';
    string ans = reversePrefix(word,ch);
    cout << "ans is : " << ans << endl;
    return 0; 
}
