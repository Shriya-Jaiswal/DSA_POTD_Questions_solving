#include<iostream>
#include <queue>
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



// // ▶️ Ask by :  Facebook ✯   Amazon ✯   Gilt Groupe ✯  


// // ▶️ Approach-1 : Using DFS
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1) Auxiliary Space, O(depth) system stack space of recursion


// Node* add(Node* root, int val, int depth, int curr) {
//     if(!root)
//         return NULL;
        
//     if(curr == depth-1) {
//         Node* lTemp = root->left;
//         Node* rTemp = root->right;
            
//         root->left  = new Node(val);
//         root->right = new Node(val);
//         root->left->left = lTemp;
//         root->right->right = rTemp;
            
//         return root;
//     }
        
//     root->left  = add(root->left, val, depth, curr+1);
//     root->right = add(root->right, val, depth, curr+1);
        
//     return root;
// }
    
// Node* addOneRow(Node* root, int val, int depth) {
//     if(depth == 1) {
//         Node* newRoot = new Node(val);
//         newRoot->left = root;
//         return newRoot;
//     }
//     return add(root, val, depth, 1);
// }



// ▶️ Approach-2 : Using BFS
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

Node* addOneRow(Node* root, int v, int d) {
    if(d == 1) {
        Node* newRoot = new Node(v);
        newRoot->left = root;
        return newRoot;
    }
    queue<Node*> que;
        
    que.push(root);
    int level = 0;
    bool rowAdded = false;
    while(!que.empty()) {
        int n = que.size();
        level++;
        while(n--) {
            Node* curr = que.front();
            que.pop();
            Node* tempL = curr->left;
            Node* tempR = curr->right;
            if(level == d-1) {
                curr->left  = new Node(v);
                curr->right = new Node(v);
                curr->left->left   = tempL;
                curr->right->right = tempR;
                rowAdded = true;
            }
            if(tempL)
                que.push(tempL);
            if(tempR)
                que.push(tempR);
        }
        if(rowAdded)
            break;
    }
        
    return root;
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    cout << endl << endl;
    int val = 1;
    int depth = 2;
    Node* ans = addOneRow(root,val,depth);
    levelOrderTraversalLikeTree(ans);


    return 0;
}

// 4 2 3 -1 -1 1 -1 -1 6 5 -1 -1 -1
