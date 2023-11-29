#include<iostream>
#include<vector>
using namespace std;

int isEulerCircuit(int V, vector<int>adj[]){
	int odd = 0;
    for (int i = 0; i < V; ++i) {
        if (adj[i].size() % 2 != 0){
            odd += 1;
        }
    }       
    if (odd > 2) {
        return 0;
    }
    return (odd == 0) ? 2 : 1;       
}

// ⏲️ Expected Time Complexity: O(V+E) where E is the number of edges in graph.
// 🛢️ Expected Space Complexity: O(V)

int main()
{
    // int v = 3;
    // vector<int> adj[] = {0,1,2};
    // int ans = isEulerCircuit(v,adj);
    // cout << "ans is : " << ans << endl;

    return 0;
}
