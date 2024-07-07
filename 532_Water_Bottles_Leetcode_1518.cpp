#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  IBM ✯   Amazon ✯   Microsoft ✯  

// // ▶️ Approach-1 (Simple simulation)
// // ⏲️ Time Complexity : O(numBottles)
// // 🛢️ Space Complexity : O(1)

// int numWaterBottles(int numBottles, int numExchange) {
//     int consumed = 0;
//     while(numBottles >= numExchange) {
//         consumed   += numExchange;
//         numBottles -= numExchange;

//         numBottles += 1;

//     }
//     return consumed + numBottles;
// }

// // ▶️ Approach-2 (Improvement on Approach-1)
// // ⏲️ Time Complexity : O(log_numExchange_(numBottles))
// // 🛢️ Space Complexity : O(1)

// int numWaterBottles(int numBottles, int numExchange) {
//     int consumed = numBottles;
//     int emptyBottles = numBottles;

//     while(emptyBottles >= numExchange) {
//         int extraFullBottles = emptyBottles / numExchange;

//         int remain = emptyBottles % numExchange;

//         consumed += extraFullBottles;

//         emptyBottles = remain + extraFullBottles;
//     }

//     return consumed;
// }


// ⏲️ Approach-3 (Using maths)
// ⏲️ Time Complexity : O(1)
// 🛢️ Space Complexity : O(1)

int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles-1) / (numExchange-1);
}

int main()
{
    int numBottles = 9;
    int numExchange = 3;
    int ans = numWaterBottles(numBottles,numExchange);
    cout << "ans is : " << ans << endl;
    return 0;
}
