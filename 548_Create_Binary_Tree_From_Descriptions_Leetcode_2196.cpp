#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
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


// ▶️ Ask by :  Google ✯   Uber ✯   LinkedIn ✯   Clari ✯  


// ▶️ Simple Approach using map and set
// ⏲️ Time Complexity : O(n), where n is the size of descriptions
// 🛢️ Space Complexity : O(n), size of map and set

Node* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, Node*> mp;
    unordered_set<int> childSet; //they can never be root of the tree


    for(vector<int>& vec : descriptions) { //O(n)
        int parent = vec[0];
        int child  = vec[1];
        int isLeft = vec[2];

        if(mp.find(parent) == mp.end()) {
            mp[parent] = new Node(parent);
        }

        if(mp.find(child) == mp.end()) {
            mp[child] = new Node(child);
        }

        if(isLeft == 1) { //left child  
            mp[parent]->left = mp[child];
        } else {
            mp[parent]->right = mp[child];
        }

        childSet.insert(child);
    }


    //Find the root
    for(vector<int>& vec : descriptions) { //O(n)
        int parent = vec[0];
        if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
            return mp[parent];
        }
    }

    return NULL; //we will never reach here
}


int main()
{
    // Node* root = NULL;
    // root = buildTree();
    // levelOrderTraversalLikeTree(root);
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    Node* ans = createBinaryTree(descriptions);
    levelOrderTraversalLikeTree(ans);
    return 0;
}
