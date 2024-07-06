#include<iostream>
#include<vector>
using namespace std;

// // ▶️ Ask by : Microsoft

// // ▶️ Approach-1 (Simple Simulation)
// // ⏲️ Time Complexity : O(time)
// // 🛢️ Space Complexity : O(1)

// int passThePillow(int n, int time) {
//     int idx  = 1;
//     int dir  = 1;

//     while(time > 0) {
//         if(idx + dir >=1 && idx + dir <= n) {
//             idx += dir;
//             time--;
//         } else {
//             dir *= -1;
//         }
//     }
//     return idx;
// }



// ▶️ Approach-2 (Simple Maths)
// ⏲️ Time Complexity : O(1)
// 🛢️ Space Complexity : O(1)

int passThePillow(int n, int time) {
    int totalFullRounds = time / (n-1);
    int timeLeft        = time % (n-1);
    if(totalFullRounds % 2 == 0) {
        return timeLeft + 1;
    } else {
        return n - timeLeft;
    }
    return -1;
}

int main()
{
    int n = 4;
    int time = 5;
    int ans = passThePillow(n,time);
    cout << "ans is : " << ans << endl;
    return 0;
}
