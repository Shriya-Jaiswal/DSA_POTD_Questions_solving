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


// ▶️ Ask by : Amazon | Microsoft | Hike | Adobe

Node* solve(int in[], int pos[], int inStart, int inEnd, int posStart, int posEnd){
    if(inStart>inEnd) return NULL;
    if(inStart==inEnd){
        return new Node(in[inStart]);
    }
    Node* root= new Node(pos[posEnd]);
    int ind = -1;
    for(int i=inStart;i<=inEnd;i++){
        if(in[i]==pos[posEnd]){
            ind=i;
            break;
        }
    }
    int left=ind-inStart;
    int right=inEnd-ind;
        
    root->left=solve(in, pos, inStart,ind-1, posStart, posStart+left-1);
    root->right=solve(in, pos, ind+1, inEnd, posEnd-right, posEnd-1);
        
    return root;
}
    

//Function to return a tree created from postorder and inoreder traversals.
Node *BuildTree(int in[], int post[], int n) {
    // Your code here
    return solve(in, post, 0, n-1, 0, n-1);
        
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    Node* ans = BuildTree(in,post,n);
    levelOrderTraversalLikeTree(ans);

    return 0;
}
