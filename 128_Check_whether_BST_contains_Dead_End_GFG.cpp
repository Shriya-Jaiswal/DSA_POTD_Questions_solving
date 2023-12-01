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

void storeNodes(Node * root, unordered_set<int> &st,unordered_set<int> &leafset){
    if (root == NULL)
        return ;
        
    st.insert(root->data);
    if (root->left==NULL && root->right==NULL)
    {
        leafset.insert(root->data);
        return ;
    }
    storeNodes(root-> left, st, leafset);
    storeNodes(root->right, st, leafset);
}

bool isDeadEnd(Node *root){
    if(!root) return true;
    unordered_set<int> st, leafset;
    st.insert(0);
    storeNodes(root, st, leafset);
        
    for (auto it: leafset){
    auto x =it;
    if (st.find(x+1) != st.end() && st.find(x-1) != st.end())
        return true;
    }
        
    return false ;
}

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    bool ans = isDeadEnd(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 8 5 2 1 7 9 -1

// 8 7 2 10 9 13 -1