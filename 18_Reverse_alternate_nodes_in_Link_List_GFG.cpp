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


Node* reverse(Node* head){
    if(!head || !head-> next){
        return head;
    }
    Node* smallHead = reverse(head-> next);
    Node* temp = head;
    temp -> next->next = head;
    temp->next = NULL;
    return smallHead;
}


void rearrange(struct Node *odd)
{
        Node* first = odd;
        Node* second = odd->next;
        Node* temp = odd->next;
        while(first->next && second -> next){
            first -> next = first->next->next;
            first = first-> next;
            second-> next = second -> next -> next;
            second = second -> next;
        } 
    
        // 👉 second = reverse(second)
        first -> next = reverse(temp);
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,9);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,9);
    insertAtTail(head,tail,4);

    print(head);
    
    rearrange(head);
    print(head);
    return 0;
}
