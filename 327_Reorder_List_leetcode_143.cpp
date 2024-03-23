#include<iostream>
#include<vector>
#include<stack>
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





// // ▶️ Ask by :  Amazon ✯   Microsoft ✯   Adobe ✯   Facebook ✯   Bloomberg ✯   Uber   Samsung  

// // ▶️ Approach-1 (Using stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// void reorderList(Node* head) {
//     stack<Node*> st;  
//     Node* curr = head;
//     while(curr) {
//         st.push(curr);
//         curr = curr->next;
//     }
//     int k = st.size()/2;
//     curr = head;
//     while(k--) {
//         Node* topNode = st.top();
//         st.pop();
//         Node* temp = curr->next;
//         curr->next = topNode;
//         topNode->next = temp;
//         curr = temp;
//     }
//     curr->next = NULL;
// }


// // ▶️ Approach-2 (without stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Spac Complexity : O(1) AUxiliary, O(n) Recursion stack space


// Node* reverseLL(Node* node) {
//     if(node == NULL || node->next == NULL)
//         return node;
//     Node* last = reverseLL(node->next);
//     node->next->next = node;
//     node->next = NULL;
//     return last;
// }
    
// void reorderList(Node* head) {
//     if(!head || !head->next || !head->next->next)
//         return;
        
//     Node* slow = head;
//     Node* fast = head;
//     while(fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     Node* revHalf = reverseLL(slow);
        
//     Node* curr = head;
//     while(revHalf->next) {
//         Node* tempFront = curr->next;
//         curr->next          = revHalf;
            
//         Node* tempBack  = revHalf->next;
//         revHalf->next       = tempFront;
            
//         revHalf             = tempBack;
//         curr                = tempFront;
//     }
// }


// ▶️ Approach-3 (Only Recursion)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) AUxiliary SPace and O(n) Recursion Stack Space

Node* curr;
void solve(Node* head) {
    if(!head) {
        return;
    }    
    solve(head->next);
    Node* tempn = curr->next;
    if(tempn == NULL) {
        return;
    } else if(head == curr) {
        head->next = NULL;
        return;
    }     
    curr->next = head;
    head->next = tempn == head ? NULL : tempn;    
    curr = tempn;
}
    
void reorderList(Node* head) {
    curr = head;
    solve(head);
}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);

    print(head);

    reorderList(head);

    print(head);
    return 0;
}
