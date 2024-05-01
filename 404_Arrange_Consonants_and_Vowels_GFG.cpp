#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
    public:
        char data;
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

// task is to complete this function
// function should return head to the list after making 
// necessary arrangements

struct Node* arrangeCV(Node *head)
{
       
    if(!head || !head->next) return head;
    unordered_set<char> st={'a','e','i','o','u'};
       
    Node*temp=head, *tail;
    int cons=0, length=0;
    while(temp){
        if(st.find(temp->data)==st.end()){
            cons++;
        }
        length++;
        if(temp->next==NULL){
            tail=temp;
        }
        temp=temp->next;
    }
       
    if(cons==0 || length==cons){
        return head;
    }
        
        while(head && st.find(head->data)==st.end()){
            Node* x=head;
            head=head->next;
            tail->next=x;
            tail=x;
            x->next=NULL;
            cons--;
        }
    temp=head;
    Node*prev=NULL;
    while(cons){
        if(tail==temp){
            break;
        }
        if(st.find(temp->data)==st.end()){
            prev->next=temp->next;
            tail->next=temp;
            temp->next=NULL;
            tail=temp;
            cons--;
            temp=prev->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
       
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,'a');
    insertAtTail(head,tail,'b');
    insertAtTail(head,tail,'c');
    insertAtTail(head,tail,'d');
    insertAtTail(head,tail,'e');
    insertAtTail(head,tail,'f');
    insertAtTail(head,tail,'g');
    insertAtTail(head,tail,'h');
    insertAtTail(head,tail,'i');

    Node* ans = arrangeCV(head);
    print(ans);
    return 0;
}
