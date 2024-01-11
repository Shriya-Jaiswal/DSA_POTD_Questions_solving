#include<iostream>
#include<climits>
using namespace std;

// ▶️ Ask by : ✯ Amazon  ✯ Google  ✯ Facebook   

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


// // ▶️ Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree
// /*
//   Just simply take a root, find all the differences of it from its childres and find max one
//   Again go to root->left and do the same as above
//   Again go to root->right and do the same as above
// */

// int maxDiff;

// void findMaxUtil(Node* root, Node* child) {
//     if(!root || !child)
//         return;
        
//     maxDiff = max(maxDiff, abs(root->data - child->data));

//     findMaxUtil(root, child->left);
//     findMaxUtil(root, child->right);
// }

// void findMaxDiff(Node* root) {
//     if(!root || !root->left && !root->right)
//         return;
         
//         //Find max differences of this root with all its children
//         findMaxUtil(root, root->left);
//         findMaxUtil(root, root->right);

//         //firther move left and right
//         findMaxDiff(root->left);
//         findMaxDiff(root->right);
// }

// int maxAncestorDiff(Node* root) {
//     maxDiff = INT_MIN;

//     findMaxDiff(root);   

//     return maxDiff;     
// }

// ◀️ Approach-2
// ➡️ Optimal (O(n)) using min and max value for |min-max|

int findMaxDiff(Node* root, int minV, int maxV) {
    if(!root)
        return abs(minV-maxV);
        
    minV = min(root->data, minV);
    maxV = max(root->data, maxV);

    int l = findMaxDiff(root->left,  minV, maxV);
    int r = findMaxDiff(root->right, minV, maxV);

    return max(l, r);
}

int maxAncestorDiff(Node* root) {
    int minV = root->data;
    int maxV = root->data;

    return findMaxDiff(root, minV, maxV);
   
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    int ans = maxAncestorDiff(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1