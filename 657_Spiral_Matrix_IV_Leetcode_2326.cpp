#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this -> data = data;
        this-> next = NULL;
    }

    ~Node(){
        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};


// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗



// 👉 printing the Linked List

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<"-> ";
        temp = temp -> next;
    }
    cout<< "NULL" << endl;
}



// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗



// 👉 insertAtTail
// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head , Node* &tail, int data){

    // 👇 firstNode
    // ➡️ check for empty Ll
    if(head == NULL){
        //  LL --> Node empty hogi, and first node add hogi
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // 👉 step create a node
    Node* newNode = new Node(data);

    tail -> next = newNode;
    
    // 👉 step 3
    tail = newNode;

}


// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗



// ▶️ Ask by : 

// ▶️ Simple SImulation
// ⏲️ Time Complexity : O(m*n)
// 🛢️ SpaceComplexity : O(1) (I am not considering the result matrix we have to return as result)

vector<vector<int>> spiralMatrix(int m, int n, Node* head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));

    int id    = 0; // 👉 0, 1, 2, 3
    int top   = 0;
    int down  = m-1;
    int left  = 0;
    int right = n-1;

    while(top <= down && left <= right) {
        if(id == 0) { // 👉 left to right
            for(int i = left; head != NULL && i <= right; i++) {
                matrix[top][i] = head->data;
                head = head->next;
            }
            top++;
        }

        if(id == 1) { // 👉 top to down
            for(int i = top; head != NULL && i <= down; i++) {
                matrix[i][right] = head->data;
                head = head->next;
            }
            right--;
        }

        if(id == 2) { // 👉 right to left
            for(int i = right; head != NULL && i >= left; i--) {
                matrix[down][i] = head->data;
                head = head->next;
            }
            down--;
        }

        if(id == 3) { // 👉 down to top
            for(int i = down; head != NULL && i >= top; i--) {
                matrix[i][left] = head->data;
                head = head->next;
            }
            left++;
        }

        id = (id+1)%4; // 👉 0, 1, 2, 3
    }

    return matrix;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int m = 3;
    int n = 5;

    insertAtTail(head,tail,3);
    insertAtTail(head,tail,0);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,9);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,0);

    vector<vector<int>> ans = spiralMatrix(m,n,head);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
