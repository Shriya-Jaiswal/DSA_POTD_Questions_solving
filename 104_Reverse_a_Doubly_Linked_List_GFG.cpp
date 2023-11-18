#include<iostream>
using namespace std;

// ▶️ D-E-Shaw Adobe

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(){
            this->data = 0;
            this->prev= NULL;
            this->next = NULL;
    }

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
            int val = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free for node with value = "<< val<<endl;
        }

    // ~Node(){
    //     cout << "Node with value: " << this->data << " deleted" << endl;
    // }
};


// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗

// 👉 printing

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout<< " NULL " << endl;
} 
// ⏲️ Time complexity O(n);
// 🛢️ Space complexity O(1)

// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗



// ▶️ insertAtTail
void insertAtTail(Node* &head, Node* &tail, int data){

    // 👉 check LL is empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
    // 👉  LL is not empty
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}



// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗
// // ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ❗ ▶️ ▶️ ▶️ ▶️ ❗ ❗ ❗ ❗


Node* reverseDLL(Node * head)
{
    Node* front = head;
    Node* last = head;
    int n=0;
    while(last->next!=NULL){
        last = last->next;
        n++;
    }
    int i=0;
    while(i<=n/2){
        int x = front->data;
        front->data = last->data;
        last->data = x;
        front = front->next;
        last = last->prev;
        i++;
    }
    return head;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,75);
    insertAtTail(head,tail,122);
    insertAtTail(head,tail,59);
    insertAtTail(head,tail,196);

    print(head);

    // Node* prev = NULL;
    // Node* curr = head;

    cout << "printing reverse list" << endl;

    head = reverseDLL(head);
    print(head);
    cout<< endl;

    return 0;
}
