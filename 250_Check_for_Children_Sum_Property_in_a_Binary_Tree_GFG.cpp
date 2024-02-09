#include<iostream>
#include<vector>
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

// ▶️ Ask by : Intuit

bool f(Node* root){
    if(root==NULL) return true;
    if(!root->left && !root->right) return true;
        
    bool left=true;
    bool right=true;
        
    int sum=0;
    if(root->left !=NULL){
        sum+=root->left->data;
        if(f(root->left)==false) return false;
    }
    if(root->right !=NULL){
        sum+=root->right->data;
        if(f(root->right)==false) return false;
    }
    return root->data==sum;   
}
   
int isSumProperty(Node *root){
    return f(root);
}


// ⏲️ Expected Time Complexiy: O(n).
// 🛢️ Expected Auxiliary Space: O(Height of the Tree).

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;
    int ans = isSumProperty(root);
    cout << "ans is " << ans << endl;

    return 0;
}
// 35 20 15 -1 -1 5 -1 -1 15 10 -1 -1 5 -1 -1
// 1 4 5 -1 -1 3 -1 -1
