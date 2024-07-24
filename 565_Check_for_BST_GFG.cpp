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


// ▶️ Ask by : VMWare | Flipkart | Accolite | Amazon | Microsoft | OYO Rooms | Samsung | Snapdeal | FactSet | Hike | MakeMyTrip | Ola Cabs | Walmart | Goldman Sachs | MAQ Software | Adobe | Linkedin | Qualcomm | Boomerang Commerce | GreyOrange | Wooker

bool isBST(Node* root) {
    int prev = -1;
    if(!root) return true;
        
    bool left = isBST(root->left);
    if(!left) return false;
        
    if(root->data <= prev) return false;
    prev = root->data;
        
    bool right = isBST(root->right);
        
    return left && right;
}

// ⏲️ Expected Time Complexity: O(n) 
// 🛢️ Expected Auxiliary Space: O(Height of the tree)
// 👉 where n is the number of nodes in the given tree

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);
    
    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);
    bool ans = isBST(root);
    cout << "ans is : " << ans << endl; 
    return 0;
}
// 2 1 3 5 -1