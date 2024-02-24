#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<limits.h>
using namespace std;

// // ▶️ Ask by : none


// // ▶️ Approach-1 (Most basic approach that can come to mind)
// // ⏲️ T.C : ~O(M*(M+N)) where M = number of meetings and N = number of people
// // 🛢️ S.C : O(M+N)

// typedef pair<int, int> P;
// vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//     map<int, vector<P>> timeMeetings;
//     for(vector<int>& meeting : meetings) {
//         int person1 = meeting[0];
//         int person2 = meeting[1];
//         int time    = meeting[2];      
//         timeMeetings[time].push_back({person1, person2});
//     }
        
//     vector<bool> knowsSecret(n, false);
//     knowsSecret[0]           = true;
//     knowsSecret[firstPerson] = true;
        
//     // 👉 Solve in increasing time meetings
//     for(auto &it : timeMeetings) {
            
//         int t           = it.first;
//         vector<P> meets = it.second;
            
//         unordered_map<int, vector<int>> adj;
//         queue<int> que;
//         unordered_set<int> alreadyAdded;

//         for(auto& [person1, person2] : meets) {
//             adj[person1].push_back(person2);
//             adj[person2].push_back(person1);
                
//             if(knowsSecret[person1] && alreadyAdded.find(person1) == alreadyAdded.end()) {
//                 que.push(person1);
//                 alreadyAdded.insert(person1);
//             }
//             if(knowsSecret[person2] && alreadyAdded.find(person2) == alreadyAdded.end()) {
//                 que.push(person2);
//                 alreadyAdded.insert(person2);
//             }
//         }
                
//         // 👉 Now I know who meet who based on increasing time
//         // 👉 Let's hit the BFS to spread the secret
            
//         while(!que.empty()) {
//             int person = que.front();
//             que.pop();
                
//             for(auto &nextPerson : adj[person]) {
//                 if(!knowsSecret[nextPerson]) {
//                     knowsSecret[nextPerson] = true;
//                     que.push(nextPerson);
//                 }
//             }
//         }
//     }
        
//     vector<int> result;
//     for(int i = 0; i < n; i++) {
//         if(knowsSecret[i] == true) {
//             result.push_back(i);
//         }
//     }
        
//     return result;
// }


// // ▶️ Approach-2 (Using BFS Graph Traversal)
// // ⏲️ T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people, there can be at most N+M elements in the queue and a person may have M neighbours
// // 🛢️ S.C : O(M+N)


// typedef pair<int, int> P;
// vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//     unordered_map<int, vector<P>> adj;
        
//     for(vector<int>& meeting : meetings) {
//         int person1 = meeting[0];
//         int person2 = meeting[1];
//         int time    = meeting[2];
            
//         adj[person1].push_back({person2, time});
//         adj[person2].push_back({person1, time});
//     }
        
//     queue<P> que;
//     que.push({0, 0});
//     que.push({firstPerson, 0});
//     vector<int> earlySecretTime(n, INT_MAX);
//     earlySecretTime[0] = 0;
//     earlySecretTime[firstPerson] = 0;
        
//     while(!que.empty()) {
//         auto [person, time] = que.front();
            
//         que.pop();
            
//         for(auto& ngbr : adj[person]) {
//             int nextPerson = ngbr.first;
//             int t          = ngbr.second;
                
//             if(t >= time && earlySecretTime[nextPerson] > t) {
//                 earlySecretTime[nextPerson] = t;
//                 que.push({nextPerson, t});
//             }
//         }
//     }
        
//     vector<int> result;
//     for(int i = 0; i < n; i++) {
//         if(earlySecretTime[i] != INT_MAX) {
//             result.push_back(i);
//         }
//     }
        
//     return result;
// }



// // ▶️ Approach-3 (Using DFS Graph Traversal)
// // ⏲️ T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people (Although it's a DFS, but we also revisit some nodes again with better secret knowing time)
// // 🛢️ S.C : O(M+N)

// typedef pair<int, int> P;    
// void dfs(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& earlySecretTime) {
//     for(auto& ngbr : adj[person]) {
//         int nextPerson = ngbr.first;
//         int t          = ngbr.second;

//         if(t >= time && earlySecretTime[nextPerson] > t) {
//             earlySecretTime[nextPerson] = t;
//             dfs(nextPerson, t, adj, earlySecretTime);
//         }
//     }
// }
    
// vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//     unordered_map<int, vector<P>> adj;
        
//     for(vector<int>& meeting : meetings) {
//         int person1 = meeting[0];
//         int person2 = meeting[1];
//         int time    = meeting[2];
            
//         adj[person1].push_back({person2, time});
//         adj[person2].push_back({person1, time});
// }

// vector<int> earlySecretTime(n, INT_MAX);
// earlySecretTime[0] = 0;
// earlySecretTime[firstPerson] = 0;

//     // 👉 Do DFS
//     dfs(0, 0, adj, earlySecretTime);
//     dfs(firstPerson, 0, adj, earlySecretTime);

//     vector<int> result;
//     for(int i = 0; i < n; i++) {
//         if(earlySecretTime[i] != INT_MAX) {
//             result.push_back(i);
//         }
//     }
        
//     return result;
// }


// ▶️ Approach-4 (Using min-heap to fetch earliest time)
// ⏲️ T.C : ~O((N+M) * (log(M+N) + M)) 
// 🛢️ S.C : O(N+M)


typedef pair<int, int> P;
vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
        int person1 = meeting[0];
        int person2 = meeting[1];
        int time    = meeting[2];
            
        adj[person1].push_back({person2, time});
        adj[person2].push_back({person1, time});
    }
        
    priority_queue<P, vector<P>, greater<P>> pq; //I need the ones first having min time
    pq.push({0, 0});
    pq.push({0, firstPerson});
        
    vector<bool> visited(n, false);
        
    while(!pq.empty()) {
        auto [time, person] = pq.top();
        pq.pop();
            
        if(visited[person] == true) {
            continue;
        }
        visited[person] = true;
            
        for(auto& ngbr : adj[person]) {
            int nextPerson = ngbr.first;
            int t          = ngbr.second;
                
            if(t >= time && !visited[nextPerson]) {
                pq.push({t, nextPerson});
            }
        }
    }
        
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(visited[i] == true) {
            result.push_back(i);
        }
    }
        
    return result;
}

int main()
{
    int n = 6;
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    int firstPerson = 1;

    vector<int> ans = findAllPeople(n,meetings,firstPerson);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";     
    }
    cout << endl;
    return 0;
}
