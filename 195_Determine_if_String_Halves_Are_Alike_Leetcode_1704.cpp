#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// // ➡️ Approach-1 (without Using Set)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// bool isVowel(char &ch) {
//     return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
//         ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
// }

// bool halvesAreAlike(string s) {
//     int n = s.length();
        
//     int mid = n/2;
        
//     int i = 0, j = mid;
        
//     int countL = 0;
//     int countR = 0;
        
//     while(i < n/2 && j < n) {
//         if(isVowel(s[i])) countL++;
            
//         if(isVowel(s[j])) countR++;
//             i++;
//             j++;
//         }    
//     return countL == countR;
// }


// ▶️ Approach-1 (without Using Set)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Coplexity : O(n)

bool halvesAreAlike(string s) {
    int n = s.length();
        
    int mid = n/2;
        
    int i = 0, j = mid;
        
    int countL = 0;
    int countR = 0;
        
    string vowels = "aeiouAEIOU";
    unordered_set<char> st(begin(vowels), end(vowels));
        
    while(i < n/2 && j < n) {
        if(st.find(s[i]) != st.end()) countL++;
            
        if(st.find(s[j]) != st.end()) countR++;
            
        i++;
        j++;
    }
        
        
    return countL == countR;
}

int main()
{
    string s = "book";
    bool ans = halvesAreAlike(s);
    cout << "ans is : "<< ans << endl;
    return 0;
}
