#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

// ▶️ Approach (Simple Simulation)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

string compressedString(string word) {
    string comp = "";
    int n = word.length();
    int i = 0;
    while(i < n) {
        int count = 0;
        char ch   = word[i];
        while(i < n && count < 9 && word[i] == ch) {
            count++;
            i++;
        }
        comp += to_string(count) + ch;
    }
    return comp;
}

int main()
{
    string word = "abcde";
    string ans = compressedString(word);
    cout << "ans is : " << ans << endl;
    return 0;
}
