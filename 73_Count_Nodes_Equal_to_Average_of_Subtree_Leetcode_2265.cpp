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

// // ▶️ //Approach-1 (Brute Force)
// int result;
    
//     int sum(Node* root, int &count) {
//         if(!root)
//             return 0;
        
//         count++;
        
//         int l = sum(root->left, count);
//         int r = sum(root->right, count);
        
//         return l + r + root->data;
//     }
    
//     void solve(Node* root) {
//         if(!root)
//             return;
        
//         int count = 0;
//         int totalSum = sum(root, count);
        
//         if((totalSum)/count == root->data) {
//             result++;
//         }
        
//         solve(root->left);
//         solve(root->right);
        
//     }
    
//     int averageOfSubtree(Node* root) {
//         result = 0;
        
//         solve(root);
        
//         return result;
//     }

//T.C : O(n^2) For every root, you visit it's subtree to find average
//S.C : O(1) (excluding recursion stack space)


// ◀️ Approach 2
int result ;
pair<int,int> solve(Node* root){
    if(root == NULL){
        return {0,0};
    }

    auto p1 = solve(root -> left);
    auto p2 = solve(root -> right);

    int totalSum = p1.first + p2.first + root -> data;
    int totalCount = p1.second + p2.second + 1;

    int avg = totalSum/totalCount;

    if(avg == root -> data){
        result += 1;
    }

    return {totalSum, totalCount};
}

int averageOfSubtree(Node* root) {
    result = 0;
    solve(root);
    return result;
}
// ⏲️ Time Complexity : O(n)
// 🛢️ Space complexity : O(1) (excluding recursion stack space)

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	buildTree();
	cout << "Printing the tree" << endl;
	levelOrderTraversalLikeTree(root);
	cout << endl;

    int ans = averageOfSubtree(root);
    cout << "ans is : " <<  ans << endl;
    return 0;
}

// 4 8 0 -1 -1 1 -1 -1 5 -1 6 -1 -1
