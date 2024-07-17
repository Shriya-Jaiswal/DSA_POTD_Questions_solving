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


// ▶️ Ask by : Amazon | Microsoft | Snapdeal

Node *createTree(vector<int> parent) {
    int n=parent.size();
    vector<Node*> arr(n);
    Node* root = nullptr;

    for (int i = 0; i <n; ++i) {
        if (parent[i] == -1) {
            arr[i] = new Node(i);
            root = arr[i];
        } else {
                arr[i] = new Node(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            if (arr[ parent[i] ]->left == nullptr) {
                arr[ parent[i] ]->left = arr[i];
            } else {
                arr[ parent[i] ]->right = arr[i];
            }
        }
    }
    return root;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    // Node* root = NULL;
    // root = buildTree();
    // levelOrderTraversalLikeTree(root);
    vector<int> parent = {-1, 0, 0, 1, 1, 3,5};
    Node* ans = createTree(parent);
    levelOrderTraversalLikeTree(ans);
    return 0;
}
