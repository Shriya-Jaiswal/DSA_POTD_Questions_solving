#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

// ▶️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

bool isCircularSentence(string sentence) {
    int n = sentence.length();

    for (int i = 0; i < n; i++) {
        if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
            return false;
    }

    return sentence[0] == sentence[n - 1]; // 👉 check last and first
}

int main()
{
    string sentence = "leetcode exercises sound delightful";
    bool ans = isCircularSentence(sentence);
    cout << "ans is : " << ans << endl;
    return 0;
}
