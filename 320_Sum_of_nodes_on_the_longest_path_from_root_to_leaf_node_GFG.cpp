#include<iostream>
#include<vector>
#include<queue>
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


int ans=0, mh=0;
void solve(Node* root, int h, int s){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        s+=root->data;
        if(h>mh){
            ans=s;
            mh=h;
        }
        else if(h==mh){
            ans=max(ans, s);
        }
        return ;
    }
        
    s+=root->data;
    solve(root->left, h+1, s);
    solve(root->right, h+1, s);
        
    return;
}
    
int sumOfLongRootToLeafPath(Node *root){
    solve(root, 0, 0);
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int ans = sumOfLongRootToLeafPath(root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
