#include<iostream>
#include<vector>
#include<algorithm>
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


// // ▶️ Ask by : 

// // ▶️ Approach-1 (Iterative)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// Node* insertGreatestCommonDivisors(Node* head) {
//     if(!head || !head->next) {
//         return head;
//     }

//     Node* currNode = head;
//     Node* nextNode = head->next;

//     while(nextNode) {
//         Node* temp = new Node(__gcd(currNode->data, nextNode->data));

//         currNode->next = temp;
//         temp->next     = nextNode;

//         currNode = nextNode;
//         nextNode = nextNode->next;
//     }

//     return head;
// }


// ▶️ Approach-2 (Recursion Story)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : System stack space due to recursion O(n)

Node* insertGreatestCommonDivisors(Node* head) {
    // 👉 Base case: if head is null or there's only one node, return head.
    if (!head || !head->next) {
        return head;
    }

    // 👉 Recursively process the rest of the list
    Node* temp = insertGreatestCommonDivisors(head->next);

    // 👉 Create a new node with the GCD of current and next node values
    Node* gcdNode = new Node(__gcd(head->data, head->next->data));

    // 👉 Insert the new node between the current node and the next node
    gcdNode->next = temp;
    head->next = gcdNode;

    // 👉 Return the current node
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,18);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,3);

    Node* ans =  insertGreatestCommonDivisors(head);
    print(ans);
    return 0;
}
