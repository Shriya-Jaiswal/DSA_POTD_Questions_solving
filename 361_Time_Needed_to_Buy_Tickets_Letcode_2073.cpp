#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Twitter ✯  

// // ▶️ Approach-1 (Using Queue to simply simulate the operations)
// // ⏲️ Time Complexity : O(n*m) -> Loop runs intil queue is empty and in worst case all people have maximum m tickets 
// // 🛢️ Space Complexity : O(n)

// int timeRequiredToBuy(vector<int>& tickets, int k) {
//     int n = tickets.size();
//     queue<int> que;

//     for (int i = 0; i < n; i++) {
//         que.push(i);
//     }

//     int time = 0;

//     while (!que.empty()) {
//         time++;
//         int front = que.front();
//         que.pop();
            
//         tickets[front]--;
            
//         if (k == front && tickets[front] == 0) {
//             return time;
//         }
//         if (tickets[front] != 0) {
//             que.push(front);
//         }
//     }

//     return time;
// }

// // ▶️ Approach-2 (Using Array for simulation)
// // ⏲️ Time Complexity : O(m*n) - Outer loop will run until nums[k] is 0. So in worst case nums[k] has max value m 
// // 🛢️ space Complexity : O(1)


// int timeRequiredToBuy(vector<int>& tickets, int k) {
//     int n = tickets.size();
//     int time = 0;
//     if (tickets[k] == 1)
//         return k + 1;
//     while (tickets[k] > 0) {
//         for (int i = 0; i < n; i++) {
//             if (tickets[i] != 0) {
//                 tickets[i]--;
//                 time++;
//             }
//             if (tickets[k] == 0)
//                 return time;
//         }
//     }
//     return time;
// }

// ▶️ Approach-3 (Using simple observation)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;
    for (int i = 0; i < tickets.size(); i++) {     
        if (i <= k) {
            time += min(tickets[k], tickets[i]);
        } else {
            time += min(tickets[k] - 1, tickets[i]);
        }
    }  
    return time;
}



int main()
{
    vector<int> tickets = {2,3,2};
    int k = 2;
    int ans = timeRequiredToBuy(tickets,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
