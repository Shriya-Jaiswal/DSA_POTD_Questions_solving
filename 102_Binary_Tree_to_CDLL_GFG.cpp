#include<iostream>
#include<queue>
using namespace std;

// ▶️ Ask by --> Amazon  SAPLabs

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }
        //no the first node 
        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;
        while(data != -1) {
                root = insertIntoBST(root, data);
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



Node *concate(Node *left_cdll, Node *present_cdll){
    if(!left_cdll){
        return present_cdll;
    }
    if(!present_cdll){
        return left_cdll;
    }
    Node *left_end = left_cdll -> left;
    Node *right_end = present_cdll -> left;
    left_end -> right = present_cdll;
    present_cdll -> left = left_end;
    left_cdll -> left = right_end;
    right_end -> right = left_cdll;
    return left_cdll;
}

Node *bTreeToCList(Node *root){
    if(!root){
        return NULL;
    }
    Node *left_cdll = bTreeToCList(root -> left);
    Node *right_cdll = bTreeToCList(root -> right);
    root -> left = root -> right = root;
    Node *left_half = concate(left_cdll, root);
    Node *right_half = concate(left_half, right_cdll);
    return right_half;
}

// ⏲️ Expected time complexity: O(N)
// 🛢️ Expected auxiliary space: O(h) , where h = height of tree

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    Node* ans = bTreeToCList(root);
    levelOrderTraversal(ans);
    return 0;
}

// 1 3 -1 -1 2 -1 -1 
// 10 20 40 -1 -1 60 -1 -1 30 -1 -1