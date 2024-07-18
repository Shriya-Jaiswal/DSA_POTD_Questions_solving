#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
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


// ▶️ Ask by :  Tiktok ✯   Josh Technologies ✯   Apple ✯   ByteDance ✯   Google ✯  

// ▶️ Approach-1 (Using Graph and BFS)
// ⏲️ Time Complexity : O(n^2)
// 🛢️ Space Complexity : O(n)

void makeGraph(Node* root, Node* prev, unordered_map<Node*, vector<Node*>>& adj, 
                    unordered_set<Node*>& st) {

    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) { //LEAF NODE
        st.insert(root);
    }

    if(prev != NULL) {
        adj[root].push_back(prev);
        adj[prev].push_back(root);
    }

    makeGraph(root->left, root, adj, st);
    makeGraph(root->right, root, adj, st);

}

int countPairs(Node* root, int distance) {
    unordered_map<Node*, vector<Node*>> adj; //Graph
    unordered_set<Node*> st; //leaf nodes

    makeGraph(root, NULL, adj, st);

    int count = 0; //count of good node pairs

    for(auto &leaf : st) {

        //BFS hit karo and see if you can find another leaf nodes within distance
        queue<Node*> que;
        unordered_set<Node*> visited;
        que.push(leaf);
        visited.insert(leaf);


        for(int level = 0; level <= distance; level++) { //only go till level <= distance
            int size = que.size();
            while(size--) { //level processed
                Node* curr = que.front();
                que.pop();

                if(curr != leaf && st.count(curr)) { 
                    count++;
                }

                for(auto &ngbr : adj[curr]) {
                    if(!visited.count(ngbr)) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
        }
    }
    return count/2;
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int distance = 3;
    int ans = countPairs(root,distance);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 1 2 -1 4 -1 -1 3 -1 -1
