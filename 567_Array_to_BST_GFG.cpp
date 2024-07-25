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
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        // 👉 this is the firt node we have to create 
        root = new Node(data);
        return root;
    }

    // 👉 not the first node
    if(root -> data > data){
        // 👉 insert in left
        root -> left = insertIntoBST(root -> left, data);
    }
    else{
        // 👉 insert in right
        root -> right = insertIntoBST(root -> right, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
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

// ▶️ Ask by : Snapdeal | Adobe | Cisco

Node *buildBSTFromInorder(vector<int> &inorder, int start, int end){
    if (start > end){
      return nullptr;
    }
    
    int mid = (start + end) / 2;
    Node *node = new Node(inorder[mid]);
    
    node->left = buildBSTFromInorder(inorder, start, mid - 1);
    node->right = buildBSTFromInorder(inorder, mid + 1, end);
    
    return node;
}
    
Node* sortedArrayToBST(vector<int>& nums) {
    Node *root = buildBSTFromInorder(nums, 0, nums.size() - 1);
    return root;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxillary Space: O(n)

int main()
{
    // Node* root = NULL;
    // cout << "enter the data for Node : " << endl;
    // takeInput(root);
    
    // cout << "printing the tree : " << endl;
    // levelOrderTraversal(root);

    vector<int>  nums = {1, 2, 3, 4};
    Node* ans = sortedArrayToBST(nums);
    levelOrderTraversal(ans);
    return 0;
}
