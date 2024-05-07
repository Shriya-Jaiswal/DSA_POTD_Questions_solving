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


// // ▶️ Ask by :  Nvidia ✯   Amazon ✯  

// // ▶️ Approach-1 (Using Reverse of LinkedList)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// Node* reverseList(Node* head) {
//     if(head == NULL || head->next == NULL) {
//         return head;
//     }
        
//     Node* last = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
        
//     return last;
        
// }
    
// Node* doubleIt(Node* head) {
//     head = reverseList(head);
        
//     Node* curr = head;
//     Node* prev = NULL;
//     int carry = 0;
        
//     while(curr != NULL) {
            
//         int newValue = curr->data * 2 + carry;
//         curr->data = newValue%10;
            
//         if(newValue >= 10) {
//             carry = 1;
//         } else {
//             carry = 0;
//         }
            
//         prev = curr;
//         curr = curr->next;
            
//     }
        
//     if(carry != 0) {
//         Node* newHead = new Node(carry);
//         prev->next = newHead;
//     }
        
        
//     return reverseList(head);
// }


// // ▶️ Approach-2 (Using Recursion)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n) system stack space

// int doubleUtil(Node* head) {
//     if(head == NULL)
//         return 0;
        
//     int carry  = doubleUtil(head->next);
//     int newVal = (head->data)*2 + carry;
//     head->data = newVal%10;
        
        
//     return newVal/10;
        
// }
    
// Node* doubleIt(Node* head) { 
//     int lastCarry = doubleUtil(head);
//     if(lastCarry > 0) {
//         Node* newHead = new Node(lastCarry);
//         newHead->next = head;
//         return newHead;
//     } 
//     return head;
// }


// // ▶️ Approach-3 (Using prev and curr left to right traversal)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// Node* doubleIt(Node* head) {
//     Node* curr = head;
//     Node* prev = NULL;
        
//     while(curr != NULL) {
            
//         int newVal = curr->data * 2;
            
//         if(newVal < 10) {
//             curr->data = newVal;
//         } else if(prev != NULL) {
//             curr->data = newVal%10;
                
//             prev->data += 1;
//         } else { //prev is NULL means we are standing at head node
//             Node* newHead = new Node(1);
//             newHead->next = curr;
//             curr->data = newVal%10;
//             head = newHead;
//         }
            
//         prev = curr;
//         curr = curr->next;
//     }    
//     return head;
// }



// ▶️ Approach-4 (Using one pointer left to right traversal)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

Node* doubleIt(Node* head) {
    if(head->data >= 5) {
        Node* newHead = new Node(0);
        newHead->next = head;
        head = newHead;
        //head = new ListNode(0, head);
    }
    Node* curr = head;
    while(curr != NULL) {
        curr->data = (curr->data * 2)%10;   
        if(curr->next != NULL && curr->next->data >= 5) {
            curr->data += 1;
        }
        curr = curr->next;
            
    }
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,9);

    Node* ans = doubleIt(head);
    print(ans);

    return 0;
}
