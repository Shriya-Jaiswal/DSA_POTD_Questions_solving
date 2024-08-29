#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  TikTok ✯   Thoughtspot ✯   Amazon ✯   Google ✯  

// ⏲️ Time Complexity : O(n^2)
// 🛢️ Space Complexity : O(n)

int n ;
void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
    visited[index] = true;
        
    for(int i = 0; i<n; i++) {
        if(!visited[i] &&
            ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
            dfs(stones, i, visited);
        }
    }
}

int removeStones(vector<vector<int>>& stones) {
    n = stones.size();
    vector<bool> visited(n, false);
        
    int count = 0;
    for(int i = 0; i<n; i++) {
        if(visited[i])
            continue;
        dfs(stones, i, visited);
        count++;
    }
        
    return n - count;
}

int main()
{
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    int ans = removeStones(stones);
    cout << "ans is : " << ans << endl;

    return 0;
}
