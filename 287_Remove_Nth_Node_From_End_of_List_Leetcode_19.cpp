#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Microsoft ✯   Google ✯   Bloomberg ✯   Walmart Global Tech   Apple   Uber  



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


// // ▶️ Approach-1 (2 Pass)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

//  int lengthLinkedList(Node* head) {
//         int l = 0;
//         while(head) {
//             l++;
//             head = head->next;
//         }
//         return l;
//     }
    
//     Node* removeNthFromEnd(Node* head, int n) {
//         int length = lengthLinkedList(head);
        
//         if(length == n) { //Length node form end means first node
//             Node* temp = head->next;
//             delete(head);
//             return temp;
//         }
//         Node* temp = head;
//         Node* prev = NULL;
//         int travel = length-n;
//         while(travel--) {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = temp->next;
//         delete(temp);   
//         return head;  
// }


// ▶️ Approach-2 (1 Pass)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
        
    for(int i = 1; i <= n; i++) {
        fast = fast->next;
    }
    if(fast == NULL) {
        return head->next;
    }
        
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
        
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);

    int n = 2;
    Node* ans = removeNthFromEnd(head,n);
    print(ans);
    return 0;
}
