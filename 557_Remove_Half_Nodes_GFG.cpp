#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
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

void levelOrderTraversalLikeTree(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
	}
}

// ▶️ Ask by : Amazon

Node *RemoveHalfNodes(Node *root) {

    if(!root)return NULL;
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if(!root->left and root->right)return root->right;
    if(root->left and !root->right)return root->left;
    return root;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(height of the binary tree)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    Node* ans = RemoveHalfNodes(root);
    levelOrderTraversalLikeTree(ans);
    return 0;
}

// 5 7 2 -1 -1 -1 8 -1 -1