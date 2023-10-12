#include<iostream>
#include<queue>
#include<unordered_map>
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


string structure(unordered_map<string , int> &mp, Node* root){
    if(root == NULL){
        return "";
    }
    string path = structure(mp, root ->left) + to_string(root->data) + structure(mp,root->right);
    mp[path]++;
    return path;
}

int dupSub(Node *root) {
    unordered_map<string ,int> mp;
    string result = structure(mp,root);
    for(auto it : mp){
        if(it.first.length() > 2 && it.second > 1){
            return 1;
        }
    }
    return 0;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Space Complexity: O(N)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int ans = dupSub(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 -1 2 4 -1 -1 5 -1 -1
