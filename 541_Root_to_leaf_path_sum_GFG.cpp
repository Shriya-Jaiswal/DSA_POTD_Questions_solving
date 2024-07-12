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



// ▶️ Ask :  Accolite | Amazon | Microsoft | Samsung | FactSet | Housing.com | Oracle | Goldman Sachs | Adobe | CouponDunia | Atlassian


bool dfs(Node* root,int sum, int target){
    if(!root->left && !root->right){
        if(sum+root->data==target)
        return true;
        return false;
    }
    bool left=false, right=false;
        
    if(root->left)
            left=dfs(root->left,sum+root->data, target);
    if(root->right)
        right=dfs(root->right,sum+root->data, target);
            
    return left||right;
}


bool hasPathSum(Node *root, int target) {
    return dfs(root,0,target);
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(height of tree)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int target = 2;
    bool ans = hasPathSum(root,target);
    cout << "ans is : " << ans << endl;
    return 0;
}
