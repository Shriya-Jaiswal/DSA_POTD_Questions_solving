#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;


// ▶️ Ask by :  Facebook ✯   Amazon ✯   Bloomberg ✯   Google ✯   Microsoft ✯   Apple  

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }
        //no the first node 
        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;
        while(data != -1) {
                root = insertIntoBST(root, data);
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


// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(depth of tree) - Recursion System Stack Space

int diameter(Node* root, int& result) {
    if(!root)
        return 0;
        
    int left  = diameter(root->left, result);
    int right = diameter(root->right, result);
        
    result = max(result, left + right); //What if I longest diamenter passes through left -> me -> right
        
    return max(left, right) + 1; //But I will return max I can afford if (left -> me -> right) was not answer
        
}
    
int diameterOfBinaryTree(Node* root) {
    if(!root)
        return 0;
        
    int result = INT_MIN;
        
    diameter(root, result);
        
    return result;
}



int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int ans = diameterOfBinaryTree(root);
    cout << "ans is : " <<  ans << endl;
    return 0;
}


// 1 2 4 -1 -1 5 -1 -1 3 -1 -1