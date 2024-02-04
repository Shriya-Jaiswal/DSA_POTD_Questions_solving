#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

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

// ➡️ 

int length(Node* head){
    Node* temp=head;
    int count=1;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}
    
Node* reverse(Node* head){
    Node*temp=head;
    Node* next=head->next;
    Node* prev=NULL;
    while(next){
        temp->next=prev;
        prev=temp;
        temp=next;
        next=temp->next;
    }
        
    temp->next=prev;
    return temp;
}

Node* subLinkedList(Node* head1, Node* head2) {
    // Your implementation of subLinkedList goes here
    // Make sure to return the head of the resulting linked list
    while(head1->next!=NULL && head1->data==0){
        head1=head1->next;
    }
    while(head2->next!=NULL && head2->data==0){
        head2=head2->next;
    }
        
    int n1=length(head1);
    int n2=length(head2);
        
    if(n1==0 && n2==0){
        return new Node(0);
    }
    if(n1<n2){
        return subLinkedList(head2, head1);
    }
    else if(n1==n2){
        Node*t1=head1;
        Node*t2=head2;
        while(t1 && t2 && t1->data==t2->data){
            t1=t1->next;
            t2=t2->next;
        }
        if(t1==NULL){
            return new Node(0);
        }
        else if(t1->data < t2->data){
            return subLinkedList(head2, head1);
        }
    }
        
    head1=reverse(head1);
    head2=reverse(head2);
        
    Node* t1=head1;
    Node* t2=head2;
        
    Node* res=NULL;
        
    while(t1){
        int sub=0;
        if(t2!=NULL){
            sub=t2->data;
            t2=t2->next;
        }
            
        if(t1->data < sub){
            t1->next->data-=1;
            t1->data+=10;
        }
            
        Node* n=new Node(t1->data-sub);
        t1=t1->next;
            
        n->next=res;
        res=n;
    }
        
    while(res->next && res->data==0){
        res=res->next;
    }
    return res;
    return NULL;
}

// ➡️ n and m are the length of the two linked lists respectively.
// ⏲️ Expected Time Complexity:  O(n+m)
// 🛢️ Expected Auxiliary Space: O(n+m)

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(head1,tail1,0);
    insertAtTail(head1,tail1,0);
    insertAtTail(head1,tail1,6);
    insertAtTail(head1,tail1,3);

    insertAtTail(head2,tail2,7);
    insertAtTail(head2,tail2,1);
    insertAtTail(head2,tail2,0);
    
    Node* ans = subLinkedList(head1,head2);
    print(ans);
    return 0;
}
