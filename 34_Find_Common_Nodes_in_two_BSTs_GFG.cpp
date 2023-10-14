#include<iostream>
#include<queue>
#include <vector>
#include<map>
#include<algorithm>
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


void inorder(Node* root, map<int,int> &m){
    if(!root){
        return;
    }
    inorder(root ->left,m);
    m[root->data]++;
    inorder(root->right,m);
}


void commonNodes(Node*root, map<int,int> &nodesInTree1, vector<int>&ans){
    if(!root){
        return;
    }

    if(nodesInTree1[root->data] > 0 ){
        ans.push_back(root->data);
        nodesInTree1[root->data]--;
    }
    commonNodes(root->left,nodesInTree1,ans);
    commonNodes(root->right,nodesInTree1,ans);
}

vector <int> findCommon(Node *root1, Node *root2)
{
   vector<int> ans;
   map<int,int>nodesInTree1;
   inorder(root1,nodesInTree1);
   commonNodes(root2,nodesInTree1,ans);
   sort(ans.begin(),ans.end());
   return ans;
}

// ⏲️ Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
// 🛢️ Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

int main()
{
    Node* root1 = NULL;
    cout << "enter the data for Node in root1 : " << endl;
    takeInput(root1);
    Node* root2 = NULL;
    cout << "enter the data for Node in root2 : " << endl;
    takeInput(root2);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root1);
    cout << "printing the tree : " << endl;
    levelOrderTraversal(root2);

    vector<int> ans = findCommon(root1,root2);
    cout<< "final ans is : " << endl;
    for(int i=0; i<ans.size();i++){
        cout<< ans[i] <<" ";
    }
    cout<< endl;

    return 0;
}

// 5 1 0 4 10 7 9 -1
// 10 7 4 9 20 -1