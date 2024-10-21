#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Google ✯  

// ▶️ Approach (Using simple backtracking)
// ⏲️ Time Complexity : O(n*2^n)
// 🛢️ Space Complexity : O(n)

void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
    if(currCount + (s.length() - idx) <= maxCount) { //Pruning for slight improvement
        return;
    }

    if(idx == s.length()) {
        maxCount = max(maxCount, currCount);
    }

    for(int j = idx; j < s.length(); j++) {
        string sub = s.substr(idx, j-idx+1);
        if(st.find(sub) == st.end()) {
            st.insert(sub);
            solve(s, j+1, st, currCount+1, maxCount);
            st.erase(sub);
        }
    }
}

int maxUniqueSplit(string s) {
    unordered_set<string> st;
    int maxCount  = 0;
    int currCount = 0;
    solve(s, 0, st, currCount, maxCount);

    return maxCount;
}

int main()
{
    
    return 0;
}
