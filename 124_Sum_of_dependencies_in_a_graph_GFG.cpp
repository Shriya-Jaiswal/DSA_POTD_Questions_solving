#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Flipkart

int sumOfDependencies(vector<int> adj[], int V) {
    int ans=0;
    for(int i=0;i<V;i++){
        ans+=adj[i].size();
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(V)
// 🛢️ Expected Auxillary Space: O(1)

int main()
{
    int v = 4;
    vector<int> adj[] = { {0,2}, {0,3}, {1,3}, {2,3} };
    int ans = sumOfDependencies(adj,v);
    cout << "ans is : " << ans << endl;
    return 0;
}
