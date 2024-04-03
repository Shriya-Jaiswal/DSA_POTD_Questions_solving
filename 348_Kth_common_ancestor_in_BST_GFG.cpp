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


Node* LCA(Node* root, int x, int y){
    if(!root) return NULL;
    if(root->data==x || root->data==y) return root;
    else if(root->data<x && root->data<y) return LCA(root->right, x,y);
    else if(root->data>x && root->data>y) return LCA(root->left, x, y);
    else{
        return root;
    }
}
    
    
void f(Node* root, Node* lca, vector<int>&path){
    path.push_back(root->data);
    if(root->data==lca->data) return;
    else if(root->data > lca->data) f(root->left, lca, path);
    else{
        f(root->right, lca, path);
    }
        
    return;
}
    
    
/*You are required to complete below function */
int kthCommonAncestor(Node *root, int k,int x, int y)
{
    // your code goes here
    Node* lca=LCA(root, x, y);
    vector<int>path;
    f(root, lca, path);
    int n=path.size();
    if(path.size()<k) return -1;
    return path[n-k];
}
 
// ⏲️ Expected Time Complexity: O(Height of the Tree)
// 🛢️ Expected Space Complexity: O(Height of the Tree)

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    int k = 2;
    int x = 40;
    int y = 60;

    int ans = kthCommonAncestor(root,k,x,y);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 30 20 50 40 60 -1
