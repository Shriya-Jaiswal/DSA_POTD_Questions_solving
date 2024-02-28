#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by :  Yahoo ✯   Amazon ✯   Microsoft ✯  


class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }
        //no the first node 
        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;
        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}

void levelOrderTraversal(Node* root ) {
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



// // ▶️ Approach-1 (Using DFS)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(max depth of tree)

// int maxDepth;
// int bottomLeft;
    
// void solve(Node* root, int currDepth) {
//     if(!root) {
//         return;
//     }
        
//     if(currDepth > maxDepth) {
//         maxDepth   = currDepth;
//         bottomLeft = root->data;
//     }
        
//     solve(root->left, currDepth+1);
//     solve(root->right, currDepth+1);
// }
    
// int findBottomLeftValue(Node* root) {
//     maxDepth = -1;
        
//     solve(root, 0);
//     return bottomLeft;
        
// }

// // ▶️ Approach-2 (Using BFS)
// // ⏲️ T.C : O(n)
// // 🛢️ S.C : O(n) for queue

// int findBottomLeftValue(Node* root) {
//     queue<Node*> que;
        
//     int bottomLeft;
//     que.push(root);
        
//     while(!que.empty()) {
//         Node* node = que.front();
//         que.pop();
            
//         bottomLeft = node->data;
            
//         if(node->right) {
//             que.push(node->right);
//         }
//         if(node->left) {
//             que.push(node->left);
//         }
//     }
        
//     return bottomLeft;
// }


// ◀️ Approach-3 (Using BFS with inner while loop)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) for queue

int findBottomLeftValue(Node* root) {
    queue<Node*> que;
        
    int bottomLeft;
    que.push(root);
        
    while(!que.empty()) {
        int n = que.size();

        while(n--) {
            Node* node = que.front();
            que.pop();
                
                
            bottomLeft = node->data;
                
            if(node->right) {
                que.push(node->right);
            }
            if(node->left) {
                que.push(node->left);
            }
        }
            
    }
        
    return bottomLeft;
}

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int ans = findBottomLeftValue(root);
    cout << "ans is : " <<  ans << endl;
    return 0;
}

// 2 1 -1 -1 3 -1 -1
