#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Leetcode medium 1845
// ▶️ ask by -->  

// // ▶️ Approach-1 (Brute Force) - T.L.E
// // ▶️ T.C : O(m * n) , where m = number of calls and n = time taken to reserve
// // ▶️ S.C : O(n)

// class SeatManager {
// public:
    
//     vector<int> t;
//     int N;
//     SeatManager(int n) {
//         N = n;
//         t.resize(n+1, -1); // 👉 unreserved 
//     }
    
//     int reserve() {
//         for(int i=1l i<N+1; i++){
//             if(t[i] == -1){
//                 t[i] = 1; // 👉 reserved
//                 return i;
//             }
//         }
//         return -1;
//     }
    
//     void unreserve(int seatNumber) {
//         t[seatNumber] = -1; // 👉 unreserved
//     }
// };



// // ▶️ Approach-2 - Reducing the time taken by reserve (Accepted)
// // ▶️ T.C : O((m+n) * logn)
// // ▶️ S.C : O(n)


// class SeatManager {
// public:
//     priority_queue<int,vector<int>,greater<int>> pq;
//     SeatManager(int n) {
//         for(int i=1; i<=n; i++){ // 👉 O(n)
//             pq.push(i); // 👉 O(logn)
//         }
//     }
    
//     int reserve() {
//         int seat = pq.top();
//         pq.pop();
//         return seat;
//     }
    
//     void unreserve(int seatNumber) {
//         pq.push(seatNumber);
//     }
// };


// // ▶️ Approach-3 (Improving Approach-2) - Avoiding pre-initialising of heap
// // ▶️ T.C : O(m* log(n)) , where m = number of reserve calls
// // ▶️ S.C : O(n)

class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int seat_marker; // 👉 seat marker will be put smallest unreserved seat 
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        // 👉 in this time priority queue will be empty
        if(!pq.empty()){
            int seat = pq.top();
            pq.pop();
            return seat;
        }

        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};



int main()
{
    // // 👉 Your SeatManager object will be instantiated and called as such:
    // SeatManager* obj = new SeatManager(n);
    // int param_1 = obj->reserve();
    // obj->unreserve(seatNumber);
    return 0;
}
