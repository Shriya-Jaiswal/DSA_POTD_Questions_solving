#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


// ▶️ Ask by : Flipkart | Amazon | Microsoft | Adobe

int t=0;
void gettime(map<Node*,Node*>&mp,Node* start){
    queue<Node*>q;
    q.push(start);
    map<Node*,int>vis;
    vis[start]=1;
    while(!q.empty()){
        int s=q.size();
        int flag=0;
        for(int i=0;i<s;i++){
            Node* node=q.front();
            q.pop();
            if(node->left&&!vis[node->left]){
                flag=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right&&!vis[node->right]){
                flag=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mp[node]&&!vis[mp[node]]){
                flag=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(flag){
            t++;
        }
    }      
}


Node* bfs(Node* root, int target,map<Node*,Node*>&mp){
    queue<Node*>q;
    Node* start;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node->data==target){
            start=node;
        }
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return start;
}

int minTime(Node* root, int target) 
{
    map<Node*,Node*>mp;
    Node* start=bfs(root,target,mp);
    gettime(mp,start);
    return t;
}

// ⏲️ Expected Time Complexity: O(number of nodes)
// 🛢️ Expected Auxiliary Space: O(height of tree)


int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int target = 8;
    int ans = minTime(root,target) ;
    cout << "ans is : " << ans << endl;
    return 0;
}

// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1