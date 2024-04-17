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

// // ▶️ Ask by : Apple ✯  

// // ▶️ Approach-1 (Using DFS)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n) space taken for resurion system stack

string result = "";    
void solve(Node* root, string curr) {
    if(root == NULL) {
        return;
    }
        
    curr = char(root->data + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
    if(root->left == NULL && root->right == NULL) {
        if(result == "" || result > curr) {
            result = curr;
        }
        return;
    }
    solve(root->left, curr);
    solve(root->right, curr);  
}
    
string smallestFromLeaf(Node* root) {
    solve(root, "");   
    return result;
}



// // ▶️ Approach-2 (Using BFS)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// string smallestFromLeaf(Node* root) {
//     queue<pair<Node*, string>> que;
        
//     string result = "";
//     que.push({root, string(1, root->data + 'a')});
        
//     while(!que.empty()) {
//         auto[node, curr] = que.front();
//         que.pop();
            
//         if(node->left == NULL && node->right == NULL) {
//             if(result == "" || result > curr) {
//                 result = curr;
//             }
//         }
            
//         if(node->left) {
//             que.push({node->left, char(node->left->val + 'a') + curr});
//         }     
//         if(node->right) {
//             que.push({node->right, char(node->right->val + 'a') + curr});
//         }    
//     }
//     return result;
// }


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    cout << endl << endl;

    string ans = smallestFromLeaf(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// a b d -1 -1 e -1 -1 c d -1 -1 e -1 -1