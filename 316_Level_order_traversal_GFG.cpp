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

// ▶️ Ask by : Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | Samsung | D-E-Shaw | Ola Cabs | Payu | Adobe | Cisco | Qualcomm

vector<int> levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty()){
        Node* node=q.front();
        q.pop(); 
        ans.push_back(node->data);
        if(node->left){
            q.push(node->left);
        } 
        if(node->right){
            q.push(node->right);
        }      
    }
    return ans;
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    vector<int> ans = levelOrder(root);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 1 3 -1 -1 2 -1 -1
// 10 20 40 -1 -1 60 -1 -1 30 -1 -1