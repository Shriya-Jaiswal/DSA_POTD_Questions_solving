#include<iostream>
#include<vector>
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

// ▶️ Ask by : Paytm | Amazon

void solve(Node* root, vector<int>curr, vector<vector<int>>&ans){
    if(root==NULL){
        return;
    }
        
    curr.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(curr);
        return ;
    }
        
    solve(root->left, curr, ans);
    solve(root->right, curr, ans);
        
    return;
}
  
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>>ans;
    vector<int>curr;
    solve(root, curr, ans);
     return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(height of the tree)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    vector<vector<int>> ans = Paths(root);

    for(int i=0; i<ans.size(); i++){
       for(int j=0; j<ans[i].size() ; j++ ){
            cout << ans[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}

// 1 2 -1 -1 3 -1 -1