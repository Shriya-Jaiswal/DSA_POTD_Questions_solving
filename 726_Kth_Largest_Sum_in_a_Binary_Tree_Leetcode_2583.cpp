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


// ▶️ Ask by :  Amazon ✯   Bloomberg ✯  

long kthLargestLevelSum(Node* root, int k) {
    priority_queue<long, vector<long>, greater<long>> pq; //Min Heap

    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        int n    = que.size();
        long levelSum = 0;
        while (n--) {
            Node* poppedNode = que.front();
            que.pop();
            levelSum += poppedNode->data;
            if (poppedNode->left != NULL) {
                que.push(poppedNode->left);
            }
            if (poppedNode->right != NULL) {
                que.push(poppedNode->right);
            }
        }

        pq.push(levelSum);

        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.size() < k ? -1 : pq.top();
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int k = 2;
    long ans = kthLargestLevelSum(root,k);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 5 8 2 4 -1 -1 6 -1 -1 1 -1 -1 9 3 -1 -1 7 -1 -1