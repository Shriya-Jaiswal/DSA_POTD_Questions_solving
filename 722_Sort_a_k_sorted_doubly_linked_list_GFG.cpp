#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class DLLNode{
    public:
        int data;
        DLLNode* prev;
        DLLNode* next;

    DLLNode(){
            this->data = 0;
            this->prev= NULL;
            this->next = NULL;
    }

    DLLNode(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~DLLNode(){
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

void print(DLLNode* &head){
    DLLNode* temp = head;
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
void insertAtTail(DLLNode* &head, DLLNode* &tail, int data){

    // 👉 check LL is empty
    if(head == NULL){
        DLLNode* temp = new DLLNode(data);
        head = temp;
        tail = temp;
    }
    else{
    // 👉  LL is not empty
        DLLNode* temp = new DLLNode(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}


DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (!head) return nullptr;

        // Min-heap to store nodes
        auto cmp = [](DLLNode* a, DLLNode* b) { return a->data > b->data; };
        std::priority_queue<DLLNode*, std::vector<DLLNode*>, decltype(cmp)> minHeap(cmp);
        
        DLLNode* current = head;
        DLLNode* sortedHead = nullptr; // Head of the sorted list
        DLLNode* sortedTail = nullptr; // Tail of the sorted list
        
        // Insert first k+1 nodes into the heap
        for (int i = 0; i <= k && current; i++) {
            minHeap.push(current);
            current = current->next;
        }

        // Extract the minimum and build the sorted list
        while (!minHeap.empty()) {
            DLLNode* minNode = minHeap.top();
            minHeap.pop();

            // Add to sorted list
            if (!sortedHead) {
                sortedHead = minNode; // First node in sorted list
                sortedTail = minNode;
            } else {
                sortedTail->next = minNode;
                minNode->prev = sortedTail;
                sortedTail = minNode;
            }

            // If there are more nodes in the original list, push the next one into the heap
            if (current) {
                minHeap.push(current);
                current = current->next;
            }
        }

        // Make sure the last node points to nullptr
        if (sortedTail) {
            sortedTail->next = nullptr;
        }
        
        return sortedHead; // Return the head of the sorted list
    }

// ⏲️ Expected Time Complexity: O(n*logk)
// 🛢️ Expected Auxiliary Space: O(k)

int main()
{
    DLLNode* head = NULL;
    DLLNode* tail = NULL;
    int k = 2;
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,4);

    // DLLNode ans = sortAKSortedDLL(head,k);
    // print(ans);

    return 0;
}
