#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// ▶️ Ask by :  Amazon ✯  

vector<int> result;
void traverse(Node* root) {
    if(!root)
        return;
        
    for(Node*& x : root->children) {
        traverse(x);
    }
        
    result.push_back(root->val);
}
    
   vector<int> postorder(Node* root) {
    result.clear();
    traverse(root);
    return result;
}

int main()
{
    
    return 0;
}
