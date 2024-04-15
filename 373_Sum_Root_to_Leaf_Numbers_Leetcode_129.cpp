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


// ▶️ Ask by :  Facebook ✯   Microsoft ✯   Amazon ✯  : Google, Meta, Accolite, Amazon, Microsoft, Samsung, FactSet, 

// ▶️ Recursion-1
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int find( Node* root, int curr) {      
    if(!root)
        return 0;

    curr = curr*10 + root->data;
    if(root->left == NULL && root->right == NULL) {
        return curr;
    }
    int left_num  = find(root->left, curr);
    int right_num = find(root->right, curr);   
    return left_num + right_num;
}
    
int sumNumbers(Node* root) {
    return find(root, 0);
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int ans = sumNumbers(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 1 2 -1 -1 3 -1 -1