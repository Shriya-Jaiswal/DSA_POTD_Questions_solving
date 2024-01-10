#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){

    int data;
    cout <<"Enter root data " << endl;
    cin >> data;

     if(data == -1){
        return NULL;
    }

    // 👉 1 case solve
    Node* root = new Node(data);

    cout << "Enter data for left child of : "<< endl;
    root -> left = buildTree();

    cout << "Enter data for right child of : "<< endl;
    root -> right = buildTree();

    return root;
}

// ➡️ Approach-1 (Convert tree to graph)
// ⏲️ Time Complexity : O(n) - visiting all nodes
// 🛢️ Space Complexity : O(n) - storing all nodes in graph


void convert(Node* current, int parent, unordered_map<int, vector<int>>& adj) {
    if (current == nullptr) {
        return;
    }

    if (parent != -1) {
        adj[current->data].push_back(parent);
    }

    if (current->left != nullptr) {
        adj[current->data].push_back(current->left->data);
    } 
    if (current->right != nullptr) {
        adj[current->data].push_back(current->right->data);
    }
    convert(current->left, current->data, adj);
    convert(current->right, current->data, adj);
}


int amountOfTime(Node* root, int start) {
    unordered_map<int, vector<int>> adj;
    convert(root, -1, adj);

    queue<int> que;
    que.push(start);
    unordered_set<int> visited;
    visited.insert(start);
    int minutes = 0;

    while (!que.empty()) {
        int n = que.size();

        while (n--) {
            int curr = que.front();
            que.pop();

            for (int &ngbr : adj[curr]) {
                if (visited.find(ngbr) == visited.end()) {
                    que.push(ngbr);
                    visited.insert(ngbr);
                }
            }
        }
        minutes++;
    }
    return minutes - 1;
}


// ▶️ Approach-2 (Using DFS - one pass solution)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) - Max depth of recursion call stack

int main()
{
    Node* root = NULL;
    root = buildTree();

    int start = 3;

    int ans = amountOfTime(root,start);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 1 5 -1 4 9 -1 -1 2 -1 -1 3 10 -1 -1 6 -1 -1 