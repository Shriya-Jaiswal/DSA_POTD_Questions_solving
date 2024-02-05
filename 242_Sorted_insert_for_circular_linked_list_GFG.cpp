#include<iostream>
using namespace std;

// ▶️ Ask by : Zoho | Amazon | Microsoft

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = this;
        }
        ~Node(){
            int val = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free for node with value = "<<val<<endl;
        }
};
int findLength(Node* &head){
    int len = 1;
    Node* temp = head;
    while(temp->next != head){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Creation 
    Node* newNode = new Node(data);
    // Connection step
    tail->next = newNode;
    newNode->next = head;
    // Update tail
    tail = newNode;
}

void printList(Node* &head){
    Node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node *sortedInsert(Node* head, int data)
{
    Node *ans = new Node(data);
    if(!head){
        ans->next=ans;
        return ans;
    }
    Node *temp=head,*temp2=NULL;
    do{
        temp2=temp;
        temp=temp->next;
        if(data>=temp2->data and data<=temp->data)break;
    }while(temp!=head);
    temp2->next=ans;
    ans->next=temp;
    if(data<head->data)return ans;
    return head;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,4);

    int data = 2;
    Node* ans = sortedInsert(head,data);

    printList(ans);
    return 0;
}
