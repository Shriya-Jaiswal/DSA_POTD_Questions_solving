#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


// ▶️ Ask by : Accolite | Amazon

void solve(Node*root, map<int,int>&mp, int level){
    if(!root) return;
    mp[level]+=root->data;
     
    solve(root->left, mp, level+1);
    solve(root->right, mp, level);
    return;
}
    
vector <int> diagonalSum(Node* root) {
    map<int,int>mp;
    solve(root, mp, 0);
    vector<int>ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
        
}


// ⏲️ Expected Time Complexity: O(nlogn).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    vector<int> ans = diagonalSum(root);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// 4 1 -1 -1 3 3 -1 -1 -1
