#include<iostream>
#include <vector>
#include<map>
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


// ▶️ Ask by : Amazon

map<int,int>mp;
void preorder(Node* node, int level){
    if(node!=NULL){
        mp[level]+=node->data;
          
        preorder(node->left, level-1);
        preorder(node->right, level+1);
          
        return;
    }
}
  
vector <int> verticalSum(Node *root) {
     preorder(root, 0);
    vector<int>ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(nlogn).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    vector<int> ans = verticalSum(root);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

//  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
