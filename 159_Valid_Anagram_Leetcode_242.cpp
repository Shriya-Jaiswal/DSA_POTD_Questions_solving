#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

// ▶️ Ask by : Facebook 8 | Bloomberg 8 | Amazon 8 | Spotify 8 | Microsoft 6 | Goldman Sachs 3 Affirm 3 Google 2 | Apple 2

// // ▶️ Approach-1 (Using sorting)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

// bool isAnagram(string s, string t) {
//     sort(begin(s), end(s));
//     sort(begin(t), end(t));  
//     return s == t;        
// }


// ▶️ Approach-2 (Using map)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(26) ~ O(1)

 bool isAnagram(string s, string t) {
    vector<int> count(26, 0);   
    for(char &ch : s) {
        count[ch-'a']++;
    } 
    for(char &ch : t) {
        count[ch-'a']--;
    }
    //NOTE : You can also do above in only one for loop.
    /*
        for(int i = 0; i<n; i++) {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
    */ 
    // Check if all elements in the array are 0 --> You can write a for loop as well
    //This is just for learning purpose
    bool allZeros = all_of(begin(count), end(count), [](int element) {
        return element == 0;
    });  
    return allZeros;
}

int main()
{
    string s = "anagram", t = "nagaram";
    bool ans = isAnagram(s,t);  
    cout << "ans is : " << ans << endl;  
    return 0;
}
