#include<iostream>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Bloomberg ✯   Apple ✯   Microsoft ✯   Oracle ✯   Goldman Sachs   Facebook   Yahoo   Qualtrics  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(26) ~ O(1)

 int firstUniqChar(string s) {
    int arr[26] = {0};   
    for(char &ch : s) {
        arr[ch-'a']++;
    }   
    for(int i = 0; i < s.length(); i++) {
        if(arr[s[i]-'a'] == 1) {
            return i;
        }
    }  
    return -1;
}


int main()
{
    string s = "loveleetcode";
    int ans = firstUniqChar(s);
    cout <<"ans is : " << ans << endl;
    return 0;
}
