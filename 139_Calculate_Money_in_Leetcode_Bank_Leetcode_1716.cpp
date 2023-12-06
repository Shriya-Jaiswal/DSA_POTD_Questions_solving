#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : edabit 1  | ----> Easy Level


// ➡️ Approach-1 (Just doing what Qn asks - simulation)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int totalMoney(int n) {
    int result = 0;
    int monday_money = 1;
    while(n > 0) {
        int money = monday_money;
        for(int day = 1; day <= min(n, 7); day++) {
            result += money++;
        }   
        n -= 7;
        monday_money += 1;
    }
    return result;
}

// // ➡️ Approach-2 (Using Maths)
// // ⏲️ Time Complexity : O(1)
// // 🛢️ Space Complexity : O(1)


//  int totalMoney(int n) {
//     int items  = n / 7;
//     int first  = 28;
//     int last   = 28 + (items - 1) * 7; // 👉 Tn = a1 + (n-1)*d
//     int arithmeticSum = items * (first + last) / 2; // 👉 Sn = n/2(a1 + an)
//     // 👉 Final week remaining days
//     int monday_money = 1 + items;
//     int finalWeek    = 0;   
//     for (int day = 1; day <= (n % 7); day++) { // 👉 This loop will Never iterate more than 6 ~ O(1)
//         finalWeek += monday_money++;
//     }  
//     return arithmeticSum + finalWeek;
// }


int main()
{
    int n = 4;
    int ans = totalMoney(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
