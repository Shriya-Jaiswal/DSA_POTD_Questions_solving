#include<iostream>
#include<queue>
using namespace std;


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


bool isbalanced = true;
int height(struct Node* node){
    // 👉 base case
    if(node == NULL){
        return 0;
    }

    int leftHeight = height(node -> left);
    int rightHeight = height(node -> right);

    // 👉 check for current node , is it balanced
    if(isbalanced && abs(leftHeight - rightHeight) > 1){
        isbalanced = false;
    }
    return max(leftHeight, rightHeight) + 1;
}



int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int ans = height(root);
    cout << "ans is : " <<  ans << endl;
    return 0;
}


// 100 50 150 40 60 175 110 -1 
// 2 1 3 -1
