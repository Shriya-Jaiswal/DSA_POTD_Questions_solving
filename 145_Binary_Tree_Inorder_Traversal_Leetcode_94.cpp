#include<iostream>
#include<queue>
#include<list>
using namespace std;

// ▶️ Ask by :  Microsoft 4 | Amazon 4 | Apple 3 | Adobe 2

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


// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) - Not including result array

vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    Node* curr = root;
    Node* pre;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            result.push_back(curr->data);
            curr = curr->right;
        } else {
            pre = curr->left;    
            while (pre->right != nullptr) {
                pre = pre->right;
            }    
            pre->right = curr;
            Node* temp = curr;
            curr = curr->left;
            temp->left = nullptr;
        }
    }
    return result;    
}


// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1) - Not including result array

// ▶️ Not working

//  public List<Integer> inorderTraversal(TreeNode root) {
//         List<Integer> result = new ArrayList<>();
//         TreeNode curr = root;
//         TreeNode pre;

//         while (curr != null) {
//             if (curr.left == null) {
//                 result.add(curr.val);
//                 curr = curr.right;
//             } else {
//                 pre = curr.left;

//                 while (pre.right != null) {
//                     pre = pre.right;
//                 }

//                 pre.right = curr;
//                 TreeNode temp = curr;
//                 curr = curr.left;
//                 temp.left = null;
//             }
//         }

//         return result;
// }



int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    vector<int> ans = inorderTraversal(root);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


// 1 -1 2 3 -1 -1 -1