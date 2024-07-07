#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
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


// ▶️ Ask by : Amazon

vector<int> ans;
void dfs(struct Node *root, int target, vector<int> &arr){
    if(!root) return;
    if(root->data==target){
        ans=arr;
        return;
    }
    arr.push_back(root->data);
    dfs(root->left,target,arr);
    dfs(root->right,target,arr);
    arr.pop_back();
}
vector<int> Ancestors(struct Node *root, int target) {
    vector<int> arr;
    dfs(root,target,arr);
    reverse(ans.begin(),ans.end());
    return ans;
}


// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(height of tree)

int main(){
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int target = 7;
    vector<int> ans = Ancestors(root,target);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}


