#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node*  next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        } 

     ~Node(){
            int val = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free of node with value = "<< val <<endl;
        // cout << "Node with value: " << this->data << " deleted" << endl;
    }
};
 

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


// 👉 printing

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout<< " NULL " << endl;
}



Node *sortedInsert(struct Node* head, int data) {
    if(data < head -> data){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }    
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL && temp -> data <= data){
        prev = temp;
        temp = temp -> next;
    }
    Node* newNode =  new Node(data);
    newNode -> next = temp;
    prev -> next = newNode;
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,25);
    insertAtTail(head,tail,36);
    insertAtTail(head,tail,47);
    insertAtTail(head,tail,58);
    insertAtTail(head,tail,69);
    insertAtTail(head,tail,80);

    print(head);

    Node* ans = sortedInsert(head,19);
    print(ans);

    return 0;
}
