#include<iostream>
#include<queue>
using namespace  std;


// ▶️ Ask by :  Morgan Stanley | Amazon | Snapdeal | MakeMyTrip | Oracle | Oxigen Wallet | Informatica | Citicorp

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
    
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
        this ->height = 0;
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

int height(Node* N){
    if(!N){
        return 0;
    }
    return N -> height;
}
int getbalance(Node* N){
    if(!N){
        return 0;
    }
    return height(N -> left) - height(N -> right);
}
Node *rightrotation(Node* a){
    Node *b = a -> left;
    Node *c = b -> right;
    b -> right = a;
    a -> left = c;
    a -> height = max(height(a -> left), height(a -> right)) + 1;
    b -> height = max(height(b -> left), height(b -> right)) + 1;
    return b;
}
Node *leftrotation(Node* a){
    Node *b = a -> right;
    Node *c = b -> left;
    b -> left = a;
    a -> right = c;
    a -> height = max(height(a -> left), height(a -> right)) + 1;
    b -> height = max(height(b -> left), height(b -> right)) + 1;
    return b;
}
Node* insertToAVL(Node* node, int data)
{
    if(!node){
        return new Node(data);
    }
    if(data < node -> data){
        node -> left = insertToAVL(node -> left, data);
    }else if(data > node -> data){
        node -> right = insertToAVL(node -> right, data);
    }else{
        return node;
    }
    node -> height = max(height(node -> left), height(node -> right)) + 1;
    int balance = getbalance(node);
    if(balance > 1 and data < node -> left -> data){
        return rightrotation(node);
    }
    if(balance < -1 and data > node -> right -> data){
        return leftrotation(node);
    }
    if(balance > 1 and data > node -> left -> data){
        node -> left = leftrotation(node -> left);
        return rightrotation(node);
    }
    if(balance < -1 and data < node -> right -> data){
        node -> right = rightrotation(node -> right);
        return leftrotation(node);
    }
    return node;
}

// ⏲️ Expected Time Complexity: O(log N)
// 🛢️ Expected Auxiliary Space: O(height of tree)


int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    int data = 3;
    Node* ans = insertToAVL(root, data);
    levelOrderTraversal(ans);
    return 0;
}

// 3
// 5 1 4 
