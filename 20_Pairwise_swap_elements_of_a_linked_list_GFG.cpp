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


Node* pairWiseSwap(struct Node* head) 
{
    Node* temp = new Node(0);    
    temp -> next = head;
    Node* prev = temp;
    Node* curr = head;
    while(curr != NULL && curr-> next != NULL){
        Node* nextNode = curr-> next;
        Node* nodeNextToNextNode = curr -> next-> next;
        nextNode -> next = curr;
        curr -> next = nodeNextToNextNode;
        prev -> next = nextNode;
        prev = curr;
        curr = nodeNextToNextNode;
    }
    return temp -> next;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,8);

    print(head);
    
    Node* ans = pairWiseSwap(head);
    print(ans);
    
    return 0;
}
