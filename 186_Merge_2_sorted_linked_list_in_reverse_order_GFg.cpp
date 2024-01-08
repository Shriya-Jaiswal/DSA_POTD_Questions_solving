#include<iostream>
#include<queue>
using namespace std;


// ⏬ Ask by : Microsoft

class Node{
    public:
        int data;
        Node* next;

// ➡️ constructor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
// ➡️ destructor
    ~Node(){
        cout<< "destructor called " << this -> data << endl;
    }
};

// 👉 printing the Linked List

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<"-> ";
        temp = temp -> next;
    }
    cout<< "NULL" << endl;
}


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



 struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1 == NULL and node2 == NULL){
            return NULL;
        }
        Node *present = NULL;
        while(node1 != NULL and node2 != NULL){
            if(node1 -> data <= node2 -> data){
                Node *temp = node1 -> next;
                node1 -> next = present;
                present = node1;
                node1 = temp;
            }else{
                Node *temp = node2 -> next;
                node2 -> next = present;
                present = node2;
                node2 = temp;
            }
        }
        while(node1 != NULL){
            Node *temp = node1 -> next;
            node1 -> next = present;
            present = node1;
            node1 = temp;
        }
        while(node2 != NULL){
            Node *temp = node2 -> next;
            node2 -> next = present;
            present = node2;
            node2 = temp;
        }
        return present;
    }  

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(head1,tail1,5);
    insertAtTail(head1,tail1,10);
    insertAtTail(head1,tail1,15);
    insertAtTail(head1,tail1,40);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(head2,tail2,2);
    insertAtTail(head2,tail2,3);
    insertAtTail(head2,tail2,20);

    print(head1);
    print(head2);

    Node* ans = mergeResult(head1, head2);
    print(ans);

    return 0;
}
