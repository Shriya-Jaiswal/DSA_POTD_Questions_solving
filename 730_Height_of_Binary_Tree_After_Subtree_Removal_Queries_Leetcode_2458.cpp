#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

// ▶️ Approach - Simple Recursion and preprocessing
// ⏲️ Time Cmlexity : O(n)
// 🛢️ Sace.C : O(n)

int level[1000001]; //level of each node
int height[100001]; //height of each node
int levelMaxHt[100001];
int levelSecondMaxHt[100001];

int findHeight(Node* root, int l) {
    if(!root) {
        return 0;
    }

    level[root->data] = l;
    height[root->data] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

    if(levelMaxHt[l] < height[root->data]) {
        levelSecondMaxHt[l] = levelMaxHt[l];
        levelMaxHt[l] = height[root->data];
    } else if(levelSecondMaxHt[l] < height[root->data]) {
        levelSecondMaxHt[l] = height[root->data];
    }

    return height[root->data];
}

vector<int> treeQueries(Node* root, vector<int>& queries) {
    findHeight(root, 0);

    vector<int> result;

    for(int &node : queries) {
        //node = that we have to delete
        int L = level[node]; //O(1) //node ka level hai ye

        //L + H - 1

        int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;

        result.push_back(tempResult);
    } 

    return result;
}


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);

    vector<int>  queries = {4};
    vector<int> ans =  treeQueries(root, queries);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 1 3 2 -1 -1 4 6 -1 -1 5 -1 7 -1 -1
