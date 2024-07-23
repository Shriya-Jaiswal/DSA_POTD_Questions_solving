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


void inorder(Node* root, vector<int>&ans){
    if(root==NULL) return;
        
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
        
    return;
}
    
vector<int> merge(Node *root1, Node *root2) {
    vector<int>arr1, arr2, ans;
    inorder(root1, arr1);
    inorder(root2, arr2);
        
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
       }
    while(i<arr1.size()){
        ans.push_back(arr1[i++]);
    }
    while(j<arr2.size()){
        ans.push_back(arr2[j++]);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(m+n)
// 🛢️ Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root1);
    cout << "enter the data for Node : " << endl;
    takeInput(root2);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root1);
    levelOrderTraversal(root2);

    vector<int> ans = merge(root1,root2);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 5 3 2 4 6 -1
// 2 1 3 7 6 -1