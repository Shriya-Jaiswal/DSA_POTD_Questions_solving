#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by  : LinkedIn ✯   Amazon ✯   Google ✯   Apple ✯   Facebook ✯   Bloomberg  

// // ▶️ Approach-1 (Using DFS)
// // ⏲️ T.C : O(n)
// // 🛢️ S.C : O(1) Auxiliary space, O(depth of tree) Recursion stack space

// bool isSameTree(TreeNode* p, TreeNode* q) {
//     if(!p && !q)
//         return true;
        
//     if(p == NULL || q == NULL)
//         return false;
        
//     if(p->val != q->val)
//         return false;
        
//     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// }


// ▶️ Approach-2 (Using BFS)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)



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

 bool isSameTree(Node* p, Node* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            Node* first = q1.front();
            Node* second = q2.front();
            q1.pop();
            q2.pop();
            if(first->data != second->data)
                return false;
          
            if(first->left && second->left) {
                q1.push(first->left);
                q2.push(second->left);
            } else if(first->left || second->left)
                return false;
          
            if(first->right && second->right) {
                q1.push(first->right);
                q2.push(second->right);
            } else if(first->right || second->right)
                return false;
        }
        return true; 
}

int main()
{
    Node* p = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(p);
    cout << "Printing the tree" << endl;
	levelOrderTraversal(p);
	cout << endl;


    Node* q = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(q);
	
	cout << "Printing the tree" << endl;
	levelOrderTraversal(q);
	cout << endl;

    bool ans = isSameTree(p,q);
    cout << "ans is : " <<  ans << endl;
    return 0;
}

// 1 2 -1 -1 3 -1 -1
// 1 2 -1 -1 3 -1 -1