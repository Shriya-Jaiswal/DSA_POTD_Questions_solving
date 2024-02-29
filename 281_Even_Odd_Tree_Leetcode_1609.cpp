#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;



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


// // ▶️ Approach-1 (When we deal with level, always first think of BFS)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// bool isEvenOddTree(Node* root) {
//     queue<Node*> que;
        
//     que.push(root);
//     bool even_level = true;
//     while(!que.empty()) {      
//         int n = que.size();
//         int prev;
//         if(even_level)
//             prev = INT_MIN;
//         else
//             prev = INT_MAX;
        
//         while(n--) {
//             Node* node = que.front();
//             que.pop();   
//             if (even_level && (node->data % 2 == 0 || node->data <= prev)) {
//                 return false;
//             }
//             if (!even_level && (node->data % 2 == 1 || node->data >= prev)) {
//                 return false;
//             }   
//             prev = node->data;
//             if(node->left) {
//                 que.push(node->left);
//             }
//             if(node->right) {
//                 que.push(node->right);
//             }       
//         }
//         even_level = !even_level;       
//     }
//     return true;
// }



// ◀️ Approach-2 (DFS)
// ⏲️ Time Ccomplexity : O(n)
// 🛢️ Space Complexity : Auxiliary Space O(n) + Recursion Space O(depth)

vector<int> levelPrev;
    
bool solve(Node* root, int level) {
    if(!root) {
        return true;
    }
        
    if((level%2 == 0 && root->data%2 == 0) || (level%2 != 0 && root->data%2 != 0)) {
           return false;
    }
        
    if(level >= levelPrev.size()) {
        levelPrev.resize(level+1);
    }

    if(levelPrev[level] != 0) { //already there is a value at this level
        if((level%2 == 0 && root->data <= levelPrev[level]) ||
            (level%2 != 0 && root->data >= levelPrev[level]))
            return false;
    }
        
    levelPrev[level] = root->data;
        
    return solve(root->left, level+1) && solve(root->right, level+1);
}
    
bool isEvenOddTree(Node* root) {
    return solve(root, 0);
}

int main()
{
     Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    bool ans = isEvenOddTree(root);
    cout << "ans is : " <<  ans << endl;
    return 0;
}

// 1 10 3 12 -1 -1 8 -1 -1 -1 4 7 6 -1 -1 -1 9 -1 2 -1 -1
// 1 10 4 3 7 9 12 8 6 2 -1

// 5 4 3 -1 -1 3 -1 -1 2 7 -1 -1 -1
