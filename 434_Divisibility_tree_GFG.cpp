#include<iostream>
#include<vector>
using namespace std;

int ans=0;
int dfs(vector<int>adj[], vector<int>&vis, int start){
    vis[start]=1;
    int cnt=0;
    for(auto it:adj[start]){
        if(!vis[it]){
            int res=dfs(adj, vis, it);
            if(res%2==0){
                ans++;
            }
            else{
                cnt+=res;
            }
        }
    }
    return cnt+1;
}

int minimumEdgeRemove(int n, vector<vector<int>>edges){
	vector<int>adj[n];
	for(int i=0;i<edges.size();i++){
	    adj[edges[i][0]-1].push_back(edges[i][1]-1);
	    adj[edges[i][1]-1].push_back(edges[i][0]-1);
	}
	    
	vector<int>vis(n,0);
	dfs(adj, vis, 0);  
	return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(n)


int main()
{   
    int n = 4;
    vector<vector<int>> edges = {{2,1},{4,2},{1,3}};
    int ans = minimumEdgeRemove(n,edges);
    cout << "ans is : " << ans << endl;
    return 0;
}
