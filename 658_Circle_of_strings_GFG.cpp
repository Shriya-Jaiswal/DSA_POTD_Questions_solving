#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : Flipkart | Accolite | Microsoft | FactSet

int isCircle(vector<string> &arr) {
    int n = arr.size();
    vector<int> vis(n,0),indegree(26,0),outdegree(26,0);
    unordered_map<char,vector<int>> mm;
    queue<int> q;
    for(int i=0;i<n;i++){
        indegree[arr[i][0]-'a']++;
        outdegree[arr[i].back()-'a']++;
        mm[arr[i][0]].push_back(i);
    }
    for(auto x:mm){
        if(indegree[x.first-'a']!=outdegree[x.first-'a'])return 0;
    }
    q.push(0);
    vis[0]=1;
    int ans = 1;
    while(!q.empty()){
        int index = q.front();
        q.pop();
        for(auto x:mm[arr[index].back()]){
            if(!vis[x]){
                ans++;
                vis[x]=1;
                q.push(x);
            }
        }
    }
    return ans==n;
        
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    vector<string>  arr = {"abc", "bcd", "cdf"};
    int ans = isCircle(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
