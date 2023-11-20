#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;


// ▶️ Ask by --> Flipkart | Amazon | Walmart

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


int mod=1e9+7;
unordered_map<int, int>mp;
    
void solve(Node* root, int k, int sum, int& ans)
{
    if(!root) return;
        
    sum += root->data;
    ans += mp[sum-k];
    mp[sum]++;
        
    solve(root->left, k, sum,ans);
    solve(root->right, k, sum,ans);
        
    mp[sum]--;
}

int sumK(Node *root,int k)
{
    int ans=0;
    mp[0]=1;
    solve(root, k, 0,ans);
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(Height of Tree)

int main()
{
    Node* root = NULL;
	cout << "Enter the data for Node " << endl;
	takeInput(root);
	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);
	cout << endl;

    int k = 3;
    int ans = sumK(root,k);
    return 0;
}


// 1 2 -1 -1 3 -1 -1 