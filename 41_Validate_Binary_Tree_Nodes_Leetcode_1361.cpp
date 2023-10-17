#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// ▶️ Ask by Meta


bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    unordered_map<int,vector<int>> adj; // 👉 traversal
    unordered_map<int,int> child_to_parent; // 👉 child to parent

    for(int i=0; i<n; i++){
        int node = i;
        int left_Child = leftChild[i];
        int right_Child = rightChild[i];

        if(left_Child != -1){
            adj[node].push_back(left_Child);

            if(child_to_parent.find(left_Child) != child_to_parent.end()){
                return false;
            }

            child_to_parent[left_Child] = node;
        }


        if(right_Child != -1){
            adj[node].push_back(right_Child);

            if(child_to_parent.find(right_Child) != child_to_parent.end()){
                return false;
            }

            child_to_parent[right_Child] = node;
        }

    }

    // 👉 now here try to know what's the root
    int root = -1;
    for(int i=0; i<n; i++){
        if(child_to_parent.find(i) == child_to_parent.end()){
            if(root != -1){
                return false;
            }
            root = i;
        }
    }


    if(root == -1){
        return false;
    }

    // 👉 here write normal BFS/DFS
    int count = 0;
    queue<int> q;
    vector<bool> visited(n,false);

    q.push(root);
    count = 1;
    visited[root] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int &v : adj[node]){
            // if(visited[v] == true){
            //     return false;
            // }

            if(!visited[v]){
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
    }
    return count == n;
}



int main()
{
    int n = 4;
    vector<int> leftChild {1,-1,3,-1};
    vector<int> rightChild {2,-1,-1,-1};
    bool ans = validateBinaryTreeNodes(n,leftChild,rightChild);
    cout<< "ans is : " << ans << endl;
    return 0;
}
