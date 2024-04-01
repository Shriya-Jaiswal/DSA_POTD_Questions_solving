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

// ▶️ code

long long int merge(vector<int>&arr, long long low, long long mid, long long high){
    long long temp[high-low+1];
    long long int k=0;
    long long int i=low;
    long long int j=mid+1;
    long long int inv=0;
        
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            inv+= mid-i +1;
            temp[k++]=arr[j++];
        }
    }
        
    while(i<=mid){
        temp[k++]=arr[i++];
    }
        
    while(j<=high){
        temp[k++]=arr[j++];
    }
        
    for(int x=low; x<=high; x++){
        arr[x]=temp[x-low];
    }
        
    return inv;
}
    
long long int mergeSort(vector<int>&arr, long long int low, long long int high){
    if(low>=high) return 0;
    long long int inv=0;    
    long long mid= (low+high)/2;  
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    inv += merge(arr, low, mid, high);      
    return inv;
}
    
long long int inversionCount(vector<int>&arr, long long N){
    long long int ans= mergeSort(arr, 0, N-1);
    return ans;   
}


void inorder(Node*root, vector<int>&arr){
    if(root){
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    return;
}

/*You are required to complete below function */
int pairsViolatingBST(int n, Node *root) {
    // your code goes here
    // store inorder traversal
    vector<int>arr;
    inorder(root, arr);
        
    // i just want to retun count inversion of arr
    long long N=n;
    return int(inversionCount(arr, N));
}

 
// ⏲️ Expected Time Complexity: O(n*logn)
// 🛢️ Expected Space Complexity: O(n)

int main()
{
    Node* root = NULL;
    cout << "enter the data for Node : " << endl;
    takeInput(root);

    cout << "printing the tree : " << endl;
    levelOrderTraversal(root);

    int n = 6;
    int ans = pairsViolatingBST(n,root);
    cout << "ans is : " << ans << endl;
    return 0;
}

// 10 50 40 20 30 -1
// 80 40 70 30 60 70 -1
