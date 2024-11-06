#include<iostream>
#include<vector>
#include<queue>
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

// ▶️ Ask by : Amazon | Microsoft | OYO Rooms | Google

void dfs(Node* root,int &ans, int x){
    if(!root->left && !root->right){
        ans+=x*10+root->data;
        return ;
    }
    if(root->left){
        dfs(root->left,ans,x*10+root->data);
    }
    if(root->right){
        dfs(root->right,ans,x*10 + root->data);
    }
}
int treePathsSum(Node *root) {
    int ans=0;
    int x=0;
    dfs(root,ans,x);
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    int ans = treePathsSum(root);
    cout << "ans is : " << ans << endl;
    return 0;
}


// 6 3 2 -1 -1 5 7 -1 -1 4 -1 -1 5 -1 4 -1 -1