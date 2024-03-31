#include<iostream>
#include<queue>
#include<limits.h>
#include<algorithm>
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


int ans=INT_MIN;
    
void solve(Node* root, int n){
    if(root==NULL) return;   
    if(root->data <= n){
        ans = max(ans, root->data);
        solve(root->right, n);
    }
    else{
        solve(root->left, n);
    }
    return;
}
int findMaxForN(Node* root, int n) {
    solve(root, n);
    if(ans==INT_MIN){
        ans=-1;
    }
    return ans;     
}

// ⏲️ Expected Time Complexity: O(Height of the BST)
// 🛢️ Expected Auxiliary Space: O(Height of the BST).


int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    int n = 24;

    int ans = findMaxForN(root,n);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 5 2 1 3 12 9 21 19 25 -1
