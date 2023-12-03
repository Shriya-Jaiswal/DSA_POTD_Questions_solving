#include<iostream>
#include<queue>
#include<unordered_set>
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
		// step A
		Node* temp = q.front();
		// step B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			// step C
			cout << temp->data << " ";
			// step D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}		
	}
}

void inorder(Node* root, unordered_set<int>& b1){
    if(!root) return;
    inorder(root->left,b1);
    b1.insert(root->data);
    inorder(root->right,b1);
}

int countPairs(Node* root1, Node* root2, int x){
    unordered_set<int> b1;
    unordered_set<int> b2;
    inorder(root1,b1);
    inorder(root2,b2);
    int ans=0;
    for(auto it: b1){
        if(b2.find(x-it)!=b2.end()) ans++;
    }
    return ans;    
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(N)

int main()
{
    Node* root1 = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root1);

    Node* root2 = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root2);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root1);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root2);

    int x = 16;
    int ans = countPairs(root1,root2,x);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 5 3 2 4 7 6 8
// 10 6 3 8 15 11 18
