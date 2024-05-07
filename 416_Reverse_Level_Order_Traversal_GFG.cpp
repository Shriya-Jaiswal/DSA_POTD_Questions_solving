#include<iostream>
#include <vector>
#include<stack>
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

// ▶️ Ask by : Flipkart | Amazon | Microsoft | FactSet | Adobe | Cisco

vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    stack<int>st;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front(); q.pop();
        st.push(node->data);
        
        if(node->right){
            q.push(node->right);
        }
        if(node->left){
            q.push(node->left);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main()
{
    
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    vector<int> ans = reverseLevelOrder(root);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// 1 3 -1 -1 2 -1 -1
