#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Adobe ✯   Apple ✯   Coursera ✯  

// // ▶️ Approach-1 (Recursion + Memoization)
// // ⏲️ Time Complexity : Without Memoization - O(3^n) and with Memoization - o(n)
// // 🛢️ space Complexity : O(n) (But size of t is 38 which is constant hence O(1))

// int t[38];
//     int find(const int& n) {
//         if(n == 0)           return 0;
//         if(n == 1 || n == 2) return 1;
//         if(t[n] != -1)       return t[n];
        
//         int a = find(n-1);
//         int b = find(n-2);
//         int c = find(n-3);
            
        
//         return t[n] = a+b+c;
//     }
//     int tribonacci(int n) {
//         memset(t, -1, sizeof(t));
        
//         return find(n);
//     }


// // ▶️ Approach-2 (Using Bottom Up DP)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)  (But size of t is 38 which is constant hence O(1))

// int tribonacci(int n) {
//     int t[38];
//     t[0] = 0;
//     t[1] = 1;
//     t[2] = 1; 
//     for (int i = 3; i <= 37; i++) {
//         t[i] = t[i-1] + t[i - 2] + t[i - 3];
//     }   
//     return t[n];
// }


// ▶️ APproach-3 (Using constant space)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int tribonacci(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
        
    int a = 0;
    int b = 1;
    int c = 1;
    int d;
 
    for(int i = 3; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}

int main()
{
    int n = 4;
    int ans = tribonacci(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
