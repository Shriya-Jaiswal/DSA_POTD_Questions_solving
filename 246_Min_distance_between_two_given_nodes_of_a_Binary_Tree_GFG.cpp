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

// ➡️ Ask by : Amazon | Samsung | MakeMyTrip | Ola Cabs | Linkedin | Qualcomm

Node* lca(Node* root,int a, int b){
    if(!root) return NULL;
    if(root->data==a or root->data==b) return root;
    Node* left=lca(root->left,a,b);
    Node* right=lca(root->right,a,b);
    if(left && right) return root;
    if(left) return left;
    return right;
}
int solve(Node* root,int val){
    if(!root) return 0;
    if(root->data==val) return 1;
    int a=solve(root->left,val);
    int b=solve(root->right,val);
    if(!a and !b) return 0;
    else return a+b+1;
}
    
int findDist(Node* root, int a, int b) {
    Node* node=lca(root,a,b);
    int x=solve(node,a);
    int y=solve(node,b);
    return x+y-2;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(Height of the Tree).

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int a = 2;
    int b = 3;
    int ans = findDist(root, a, b);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 1 2 -1 -1 3 -1 -1
// 11 22 44 -1 -1 55 -1 -1 33 66 -1 -1 77 -1 -1