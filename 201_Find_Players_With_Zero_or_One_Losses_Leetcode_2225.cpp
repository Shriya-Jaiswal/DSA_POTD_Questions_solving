#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Palantir Technologies ✯   Indeed ✯  

// ⏲️ Time Complexity : O(n*logn)
// 🛢️ Space Complexity : O(n)

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> lost;
        
    for(auto &it : matches) {
        int lose = it[1];
        lost[lose]++;
    }
        
    vector<int> notLost;
    vector<int> oneLos;
        
    for(auto &it : matches) {
        int lose = it[1];
        int win  = it[0];
            
        if(lost[lose] == 1) {
            oneLos.push_back(lose);
        }
        if(lost.find(win) == lost.end()) {
            notLost.push_back(win);
            lost[win] = 2;
        }
            
    }
        
    sort(begin(notLost), end(notLost));
    sort(begin(oneLos), end(oneLos));
        
    return {notLost, oneLos}; 
}

int main()
{
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> ans = findWinners(matches);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
