#include<iostream>
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

// ▶️ Ask by :  Microsoft ✯   Amazon ✯   Apple ✯   PhonePe ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(height of tree due to recursion)

int solve(Node* root, int &moves) {
    if(root == NULL) {
        return 0;
    }
        
    int l = solve(root->left, moves);
    int r = solve(root->right, moves);
        
    int total_extra_candies = (l + r + root->data) - 1;
        
    moves += abs(l) + abs(r);
        
    return total_extra_candies;
}

int distributeCoins(Node* root) {
    int moves = 0;
    if(!root->left && !root->right) {
        return 0;
    }
    solve(root, moves);
        
    return moves;
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    int ans = distributeCoins(root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 3 0 -1 -1 0 -1 -1