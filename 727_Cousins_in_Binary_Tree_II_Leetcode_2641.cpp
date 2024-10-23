#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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


// ▶️ Ask by :  Amazon ✯  

Node* replaceValueInTree(Node* root) {
    queue<pair<Node*, Node*>> q;
    q.push({NULL, root});
    while(q.size()){
        int s = q.size();
        int layerSum = 0;
        unordered_map<Node*,int>sumOfParent;
        vector<pair<Node*, Node*>> layer;
        while(s--){
            auto[parent,node] = q.front();
            q.pop();
            layer.push_back({parent,node});
            layerSum+=node->val;
            sumOfParent[parent] += node->val;
            if(node->left){
                q.push({node,node->left});
            }
            if(node->right){
                q.push({node,node->right});
            }
        }
        for(auto &[parent,node]: layer){
            node->val = layerSum - sumOfParent[parent];
        }
    }        
    return root;
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    Node* ans = replaceValueInTree(root);
    levelOrderTraversalLikeTree(ans);
    return 0;
}
