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


// ▶️ Ask by : Paytm | Flipkart | Accolite | Amazon | OYO Rooms | Walmart |CouponDunia

vector <int> bottomView(Node *root) {
    vector<int> ans;
    queue<pair<Node*,int>> q;
    unordered_map<int,int> mm;
    q.push({root,0});
    int mn=0,mx=0;
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        Node *temp = a.first;
        mm[a.second]=temp->data;
        mn=min(mn,a.second);
        mx=max(mx,a.second);
        if(temp->left)q.push({temp->left,a.second-1});
        if(temp->right)q.push({temp->right,a.second+1});
    }
    for(int i=mn;i<=mx;i++){
        ans.push_back(mm[i]);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    vector<int> ans = bottomView(root);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 1 3 -1 -1 2 -1 -1
