#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// ➡️ leetcode Easy 501 ---> Ask by ---> Adobe, google

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        // 👉 this is the firt node we have to create 
        root = new Node(data);
        return root;
    }

    // 👉 not the first node
    if(root -> data > data){
        // 👉 insert in left
        root -> left = insertIntoBST(root -> left, data);
    }
    else{
        // 👉 insert in right
        root -> right = insertIntoBST(root -> right, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
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

// 👉 1️⃣ Approach ---> using map ---> but we use extra space 
unordered_map<int,int> mp; // 🛢️ O(n) space used


void dfs(Node* root){
    if(!root){ // 👉 we can write ---> root == NULL
        return ;
    }

    // 👉 inorder traversal
    dfs(root->left);
    mp[root->data]++;
    dfs(root->right);
}


vector<int> findMode_Approach_1(Node* root) {
    dfs(root);
    vector<int> result;
    int maxFreq = 0;

    for(auto &it : mp){

        if(it.second > maxFreq){
            maxFreq = it.second;
            result = {};
            result.push_back(it.first);
        }
        else if(it.second == maxFreq){
            result.push_back(it.first);
        }
    }
    return result;
}
// 👉 2️⃣ Approach ---> follow up question ---> O(1)Space ---> BSt ka inorder traversal find out karo then try to obtain streak

int currNum = 0;
int currFreq = 0;
int maxFreq = 0;
vector<int> result ;

void dfs2(Node* root){
    if(!root){
        return ;
    }
    dfs2(root -> left);

    if(root -> data == currNum){
        currFreq++;
    }
    else{
        currNum = root->data;
        currFreq = 1;
    }

    if(currFreq > maxFreq){
        result = {};
        maxFreq = currFreq;
    }

    if(currFreq == maxFreq){
        result.push_back(root->data);
    }

    dfs2(root->right);
}

vector<int> findMode_Approach_2(Node* root) {
    dfs2(root);
    return result;
}

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    // vector<int> ans = findMode_Approach_1(root);
    vector<int> ans = findMode_Approach_2(root);
    for(int i=0; i< ans.size(); i++){
        cout<< ans[i] << " ";
    }   
    cout<< endl;

    return 0;
}

// 1 2 2 -1