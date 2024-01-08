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

// 👉 codehelp Approach

// int rangeSumBST(Node* root, int low, int high) {
//     if(!root){
//         return 0;
//     }       
//     int ans = 0;
//     bool wasInRange = false;
//     if(root -> data >= low && root -> data <= high){
//         wasInRange = true;
//         ans += root -> data;
//     }

//     if(wasInRange){
//         ans += rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
//     }
//     else if(root -> data <= low){
//         ans += rangeSumBST(root -> right, low, high);
//     }
//     else if(root -> data > high){
//         // 👉 go to left subtree
//         ans += rangeSumBST(root->left, low, high);
//     }
//     return ans;
// }


// ▶️ or Approach

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) (Ignoging recursion stack space)

int rangeSumBST(Node* root, int low, int high) {
    if(!root)
        return 0;
        
    //Within Range
    if(root->data >= low && root->data <= high) {
        return root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
        
    //When outside the range (Less than low) - Go right
    if(root->data < low)
        return rangeSumBST(root->right, low, high);

    //When outside the range (Greater than high) - Go left
    return rangeSumBST(root->left, low, high);
}

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node in BST : " << endl;
    takeInput(root);

    cout << "printing the tree for BSt1 : " << endl;
    levelOrderTraversal(root);
   
   int low = 7;
   int high = 15;
   int ans = rangeSumBST(root, low, high);
   cout << "ans is : " << ans << endl;
   
    return 0;
}
// 10 5 15 3 7 18 -1
// 10 5 15 3 7 13 18 1 6 -1