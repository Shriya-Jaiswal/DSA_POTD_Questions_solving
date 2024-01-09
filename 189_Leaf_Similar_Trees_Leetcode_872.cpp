#include<iostream>
#include<vector>
using namespace std;

//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here

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


void inOrder(Node* root, string &s) {
    if(root == NULL) return;
        
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        s += to_string(root->data) + "_";
        return;
    }
        
    inOrder(root->left, s);
    inOrder(root->right, s);
}


bool leafSimilar(Node* root1, Node* root2) {
    string s1 = "";
    string s2 = "";
        
    inOrder(root1, s1);
    inOrder(root2, s2);
        
    return s1==s2;   
}


int main()
{
    Node* root1 = NULL;
    root1 = buildTree();

    Node* root2 = NULL;
    root2 = buildTree();

    bool ans = leafSimilar(root1,root2);
    cout<< "ans is : " << ans << endl;
    return 0;
}


// 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 9 -1 -1 8 -1 -1
// 3 5 6 -1 -1 7 -1 -1 1 4 -1 -1 2 9 -1 -1 8 -1 -1