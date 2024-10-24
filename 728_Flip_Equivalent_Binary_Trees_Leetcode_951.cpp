#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
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


// ▶️ Ask by :  Google ✯  

bool flipEquiv(Node* root1, Node* root2) {
    if(!root1 and !root2){
        return true;
    } 
    if(!root1 or !root2 or root1->data!= root2->data){
        return false ;
    } 

    return ((flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) or
            (flipEquiv(root1->right, root2->left) and flipEquiv(root1->left,root2->right)));
}


int main()
{
    Node* root1 = NULL;
    root1 = buildTree();
    levelOrderTraversalLikeTree(root1);
    Node* root2 = NULL;
    root2 = buildTree();
    levelOrderTraversalLikeTree(root2);

    bool ans = flipEquiv(root1,root2);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
// 1 3 -1 6 -1 -1 2 4 -1 -1 5 8 -1 -1 7 -1 -1 
