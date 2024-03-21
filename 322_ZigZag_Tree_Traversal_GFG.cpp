#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ▶️ ask by : Flipkart | Amazon | Microsoft | Snapdeal | FactSet | Hike | Walmart | Cisco

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


vector <int> zigZagTraversal(Node* root){
    vector<vector<int>>traversal;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
    	int n=q.size();
    	vector<int>level;
    	for(int i=0;i<n;i++){
    	    Node* node=q.front();
    	    q.pop();
    	    level.push_back(node->data);
    	    if(node->left){
    	        q.push(node->left);
    	    }
    	    if(node->right){
    	        q.push(node->right);
    	    }
    	}
    	traversal.push_back(level);
    }
    vector<int>ans;
    for(int i=0;i<traversal.size();i++){
    	if(i%2==1){
    	    reverse(traversal[i].begin(), traversal[i].end());
    	}
    	for(auto it:traversal[i]){
    	       ans.push_back(it);
    	}
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    vector<int> ans = zigZagTraversal(root);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
