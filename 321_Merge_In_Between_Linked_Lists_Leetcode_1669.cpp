#include<iostream>
#include<vector>
using namespace std;



class Node{
    public:
        int data;
        Node* next;

// ➡️ constructor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
// ➡️ destructor
    ~Node(){
        cout<< "destructor called " << this -> data << endl;
    }
};

// 👉 printing the Linked List

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<"-> ";
        temp = temp -> next;
    }
    cout<< "NULL" << endl;
}


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


// ▶️ Ask by :  Amazon ✯   Apple ✯   VMWare ✯  

// ⏲️ Time Complexity : O(m+n)
// 🛢️ Space Complexity : O(1)

Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {
    Node* left  = NULL;
    Node* right = list1;
    for(int i = 0; i <= b; i++) {
        if(i == a-1) {
            left = right;
        }
        right = right->next;
    } 
    left->next = list2;   
    Node* temp = list2;
    while(temp && temp->next) {
        temp = temp->next;
    }
    temp->next = right;
    return list1;  
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(head1,tail1,10);
    insertAtTail(head1,tail1,1);
    insertAtTail(head1,tail1,13);
    insertAtTail(head1,tail1,6);
    insertAtTail(head1,tail1,9);
    insertAtTail(head1,tail1,5);

    int a = 3;
    int b = 4;

    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(head2,tail2,1000000);
    insertAtTail(head2,tail2,1000001);
    insertAtTail(head2,tail2,1000002);

    Node* ans = mergeInBetween(head1,a,b,head2);
    print(ans);

    return 0;
}
