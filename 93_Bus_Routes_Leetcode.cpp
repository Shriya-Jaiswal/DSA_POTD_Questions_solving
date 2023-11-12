#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// ➡️ Approach- (Using BFS)
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
      if (source == target) {
        return 0;
      }

        unordered_map<int, vector<int>> adj;
        
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        
        for (auto route : adj[source]){
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();

            while(size--) {
                int route = que.front();
                que.pop();

                
                for (auto &stop: routes[route]) {
                    
                    if (stop == target) {
                        return busCount;
                    }

                    
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;        
}

// ⏲️ Time Complexity : O(m^2 * k) - m is the size of routes, and k is the maximum size of routes[i].


int main()
{
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1;
    int target = 6;

    int ans = numBusesToDestination(routes,source,target);
    cout << "ans is : " << ans << endl;
    return 0;
}
