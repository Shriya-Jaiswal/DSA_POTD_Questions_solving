#include<iostream>
using namespace std;

// ▶️ Ask by : Flipkart Amazon Microsoft

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


bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2){
        return true;
    }

    if(!r1 || !r2){
        return false;
    }

    if(r1-> data != r2 -> data){
        return false;
    }
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right, r2->right);
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(Height of the Tree).

int main()
{
    Node* r1 = NULL;
    Node* r2 = NULL;
    r1 = buildTree();
    r2 = buildTree();

    bool ans = isIdentical(r1,r2);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 1 2 -1 -1 3 -1 -1
// 1 3 -1 -1 2 -1 -1

