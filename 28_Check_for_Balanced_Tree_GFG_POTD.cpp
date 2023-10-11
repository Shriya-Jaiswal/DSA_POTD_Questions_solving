#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}



//  ▶️ ▶️ ▶️ Amazon Microsoft  walmart
bool isBalanced(Node *root)
{
    if(root == NULL){
        return true;
    }
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    if((abs(leftHeight - rightHeight) == 0 || abs(leftHeight - rightHeight) == 1) && isBalanced(root->left) && isBalanced(root -> right)){
        return true;
    }
    return false;
}

// ⏲️ Expected time complexity: O(N)
// 🛢️ Expected auxiliary space: O(h) , where h = height of tree


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    bool ans = isBalanced(root);
    cout << "ans is : " << ans << endl;
    return 0;
}


// 10 20 40 -1 -1 60 -1 -1 30 -1 -1