#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
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


// ▶️ Ask by : Paytm | Flipkart | Accolite | Amazon | OYO Rooms | Samsung | Snapdeal | MakeMyTrip | Ola Cabs | Adobe | Qualcomm | Twitter | Knowlarity | Open Solutions

vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int size=q.size();
       ans.push_back(q.front()->data);
       while(size--){
           Node* t=q.front();
           q.pop();
           if(t->left) q.push(t->left);
           if(t->right) q.push(t->right);
       }
   }
   return ans;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(N).

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    vector<int> ans = leftView(root);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 1 3 -1 -1 2 -1 -1
