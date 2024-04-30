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



// ▶️ Ask by : Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | Snapdeal | MakeMyTrip | Qualcomm

Node* reverse(Node* head){
    if(!head || !head->next) return head;

    Node*prev=NULL, *temp=head, *next=head->next;
    while(next){
        temp->next=prev;
        prev=temp;
        temp=next;
        next=temp->next;
    }
    temp->next=prev;

    return temp;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    if(!l1) return l2;
    if(!l2) return l1;


    Node* head=l1;

    Node* tail;

    int carry=0;
    while(l1 && l2){
        l1->data += carry+l2->data;
        carry=l1->data/10;
        l1->data %= 10;

        tail=l1;

        l1=l1->next;
        l2=l2->next;
    }
    if(l2){
        tail->next=l2;
        l1=l2;
    }
    while(l1){
        l1->data+=carry;
        carry=l1->data/10;
        l1->data %= 10;
        tail=l1;
        l1=l1->next;
    }

    l1=tail;
    while(carry){
        l1->next=new Node(carry);
        carry=l1->data/10;
        l1->data %= 10;
        l1=l1->next;
    }
    return head;
}
//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* num1, struct Node* num2)
{
    // code here
    while(num1->next && num1->data==0){
        num1=num1->next;
    }
    while(num2->next && num2->data==0){
           num2=num2->next;
    }
    num1=reverse(num1);
    num2=reverse(num2);
    return reverse(addTwoNumbers(num1, num2));
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,5);

    insertAtTail(head2,tail2,3);
    insertAtTail(head2,tail2,4);
    insertAtTail(head2,tail2,5);

    Node* ans = addTwoLists(head1,head2);
    print(ans);
    return 0;
}
