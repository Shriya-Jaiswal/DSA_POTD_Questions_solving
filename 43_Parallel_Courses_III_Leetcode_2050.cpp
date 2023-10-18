#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include <cmath>
using namespace std;

// ▶️ leetcode Hard --> Ask by Printerest,Uber


int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int,vector<int>> adj;
    vector<int> indegree(n,0);

    for(int i=0; i<relations.size(); i++){
        int u = relations[i][0] - 1;
        int v = relations[i][1] -1;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int>q;
    vector<int> maxTime(n,0);

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
            maxTime[i] = time[i];
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v : adj[u]){
            
            maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);

            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    return *max_element(begin(maxTime), end(maxTime));
}

int main()
{
    int n = 3;
    vector<vector<int>> relations {{1,3},{2,3}};
    vector<int> time {3,2,5};

    int ans = minimumTime(n,relations,time);
    cout << "ans is : " << ans << endl;

    return 0;
}
