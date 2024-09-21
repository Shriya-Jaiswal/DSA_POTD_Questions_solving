#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Tiktok ✯   Facebook ✯   Uber ✯   Bloomberg ✯   Apple   ByteDance  

// ▶️ Approach (Simple Recursion - DFS)
// ⏲️ Time Complexity : O(n) - We visit each number (1 to n) only once.
// 🛢️ Space Complexity : O(d) - where d is the number of digits in n i.e. log10(n)

void solve(int curr, int n, vector<int>& result) {
    if(curr > n)
        return;
        
    result.push_back(curr);

    for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
        int nextnum = curr*10 + nextDigit;
            
        if(nextnum > n)
            return;
            
        solve(nextnum, n, result);
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> result;
        
    for(int num = 1; num <= 9; num++)
        solve(num, n, result);
        
    return result;
}

int main()
{
    int  n = 13;
    vector<int> ans = lexicalOrder(n);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i]<< " ";
    }
    return 0;
}
