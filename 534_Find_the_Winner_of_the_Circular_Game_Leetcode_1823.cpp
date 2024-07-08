#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Goldman Sachs ✯   Bloomberg ✯  Amazon

// // ▶️ Approach-1 (Brute Force - Simple Simulation)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(n)

// int findTheWinner(int n, int k) {
//     vector<int> arr;
//     for(int i = 1; i <= n; i++) {
//         arr.push_back(i);
//     }
//     int i = 0; //Game starts from 1st player which is sitting at index 0 in arr
//     while(arr.size() > 1) {
//         int idx = (i + k - 1) % arr.size();
//         arr.erase(arr.begin() + idx);
//         i = idx;
//     }
//     return arr[0];
// }


// // ▶️ Approach-2 (Using Queue for Simulation)
// // ⏲️ Time Complexity : O(n*k)
// // 🛢️ Space Complexity : O(n)

// int findTheWinner(int n, int k) {
//     queue<int> que;
//     for(int i = 1; i <= n; i++) {
//         que.push(i);
//     }
//     while(que.size() > 1) {
//         for(int count = 1; count <= k-1; count++) {
//             que.push(que.front());
//             que.pop();
//         }
//         que.pop();
//     }
//     return que.front();
// }


// ▶️ Approach-3 (Using Recursion)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1), but note that it will take o(n) system stack space

int findWinnerIdx(int n, int k) {
    if(n == 1) {
        return 0; //index
    }
    int idx = findWinnerIdx(n-1, k);
    idx = (idx + k) % n; //to find the original index in the original array
    return idx;
}

int findTheWinner(int n, int k) {  
    int result_idx = findWinnerIdx(n, k);
    return result_idx + 1;
}



int main()
{
    int  n = 5;
    int k = 2;
    int ans = findTheWinner(n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
