#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
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


// ▶️ Ask by : Flipkart | Amazon | Microsoft | Samsung | D-E-Shaw

bool isBST(Node* root,int mn, int mx){
    if(!root) return true;
    if(root->data < mn || root->data > mx ) return false;
    return isBST(root->left, mn, root->data-1) && isBST(root->right,root->data+1,mx);
}
    
int sizeOfBst(Node* root){
    if(root==NULL) return 0;
    queue<Node *> q;
    q.push(root);
    int count=1;
    while(!q.empty()){
        Node * node=q.front();
        q.pop();
        if(node->left){
            q.push(node->left);
            count++;
        }
        if(node->right){
            q.push(node->right);
            count++;
        }
    }
    return count;
}
    
int largestBst(Node *root)
{
    queue<Node*> q;
    int ans=0;
    q.push(root);
    while(!q.empty()){
    	Node* node=q.front();
    	q.pop();
    	if(isBST(node, INT_MIN, INT_MAX)){
    	    int size=sizeOfBst(node);
    	    ans=max(ans,size);
    	}
    	if(node->left) q.push(node->left);
    	if(node->right) q.push(node->right);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(Height of the BST).

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int ans = largestBst(root);
    cout << "ans is : " << ans << endl; 
    return 0;
}
// 1 4 6 -1 -1 8 -1 -1 4 -1 -1