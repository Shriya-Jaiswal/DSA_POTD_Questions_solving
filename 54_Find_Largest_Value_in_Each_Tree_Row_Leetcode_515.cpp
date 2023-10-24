#include<iostream>
#include<vector>
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

vector<int> result;

void DFS(Node* root, int depth){
    if(root==NULL){
        return;
    }

    if(depth == result.size()){
        result.push_back(root->data);
    }
    else{
        result[depth] = max(result[depth],root->data);
    }

    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

vector<int> largestValues(Node* root) {
    DFS(root,0);
}

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    vector<int> ans = largestValues(root);
    for(int i=0; i<ans.size();i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}

// 1 3 5 -1 -1 3 -1 -1 2 -1 9 -1 -1