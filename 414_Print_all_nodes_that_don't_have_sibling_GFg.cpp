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


// ◀️ Ask by : Amazon | D-E-Shaw

void traversal(Node*node, vector<int>&ans){
    if(node){
        if(node->left && !node->right){
            ans.push_back(node->left->data);
        }
        if(!node->left && node->right){
            ans.push_back(node->right->data);
        }
        
        traversal(node->left, ans);
        traversal(node->right, ans);
        
        return;
    }
}

vector<int> noSibling(Node* node)
{
    vector<int>ans;
    traversal(node, ans);
    if(ans.size()==0){
        ans.push_back(-1);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

// ⏲️ Expected Time Complexity: O(nlogn)
// 🛢️ Expected Auxiliary Space: O(Height of the tree)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    vector<int> ans = noSibling(root);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 37 20 113 -1 -1 -1
