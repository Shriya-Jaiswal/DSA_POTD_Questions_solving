#include<iostream>
#include<queue>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   IBM ✯  

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

// ▶️ Approach - Simple Recursion Story
// ⏲️ Time Complexity : O(n)

string tree2str(Node* root) {
    if(!root) {
        return "";
    }     
    string result = to_string(root->data);
    string l = tree2str(root->left);
    string r = tree2str(root->right);
       
    if(!root->left && !root->right) {
        return result;
    }
        
    if(!root->right)
        return result + "(" + l + ")";
        
    if(!root->left)
        return result + "()" + "(" + r + ")";
        
    return result + "(" + l + ")" + "(" + r + ")";        
}

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    string ans = tree2str(root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 1 2 4 -1 -1 -1 3 -1 -1