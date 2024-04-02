#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   LinkedIn ✯   Google ✯  

// // ▶️ Using array of size 256
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1) -> Take array of size 256 to handle all ASCII characters instead of taking map

// bool isIsomorphic(string s, string t) {
//     vector<int> mp1(256, -1);
//     vector<int> mp2(256, -1);
//     int n = s.length();
        
//     for(int i = 0; i<n; i++) {
//         char ch1 = s[i];
//         char ch2 = t[i];
            
//         if((mp1[ch1] != -1 && mp1[ch1] != ch2) ||
//             (mp2[ch2] != -1  && mp2[ch2] != ch1)
//             )
//             return false;
//             mp1[ch1] = ch2;
//             mp2[ch2] = ch1;
//         }
//     return true;
// }


// ▶️ Using unordered_map
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) -> size of map will not exceed 256

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;
    int m = s.length();
    for(int i = 0; i < m; i++) {
        char ch1 = s[i];
        char ch2 = t[i];
        if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || 
            mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1
            ) {
            return false;
        }       
        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "add";

    bool ans = isIsomorphic(s,t);
    cout << "ans is : " << ans << endl;
    return 0;
}
