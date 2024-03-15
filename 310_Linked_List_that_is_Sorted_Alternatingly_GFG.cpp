#include<iostream>
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

// ▶️ Ask by : Amazon
void sort(Node **head)
    {
         // Code here
         Node *head1=new Node(0),*head2=new Node(0);
         Node *temp1=head1,*temp2=head2,*temp=*head;
         bool indication=true;
         while(temp){
             if(indication){
                 temp1->next=temp;
                 temp1=temp1->next;
             }
             else{
                 temp2->next=temp;
                 temp2=temp2->next;
             }
             temp=temp->next;
             indication=!indication;
         }
         temp1->next=NULL;
         temp2->next=NULL;
         Node *curr=head2,*prev=NULL,*nxt=head2->next;
         while(curr){
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
         }
         temp=prev;
         while(prev){
             if(prev->next==head2){
                 prev->next=NULL;
             }
             prev=prev->next;
         }
         Node *ans = new Node(0);
         head2=ans;
         head1=head1->next;
         while(head1 and temp){
             if(head1->data<=temp->data){
                 ans->next=head1;
                 head1=head1->next;
             }
             else{
                 ans->next=temp;
                 temp=temp->next;
             }
             ans=ans->next;
         }
         while(head1){
             ans->next=head1;
             head1=head1->next;
             ans=ans->next;
         }
         while(temp){
             ans->next=temp;
             temp=temp->next;
             ans=ans->next;
         }
         *head=head2->next;
    }



// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,9);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,7);

    sort(&head);

    print(head);

    return 0;
}
