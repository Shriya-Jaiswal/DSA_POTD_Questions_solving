#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Walmart


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


// ▶️ code

Node* deleteNode(Node* head, int x) {
    if(x==1)return head->next;
    Node *temp=head;
    int count=1;
    while(count<x){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next)temp->next->prev=temp->prev;
    return head;
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxilliary Space: O(1)

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);

    print(head);
    int x = 3;
    Node * ans = deleteNode(head,x);
    print(ans);
    return 0;
}
