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





// ▶️ ask by :  Facebook ✯   Amazon ✯   Microsoft ✯   Apple ✯   Bloomberg ✯   Google   Adobe   ServiceNow   VMware   Yahoo   Intuit  


// // ▶️ Approach-1 (Using extra space)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)


// bool isPalindrome(Node* head) {
//     vector<int> temp;

//     Node* curr = head;
//     while(curr) {
//         temp.push_back(curr->val);
//         curr = curr->next;
//     }
//     int i = 0;
//     int j = temp.size()-1;
//     while(i < j) {
//         if(temp[i] != temp[j]) 
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }


// // ▶️ Approach-2 (Reversing the 2nd half of linked list)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// Node* reverseList(Node* head) {
//     if(!head || !head->next)
//         return head;
        
//     Node* last = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return last;
// }

// bool isPalindrome(Node* head) {
//     if(!head || !head->next) {
//         return true;
//     }

//     Node* slow = head;
//     Node* fast = head;
//     Node* prev = NULL;

//     while(fast && fast->next) {
//         prev = slow;
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     Node* revhead = reverseList(slow);
//     prev->next = NULL; 
//     while(revhead != NULL && head != NULL) {
//         if(revhead->val != head->val) {
//             return false;
//         }
//         revhead = revhead->next;
//         head = head->next;
//     }
//     return true;
// }


// // ▶️ Approach-3 (Reversing the 2nd half of linked list)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)


// bool isPalindrome(Node* head) {
//     if(!head || !head->next) {
//         return true;
//     }

//     Node* slow = head;
//     Node* fast = head;
//     Node* prev = NULL;

//     while(fast && fast->next) {
//         fast = fast->next->next;
//         Node* temp = slow->next;
//         slow->next = prev;
//         prev = slow;
//         slow = temp;
//     }
//     // 👉 If the number of nodes is odd, move slow to the next node
//     if (fast)
//         slow = slow->next;
//     while(prev && slow) {
//         if(prev->data != slow->data) {
//             return false;
//         }
//         prev = prev->next;
//         slow = slow->next;
//     }
//     return true;
// }


// ▶️ Approach-4 (Using Pure Recursion - Because when recursion winds back, we can start comparing curr head with last node and so on)
// ⏲️ Time Complexity : O(n)
// 🛢️ S.C : O(1) Auxiliary space

Node* curr;
bool solve(Node* head) {
    if(!head)
        return true;
    if(!solve(head->next) || head->data != curr->data) {
        return false;
    }
    curr = curr->next;
    return true;
}

bool isPalindrome(Node* head) {
    curr = head;
    return solve(head);
}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);

    bool ans = isPalindrome(head);
    cout << "ans is : " << ans << endl;
    return 0; 
}
