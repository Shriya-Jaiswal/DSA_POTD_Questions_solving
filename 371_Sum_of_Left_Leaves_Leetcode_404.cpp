#include<iostream>
#include<queue>
using namespace std;


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

// // ▶️ Ask by :  Adobe ✯   : META

// // ▶️ Approach-1 (Using Parent Pointer)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1) Auxiiliary Space and O(depth of tree) recursion system stack space

// int sum(Node* curr, Node* parent) {
//     if(!curr)
//         return 0;
        
//     int left  = sum(curr->left, curr);
//     int right = sum(curr->right, curr);
        
//     int sum = 0;
//     if(curr->left == NULL && curr->right == NULL) {
//         if(parent && parent->left == curr)
//             sum += curr->data;
//     }
//     return left+right+sum;
// }
// int sumOfLeftLeaves(Node* root) {
//     if(!root)
//         return 0;
//     Node* parent = NULL;
//     return sum(root, parent);
// }

// ▶️ Approach-2 (without parentpointer, only using a flag)
// ⏲️ T.C : O(n)
// 🛢️ S.C : O(1) Auxiiliary Space and O(depth of tree) recursion system stack space


int solve(Node* curr, bool isLeft) {
    if(!curr) {
        return 0;
    }  
    if(!curr->left && !curr->right && isLeft) {
        return curr->data;
    }   
    return solve(curr->left, true) + solve(curr->right, false);
}
    
int sumOfLeftLeaves(Node* root) {
    return solve(root, false);
}

int main(){
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int ans = sumOfLeftLeaves(root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 3 9 -1 -1 20 15 -1 -1 7 -1 -1