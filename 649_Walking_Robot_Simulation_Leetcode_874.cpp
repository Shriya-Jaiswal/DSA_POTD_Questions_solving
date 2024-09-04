#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// ▶️ Ask by :  Jane Street ✯  

// ▶️ Simple Simulation
// ⏲️ Time Complexity : O(m + n * maxValCommand), m = size of obstacles, n = size of commands
// 🛢️ Space Complexity : O(m)

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<string> st;
    for(vector<int>& obs : obstacles) {
        string key = to_string(obs[0]) + "_" + to_string(obs[1]);
        st.insert(key);
    }

    int x = 0;
    int y = 0;
    int maxD = 0;

    // 👉 Pointing to North
    pair<int, int> dir = {0, 1}; //N

    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == -2) { // 👉 left 90 degree
            dir = {-dir.second, dir.first};
        } else if(commands[i] == -1) { // 👉 right 90 degree
            dir = {dir.second, -dir.first};
        } else { // 👉 move to the direction step by step
            for(int step = 0; step < commands[i]; step++) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                string nextKey = to_string(newX) + "_" + to_string(newY);

                if(st.find(nextKey) != st.end()) {
                    break;
                }
                x = newX;
                y = newY;
            }
        }
        maxD = max(maxD, x*x + y*y);
    }
    return maxD;
}

int main()
{
    vector<int>  commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    int ans = robotSim(commands,obstacles);
    cout << "ans is : " << ans << endl;
    return 0;
}
