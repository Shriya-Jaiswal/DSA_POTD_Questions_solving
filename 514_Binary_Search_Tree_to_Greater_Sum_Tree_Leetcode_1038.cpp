#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        // 👉 this is the firt node we have to create 
        root = new Node(data);
        return root;
    }

    // 👉 not the first node
    if(root -> data > data){
        // 👉 insert in left
        root -> left = insertIntoBST(root -> left, data);
    }
    else{
        // 👉 insert in right
        root -> right = insertIntoBST(root -> right, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}


void levelOrderTraversal(Node* root ) {
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


// ▶️ Ask by :  Amazon ✯   Facebook ✯  

// ▶️ Simple recursive approach
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

void solve(Node* root, int &sum) {
    if(!root) { //root == NULL
        return;
    }
    solve(root->right, sum); //RIGHT is covered
    sum += root->data;
    root->data = sum;
    solve(root->left, sum); //Covergin the left
}

Node* bstToGst(Node* root) {
    int sum = 0;
    solve(root, sum);
    return root;
}

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node in BST1 : " << endl;
    takeInput(root);
    cout << "printing the tree for BSt1 : " << endl;
    levelOrderTraversal(root);
    Node* ans = bstToGst(root);
    levelOrderTraversal(ans);
    return 0;
}
