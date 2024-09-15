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

// ▶️ Ask by : Morgan Stanley | Accolite | Amazon | Microsoft | Snapdeal | Goldman Sachs | Salesforce

Node *head = NULL, *lastNode = NULL;
void help(Node *root){
    if(!root)return;
    help(root->left);
    if(!head)head=root;
    if(lastNode)lastNode->right=root;
    root->left=lastNode;
    lastNode=root;
    help(root->right);
}

Node* bToDLL(Node* root) {
    help(root);
    return head;
}


// ⏲️ Expected Time Complexity: O(no. of nodes)
// 🛢️ Expected Space Complexity: O(height of the tree)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    Node* ans = bToDLL(head);
    levelOrderTraversalLikeTree(ans);
    return 0;
}

// 1 3 -1 -1 2 -1 -1