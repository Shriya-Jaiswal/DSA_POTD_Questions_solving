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

// ▶️ Ask by : Paytm | Flipkart | Accolite | Amazon | Microsoft | MAQ Software | Adobe | Linkedin | Quikr | Yahoo | InMobi

Node* solve(vector<int>&A, int& ind){
    if(A[ind]==-1){
        ind++;
        return NULL;
    }
    Node* root= new Node(A[ind]);
    ind++;
    root->left=solve(A, ind);
    root->right=solve(A, ind);
        
    return root;
}
    
void pre(Node* root, vector<int>&ans){
    if(root==NULL){
        ans.push_back(-1);
        return;
    }
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
        
    return;
}
    
//Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root) 
{
    vector<int>ans;
    pre(root, ans);
        
    return ans;
}
    
// 👉 Function to deserialize a list and construct the tree.
Node * deSerialize(vector<int> &A)
{
    int ind=0;
    return solve(A,ind);
}

// ⏲️ Expected Time Complexity: O(Number of nodes).
// 🛢️ Expected Auxiliary Space: O(Number of nodes).

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

   vector<int> ans = serialize(root);
   for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
   }
   cout << endl;
    return 0;
}
// 1 2 -1 -1 3 -1 -1