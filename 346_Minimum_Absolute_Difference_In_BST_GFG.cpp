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

// ▶️

int ans=INT_MAX;
    
void solve(Node* root, int&last){
    if(!root) return;
        
    solve(root->left, last);
    if(last!=-1){
        ans=min(ans, root->data - last);
    }
    last=root->data;
    solve(root->right, last);
}
    
int absolute_diff(Node *root){
    int last=-1;
    solve(root, last);
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(Height of tree)

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    int ans = absolute_diff(root);
    cout << "ans is : " << ans << endl;

    return 0;
}
//  50 30 20 70 60 80 -1