#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


// ▶️ Ask by : Flipkart | Microsoft

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


// // ➡️ Approach-1 (Storing all root-leaf paths)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n*h) - where "n" is the number of nodes in the tree, and "h" is the height of the tree. 
// // ➡️ This is because there can be at most n/2 leaf nodes in a binary tree, and each path from root to leaf may have a length of up to h.



// vector<vector<Node*>> paths;
// void storeRootToLeaf(Node* root, vector<Node*>& temp) {
//     if(!root) {
//         return;
//     }
        
//     temp.push_back(root);
//     if(!root->left && !root->right) {
//         paths.push_back(temp);
//     }
//     storeRootToLeaf(root->left, temp);
//     storeRootToLeaf(root->right, temp);
//     temp.pop_back();
// }
    
// //Function to return count of nodes at a given distance from leaf nodes.
// int printKDistantfromLeaf(Node* root, int k) {
//     paths.clear();
//     vector<Node*> temp;
//     storeRootToLeaf(root, temp);
//     unordered_set<Node*> st;
    	
//     for(vector<Node*> &vec : paths) {
//     	int n = vec.size();
//     	if(n - k > 0) {
//     	    st.insert(vec[n-k-1]);
//     	}
//     }
    	
//     return st.size();
// }



// ➡️ Approach-2 (Without storing all root-leaf paths)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(h)

void solve(Node* root, int level, unordered_set<Node*>& result, vector<Node*>& path, int& k) {
    if(!root) {
        return;
    }
        
    path.push_back(root);
    if(!root->left && !root->right) {
        if(level - k >= 0) {
            result.insert(path[level-k]);
        }
    }
        
    solve(root->left, level+1, result, path, k);
    solve(root->right, level+1, result, path, k);
    path.pop_back();
}
    
//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k) {
    vector<Node*> path;
    unordered_set<Node*> result;
    	
    solve(root, 0, result, path, k);

    return result.size();
}


// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(Height of the Tree).

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int k = 4;
    int ans = printKDistantfromLeaf(root,k);
    cout << "ans is : " << ans << endl;

    return 0;
}
// 1 3 5 7 -1 -1 8 -1 9 -1 -1 -1 -1
