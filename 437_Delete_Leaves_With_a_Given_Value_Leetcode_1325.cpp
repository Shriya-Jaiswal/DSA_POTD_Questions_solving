#include<iostream>
#include<vector>
#include<queue>
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

// ▶️ Ask by :  Amazon ✯  Dunzo, Sprinkler

// ▶️ Simple Recursion story to code
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(height)

Node* removeLeafNodes(Node* root, int target) {
    if(!root) {
        return NULL;
    }

    root->left  = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if(root->left == NULL && root->right == NULL && root->data == target)
        return NULL;

    return root;    
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    int target = 2;

    Node* ans = removeLeafNodes(root, target);
    levelOrderTraversalLikeTree(ans);
    return 0;
}

// 1 2 2 -1 -1 -1 3 2 -1 -1 4 -1 -1