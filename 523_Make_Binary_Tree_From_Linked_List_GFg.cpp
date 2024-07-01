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


// ▶️ Ask by : Amazon

void constructTree(int ind, vector<int> &arr, Node* &node)
{
    node = new Node(arr[ind]);
    int leftInd = 2*ind + 1, rightInd = 2*ind + 2;
    
    if(leftInd < arr.size())
        constructTree(leftInd,arr,node->left);
    
    else
        return;
    
    if(rightInd < arr.size())
        constructTree(rightInd,arr,node->right);
    
}
void convert(Node *head, Node *&root) {
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    constructTree(0,arr,root);
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{

    return 0;
}
