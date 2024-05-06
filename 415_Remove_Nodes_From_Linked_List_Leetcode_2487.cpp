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



// // ▶️ Ask by :  Amazon ✯   Bloomberg ✯  

// // ▶️ Approach-1 (Using stack)
// // ⏲️ Time Complexity  : O(n)
// // 🛢️ Space Complexity  : O(n)

// Node* removeNodes(Node* head) {
//     stack<Node*> st;
//     Node* current = head;

//     while (current != nullptr) {
//         st.push(current);
//         current = current->next;
//     }

//     current = st.top();
//     st.pop();
//     int maximum = current->data;
//     Node* resultHead = new Node(maximum);

//     while (!st.empty()) {
//         current = st.top();
//         st.pop();
//         if (current->data < maximum) {
//             continue;
//         }
//         else {
//             Node* newNode = new Node(current->data);
//             newNode->next = resultHead;
//             resultHead = newNode;
//             maximum = current->data;
//         }
//     }

//     return resultHead;
// }




// // ▶️ Approach-2 (Using Recursion - instead of stack, use system's stack)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n) system stack

// Node* removeNodes(Node* head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     Node* nextNode = removeNodes(head->next);

//     if (head->data < nextNode->data) {
//         delete head;
//         return nextNode;
//     }
//     head->next = nextNode;
//     return head;
// }


// ▶️ Approach-3 (Using reverse)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)
 
Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
        
    Node* last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
        
    return last;
}


Node* removeNodes(Node* head) {
    head = reverseList(head);

    int maximum = 0;
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        maximum = max(maximum, current->data);

        if (current->data < maximum) {
            prev->next = current->next;
            Node* deleted = current;
            current = current->next;
            delete(deleted);
        }

        else {
            prev = current;
            current = current->next;
        }
    }    
    return reverseList(head);
}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,5);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,8);

    print(head);

    cout << endl;

    Node* ans = removeNodes(head);
    print(ans);

    return 0;
}
