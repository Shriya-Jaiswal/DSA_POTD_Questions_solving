#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
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


// ▶️ Ask by :  Facebook ✯   Google ✯   Microsoft ✯   Intuit ✯  

// ▶️ Approach -  Using Post Order + set
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

Node* deleteHelper(Node* root, unordered_set<int>& st, vector<Node*>& result) {
    if(root == NULL)
        return NULL;
        
    root->left  = deleteHelper(root->left, st, result);
    root->right = deleteHelper(root->right, st, result);
        
    if(st.find(root->data) != st.end()) { //if I have to delete this root, then put root->left and root->right in result
        if(root->left != NULL)
            result.push_back(root->left);
            
        if(root->right != NULL)
            result.push_back(root->right);
            
        return NULL;
    } else {
        return root;
    }
}
    
vector<Node*> delNodes(Node* root, vector<int>& to_delete) {
    vector<Node*> result;
    unordered_set<int> st;
        
    for(int &num : to_delete) {
        st.insert(num);
    }
        
    deleteHelper(root, st, result); // <-- it will not consider root
    //So, check here if root is to be deleted or not
    if(st.find(root->data) == st.end()) {
        result.push_back(root);
    }
    return result;
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    vector<int> to_delete = {3,5};
    vector<Node*> ans = delNodes(root, to_delete);
    for(int i=0; i<ans.size();i++){
        cout << "ans is : " << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1