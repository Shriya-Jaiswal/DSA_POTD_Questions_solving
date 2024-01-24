#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Bloomberg ✯  

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

// // ▶️ Approach-1 (Simple and straight forward)
// // ⏲️ Time Compleixty : O(n)
// // 🛢️ Space Complexity : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))

// int result = 0;    
// void solve(Node* root, vector<int>& temp) {
//     if(root != NULL) {
//         temp[root->data]++;
      
//         if(root->left == NULL && root->right == NULL) {
//             int oddFreq = 0;
//             for(int i = 1; i <= 9; i++) {
//                 if(temp[i]%2 != 0) {
//                     oddFreq++;
//                 }
//             }
//             result += oddFreq <= 1;
//         }    
//         solve(root->left, temp);
//         solve(root->right, temp);   
//         temp[root->data]--;
//     }
// }
    
// int pseudoPalindromicPaths (Node* root) {
//     vector<int> temp(10, 0); 
//     solve(root, temp);
//     return result;
// }


// ▶️ Approach-2 (Using bit magic)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))

int result = 0;
    
void solve(Node* root, int temp) {
    if(root != NULL) {
            
        temp = temp ^ (1 << root->data);
            
        if(root->left == NULL && root->right == NULL) {
            if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                result++;
            }
        }
        solve(root->left, temp);
        solve(root->right, temp);
        }
    }
    
int pseudoPalindromicPaths (Node* root) {
    solve(root, 0);
    return result;
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    int ans = pseudoPalindromicPaths(root);
    cout << "ans is : " << ans << endl;

    return 0;
}

// 2 3 3 -1 -1 1 -1 -1 1 -1 1 -1 -1
