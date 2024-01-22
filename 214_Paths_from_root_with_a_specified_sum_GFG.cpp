#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

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


void dfs(Node* root, int sum, int target,vector<int>&temp,vector<vector<int>>&ans){
    if(!root) return;
    temp.push_back(root->data);
    if(sum+root->data==target){
        ans.push_back(temp);
    }
    dfs(root->left,sum+root->data,target,temp,ans);
    dfs(root->right,sum+root->data,target,temp,ans);
    temp.pop_back();
}


vector<vector<int>> printPaths(Node *root, int sum){
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(root,0,sum,temp,ans);
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Space Complexity: O(N2)

int main()
{
    Node* root = NULL;
    root = buildTree();
    int sum = 8;
    vector<vector<int>> ans = printPaths(root,sum);
    for(int i=0; i< ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
// 1 20 -1 -1 3 4 6 -1 -1 7 -1 -1 15 8 -1 -1 9 -1 -1