#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// ▶️ Ask by ---> Microsoft , Visa ✯   Google ✯  

// // ➡️ Approach-1 (Separate string create and sort)

// bool isVowel(char ch) {
//     ch = tolower(ch);
//     return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
// }

// string sortVowels(string s) {
//     string temp;
//     for(char &ch : s) {
//         if(isVowel(ch)) {
//             temp.push_back(ch);
//         }
//     }
        
//     sort(begin(temp), end(temp));
//     int j = 0;
//     for(int i = 0; i<s.length(); i++) {
//         if(isVowel(s[i])) {
//             s[i] = temp[j];
//             j++;
//         }
//     }
        
//     return s;
// }
// // ⏲️ Time Complexity : O(nlog)



// ▶️ Approach-2 (Without sorting. Counting the vowels - counting sort)
// ⏲️ Time Complexity : O(n)

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
    
string sortVowels(string s) {
    unordered_map<char, int> mp;   
    for(char &ch : s) {
        if(isVowel(ch)) {
            mp[ch]++;
        }
    }
    string temp   = "AEIOUaeiou";
        
    int j = 0; //pointing to temp (current vowel)
        
    for(int i = 0; i<s.length(); i++) {
            
        if(isVowel(s[i])) {
            while(mp[temp[j]] == 0) {
                j++;
            } 
            s[i] = temp[j];
            mp[temp[j]]--;
        }   
    }
    return s;
}

int main()
{
    string  s = "lEetcOde";
    string ans = sortVowels(s);
    cout << "ans is : "<< ans << endl;
    return 0;
}
