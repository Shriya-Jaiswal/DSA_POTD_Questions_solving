#include<iostream>
#include<vector>
#include<unordered_set>
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


// ▶️ Ask by :  Amazon ✯   Paytm ✯   VMWare ✯   Accolite ✯   OYO ✯   Samsung   Snapdeal   DE Shaw   Hike   MakeMyTrip   Walmart   MAQ Software   Adobe   SAP Labs   Qualcomm   Veritas   Mahindra Comviva   Lybrate   TCS   Deutsche Bank   Spotify   Microsoft   Oracle   Visa   Google   Goldman Sachs   Wells Fargo   Sterlite Technologies Limited   Grab   Dunzo   RIVIGO   Siemens   Cognizant   Barclays   Swiggy   Capgemini   BNY Mellon   Paypal   Informatica   Ola   Delhivery   Protium   Accenture   Natwest Group   Thales   Morgan Stanley   HSBC   American Express   Expedia Group   Phone Pe   Salesforce   Quikr   Publicis Sapient   Groww   Cisco   Urban Company   Freshworks   Rakuten   Infosys   Indus Valley Partners   Rudder Analytics   Globant   Pegasystems   Hedonova   MobiKwik   Amdocs   FICO   Aricent Technologies Limited   HashedIn   KPMG   Hexaview Technologies   Antino Labs Pvt Ltd   Ion Trading   Bharti Airtel   IEO MAKERS FABLAB (OPC) PRIVATE LIMITED   Park+   Providence Global Center LLP   FourKites   Nagarro   WinZO   MINDZITA (OPC) PRIVATE LIMITED   Valuefy Solutions   Truminds Software Systems   Born group   Tekion Corp   Verifone   Adidas   RedBus   Unthinkable Solutions   MindTickle   Spinny   99acres   Happiest Minds Technologies Limited   NetApp India Pvt Ltd   Cadence Design Systems   Magicbricks   Rapido   Bristlecone   Juniper Networks   F5 Networks   Symphony Talent, LLC   Thoughts2Binary Consulting and Solutions   Strategic IP Information Pte Ltd.   Persistent Systems   Tata Cliq   CRED   EPAM Systems   BirdEye   Jio Platforms Limited   Shell india   Osmosiss   Accion Labs Private Limited   Nagaaro   42gearMobilitySystems   Nippon Audiotronix limited   Wheelseye Technology   Velocity Software Pvt. Ltd.   Athenahealth   Chaayos   John Deere India Pvt. Ltd. (JDTCI)   SLK SOFTWARE   Nike   Bloomberg   Oodles Technologies Pvt Ltd   Synopsys   Veridic Private Limited   Cleartrail Technologies   MX Player   Coinbase   Green apple   Cloudera   Blackrock  


// ▶️Approach 1
 bool hasCycle(Node *head) {   
    unordered_set<Node*> se;
    while(head){
        if(se.find(head)!=se.end())
            return true;
            
        se.insert(head);
        head=head->next;
    }
    return false;
}

// // ➡️ Approach 2  
// bool hasCycle(Node *head) {
//     Node* slow=head,*fast=head;
//     while(slow && fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
            
//         if(slow==fast)
//             return true;
//     }
//     return false;   
// }

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,0);
    insertAtTail(head,tail,-4);

    bool ans = hasCycle(head);
    cout << "ans is : " << ans << endl;

    return 0;
}
