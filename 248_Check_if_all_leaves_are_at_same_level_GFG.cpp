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

// ▶️ Ask by : Amazon


bool check(Node *root)
{
    if(root==NULL) return true;
    queue<Node* > q;
    q.push(root);
    int level=0;
    int leaf=-1;
    while(!q.empty()){
        int n=q.size();
        level++;
            
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
                
            if(!curr->left && !curr->right){
                //i have encountered a leaf node
                if(leaf==-1){
                    leaf=level;
                }
                else if(leaf!=level){
                    return false;
                }
            }
                
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }   
    }
    return true;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(height of tree)

int main()
{
    Node* root = NULL;
    cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;
    bool ans = check(root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 1 2 -1 -1 3 -1 -1