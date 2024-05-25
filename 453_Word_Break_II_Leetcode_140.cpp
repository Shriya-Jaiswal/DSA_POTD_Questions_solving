#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// // ▶️ Ask by :  Facebook ✯   Amazon ✯   Bloomberg ✯   Apple ✯   Adobe ✯   Google   Microsoft    Meta Phone Screen Interview, Twitter, Snapchat, Dropbox, Uber, GoogleSnapchat  

// // ▶️ Approach-1 (Using simple backtracking)
// // ⏲️ Time Complexity : O(2^n)
// // 🛢️ Space Complexity : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)

// vector<string> result;
// unordered_set<string> dict;

// void solve(int i, string& currSentence, string &s) {
//     if(i >= s.length()) {
//         result.push_back(currSentence);
//         return;
//     }
//     for(int j = i; j < s.length(); j++) {
//         string tempWord = s.substr(i, j-i+1);
//         if(dict.find(tempWord) != dict.end()) {
//             string origSentence = currSentence;
//             if(!currSentence.empty())
//                 currSentence += " ";
//             currSentence += tempWord;
//             solve(j+1, currSentence, s);
//             currSentence = origSentence;
//         }
//     }
// }

// vector<string> wordBreak(string s, vector<string>& wordDict) {
//     for(string &word : wordDict) {
//         dict.insert(word);
//     }

//     string currSentence = "";
//     solve(0, currSentence, s);

//     return result;
// }

// ▶️ Approach-2 (Using simple backtracking)
// ⏲️ Time Complexity : O(2^n)
// 🛢️ Space Complexity : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)


unordered_set<string> dict;
unordered_map<string, vector<string>> mp;

vector<string> solve(string &s) {
    if(s.empty()) {
        return {""};
    }
      
    if(mp.count(s))
        return mp[s];

    if(mp.count(s))
        return mp[s];
        
    vector<string> result;
    for(int l = 1; l <= s.length(); l++) {
        string currWord   = s.substr(0, l);
        if(dict.count(currWord)) {
            string remainWord = s.substr(l);
            vector<string> remainResult = solve(remainWord);
            for(string &w : remainResult) {
                string toAdd = currWord + (w.empty() ? "" : " ") + w;
                result.push_back(toAdd);
            }
        }
    }
    return mp[s] = result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    for(string &word : wordDict) {
        dict.insert(word);
    }

    return solve(s);
}


int main()
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> ans = wordBreak(s,wordDict);
    for(int i=0; i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
