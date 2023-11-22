#include<iostream>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft

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


// ➡️ return true/false denoting whether the tree is Symmetric or not
bool check(Node* left, Node* right) {
    if (left == NULL && right == NULL){
        return true;
    }
    if (left == NULL || right == NULL || left->data != right->data){
        return false;
    }
    return check(left->left, right->right) && check(left->right, right->left);
}

bool isSymmetric(struct Node* root){
	if (root == NULL){
    return true;
    }
    return check(root->left, root->right);
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(Height of the Tree).

int main()
{
    Node* root = NULL;
    root = buildTree();
    bool ans = isSymmetric(root);
    cout << "ans is : " << ans << endl;
    return 0;
}


// 5 1 2 -1 -1 -1 1 -1 2 -1 -1 