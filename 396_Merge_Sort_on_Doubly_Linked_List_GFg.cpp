#include<iostream>
using namespace std;



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


Node* merge(Node* first, Node* second){
    if(!first) return second;
    if(!second) return first;
        
    if(first->data < second->data){
        first->next= merge(first->next, second);
        first->next->prev=first;
        first->prev=NULL;
            
        return first;
    }
    else{
        second->next= merge(first, second->next);
        second->next->prev=second;
        second->prev=NULL;
            
        return second; 
       }
}
  
Node* getMid(Node* head){
    Node* fast=head, *slow=head;
        
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
        
    Node* temp=slow->next;
    slow->next=NULL;
    return temp;
}
  
// Function to sort the given doubly linked list using Merge Sort.
Node *sortDoubly( Node *head) {
    if(!head || !head->next) return head;
        
    Node* mid= getMid(head);
        
    head=sortDoubly(head);
    mid=sortDoubly(mid);
        
    return merge(head, mid);
}

int main()
{
    Node* first = new Node(7);
    Node* second = new Node(3);
    Node* third = new Node(5);

    Node* head = first;
    Node* tail = third;

    first -> next = second;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 8);

    print(head);
    cout<< endl;

    Node* ans = sortDoubly(head);
    print(ans);
    return 0;
}


