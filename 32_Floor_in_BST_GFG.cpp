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


int floor(Node* root, int x) {
    int ans =  -1;
    while(root){
        if(root->data == x){
            ans = root->data;
            return ans;
        }
        if(x < root->data){
            root = root -> left;
        }
        else{
            ans = root -> data;
            root = root -> right; 
        }
    } 
    return ans;
}



int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int x = 87;
    int ans = floor(root,x);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 2 -1 81 42 -1 66 45 -1 -1 -1 87 -1 90 -1 -1 

// 6 -1 8 7 -1 -1 9 -1 -1