#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
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



unordered_map<Node*, Node*> parents;
Node* target_Node;

void parent_finder(Node* root, Node* parent){
    if(!root){
        return;
    }
    parents[root] = parent;
    parent_finder(root -> left, root);
    parent_finder(root -> right, root);
}


void find(Node* root, int target, bool & status){
    if(!root){
        return;
    }
    if(root -> data == target && status == false){
        target_Node = root;
        status = true;
        return;
    }
    find(root -> left, target, status);
    find(root -> right, target, status);
}



vector <int> KDistanceNodes(Node* root, int target , int k)
{
    parent_finder(root,NULL);
    queue<pair<Node*,int>> q;
    bool status = false;
    find(root,target,status);
    q.push({target_Node,k});
    unordered_map<Node*,bool> visited;
    vector<int> ans;
    visited[target_Node] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i <size; i++){
            Node* present = q.front().first;
            int position = q.front().second;
            q.pop();
            if(position == 0){
                ans.push_back(present -> data);
            }
            if(present -> left && position > 0 && visited[present -> left] == false){
                q.push({present -> left, position - 1});
                visited[present -> left] = true;
            }
            if(present -> right && position > 0 && visited[present -> right] == false){
                q.push({present -> right, position - 1});
                visited[present -> right] = true;
            }
            if(parents[present] && position > 0 && visited[parents[present]] == false){
                q.push({parents[present], position - 1});
                visited[parents[present]] = true;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int target = 8;
    int k = 2;
    vector <int> ans = KDistanceNodes(root, target,k);
    for(int i = 0; i< ans.size(); i++){
        cout<< ans[i] <<" ";
    }
    cout << endl;

    return 0;
}

// 20 8 4 12 10 14 20 22 -1 