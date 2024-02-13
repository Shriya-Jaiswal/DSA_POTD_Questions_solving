#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : Google

class Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*>mp;

Node* cloneGraph(Node* node) {
    if(node==NULL) return NULL;
    if(mp.find(node)==mp.end()){
        mp[node]= new Node(node->val, {});
        for(auto it:node->neighbors){
            mp[node]->neighbors.push_back(cloneGraph(it));
        }
    }
    return mp[node];   
}


// ⏲️ Expected Time Complexity: O(n + m).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    
    return 0;
}
