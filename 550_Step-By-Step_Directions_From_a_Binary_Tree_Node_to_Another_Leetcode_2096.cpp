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


// // ▶️ Ask by :  Tiktok ✯   Databricks ✯   Spotify ✯   Google ✯   Amazon ✯   Microsoft  

// // ▶️ Approach-1 (Using LCA)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// Node* lowestCommonAncestor(Node* root, int src, int dest) {
//     if(!root)
//         return NULL;
        
//     if(root->data == src || root->data == dest)
//         return root;
        
//     Node* l = lowestCommonAncestor(root->left,  src, dest);
//     Node* r = lowestCommonAncestor(root->right, src, dest);
        
//     if(l && r)
//         return root;
        
//     return l ? l : r;
// }

// bool findPath(Node* LCA, int target, string& path) {
//     if(LCA == NULL) {
//         return false;
//     }

//     if(LCA->data == target) {
//         return true;
//     }

//     //explore Left
//     path.push_back('L');
//     if(findPath(LCA->left, target, path) == true) {
//         return true;
//     }

//     path.pop_back();

//     //explore right
//     path.push_back('R');
//     if(findPath(LCA->right, target, path) == true) {
//         return true;
//     }

//     path.pop_back();

//     return false;
// }

// string getDirections(Node* root, int startValue, int destValue) {
//     Node* LCA = lowestCommonAncestor(root, startValue, destValue);

//     string lcaTOSrc  = "";
//     string lcaTODest = "";

//     findPath(LCA, startValue, lcaTOSrc);
//     findPath(LCA, destValue, lcaTODest);

//     string result = "";

//     for(int i = 0; i < lcaTOSrc.length(); i++) {
//         result.push_back('U');
//     }

//     result += lcaTODest;

//     return result;
// }


// ▶️ Approach-2 (Without finding LCA)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

bool findPath(Node* LCA, int target, string& path) {
    if(LCA == NULL) {
        return false;
    }

    if(LCA->data == target) {
        return true;
    }

    //explore Left
    path.push_back('L');
    if(findPath(LCA->left, target, path) == true) {
        return true;
    }

    path.pop_back();

    //explore right
    path.push_back('R');
    if(findPath(LCA->right, target, path) == true) {
        return true;
    }

    path.pop_back();

    return false;
}

string getDirections(Node* root, int startValue, int destValue) {
    string rootToSrc  = "";
    string rootToDst = "";
    findPath(root, startValue, rootToSrc); //O(n)
    findPath(root, destValue,  rootToDst); //O(n)
    int l = 0; //commonPathLength
    while(l < rootToSrc.length() && l < rootToDst.length() && rootToSrc[l] == rootToDst[l]) {
        l++;
    }
    string result = "";
    //Add "U"
    for(int i = 0; i < rootToSrc.length() - l; i++) {
        result.push_back('U');
    }

    for(int i = l; i < rootToDst.length(); i++) {
        result.push_back(rootToDst[i]);
    }

    return result;
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversalLikeTree(root);
    int  startValue = 3;
    int destValue = 6;
    string ans = getDirections(root,startValue,destValue);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 5 1 3 -1 -1 2 6 -1 -1 4 -1 -1
