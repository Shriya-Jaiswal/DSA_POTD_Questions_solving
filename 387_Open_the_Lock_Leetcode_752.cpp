#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

// ▶️ Ask by :  JPMorgan and Chase ✯   Uber ✯   Amazon ✯   Google ✯   ByteDance ✯  META

// Similar Question :  1. Word Ladder (Leetcode) 
//                     2. Gene Mutation (Leetcode)
//                     3. Sequential Digits (Leetcode)
//                     4. Print all Jumping Numbers smaller than or equal to a given value (GFG)


// ▶️ Using BFS
// ⏲️ Time Complexity : We have n = 10 slots in each wheel and we have w = 4 wheels. In worst case we will explore all possible combinations.
//      Total Combinations = O(n^w)
// 🛢️ Space Complexity : In worst case we will store all possible combinations in queue O(n^w)

void fillNeighbors(queue<string>& que, string& curr, unordered_set<string>& dead) {
    for(int i = 0; i<4; i++) {
        char ch  = curr[i];

        char dec = ch=='0' ? '9' : ch-1;
        char inc = ch=='9' ? '0' : ch+1;

        curr[i]  = dec;
        if(!dead.count(curr)) {
            dead.insert(curr);
            que.push(curr);
        }

        curr[i] = inc;
        if(!dead.count(curr)) {
            dead.insert(curr);
            que.push(curr);
        }
        curr[i] = ch;
    }
}
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(begin(deadends), end(deadends));
        
    string start = "0000";        
    if(dead.count(start))
        return -1;
        
    queue<string> que;
    que.push(start);
        
    int level = 0;
    while(!que.empty()) {
        int n = que.size();
            
        while(n--) {
            string curr = que.front();
            que.pop();
            if(curr == target)
                return level;
                
            fillNeighbors(que, curr, dead);
        }
        level++;
    }
    return -1;
}

int main()
{
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    int ans = openLock(deadends,target);
    cout << "ans is : " << ans << endl;
    return 0;
}
