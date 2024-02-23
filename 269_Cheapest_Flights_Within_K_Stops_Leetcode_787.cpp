#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>
using namespace std;

// ▶️ Ask by :  Airbnb ✯   Amazon ✯   Facebook ✯   Coupang ✯   TikTok ✯   Google   Apple   Cisco   Microsoft   Snapchat   Expedia   InMobi   Bloomberg   Qualtrics   Uber   Wish  

// ➡️ Approach-1 (BFS)
// ⏲️ Time Cmlexity : O(V+E) - BFS traversal of Graph
// 🛢️ S.C : O(V+E)


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int> &vec : flights) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que;
        que.push({src, 0});
        distance[src] = 0;
        
        int level = 0;
        
        while(!que.empty() && level <= k) {
            int N = que.size();
            
            while(N--) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();
                
                for(pair<int, int> &P : adj[u]) {
                    
                    int v    = P.first;
                    int cost = P.second;
                    
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        que.push({v, d+cost});
                    }
                    
                }
                
            }
            level++;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
}

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = findCheapestPrice(n,flights,src,dst,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
