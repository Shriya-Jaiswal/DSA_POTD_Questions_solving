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


bool areIdentical(struct Node *head1, struct Node *head2) {
    struct Node *t1=head1;
    struct Node *t2=head2;
    
    while(t1!=NULL || t2!=NULL){
        if(!t1 || !t2 || t1->data!= t2->data) return false;
        t1=t1->next;
        t2=t2->next;
    }
    return true;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxilliary Space: O(1)


int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(head1,tail1,1);
    insertAtTail(head1,tail1,2);
    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,5);
    insertAtTail(head1,tail1,6);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(head2,tail2,99);
    insertAtTail(head2,tail2,59);
    insertAtTail(head2,tail2,42);
    insertAtTail(head2,tail2,20);

    bool ans = areIdentical(head1,head2);
    cout << "ans is : " << ans << endl;

    return 0;
}
