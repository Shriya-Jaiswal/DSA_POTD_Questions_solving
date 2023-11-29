#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Apple ✯   Box ✯   Facebook ✯   Cisco ✯   Amazon ✯   Google   Oracle  , Microsoft

// ◀️ Leetcode Easy level ---> bit manipulation

// // ➡️ Approach-1 (Using simple right shift operator)
// // ⏲️ Time Complexity : O(1) - because the loop in the code iterates 32 times, which is a constant number regardless of the input n
// // 🛢️ Space Complexity : O(1)

// int hammingWeight(uint32_t n) {
//     int count = 0;
//     for(int i = 31; i>=0; i--) {
//         if(((n >> i) & 1) == 1) {
//             count++;
//         }
//     }    
//     return count;
// }

// // ➡️ Approach-2 (Using simple bit magic)
// // ⏲️ Time Complexity : O(k) -> Where k = number of set bits (1s) in input 'n'
// // 🛢️ Space Complexity : O(1)

//  int hammingWeight(uint32_t n) { // 👉 uint32_t is a unsigned int 32 
//     int count = 0;
//     while(n) {
//         n = (n&(n-1)); // 👉 This expression is used to turn off the rightmost set bit in n. This operation effectively removes one set bit in each iteration.
//         count++;
//     }
//     return count;
// }

// // ▶️ Approach-3 (Using simple bit magic)
// // ⏲️ Time Complexity : O(log(n)) -> In each iteration, n is divided by 2 (n /= 2)
// // 🛢️ Space Complexity : O(1)

// int hammingWeight(uint32_t n) {
//     int count = 0;  
//     while(n) {
//         count += (n%2);
//         n /= 2;
//     }   
//     return count;
// }


// ▶️ Approach-4 (using GCC built-in function)
// ⏲️ Time Complexity : O(k) -> Where k = number of set bits (1s) in input 'n'
// 🛢️ Space Complexity : O(1)

int hammingWeight(uint32_t n) {
    return __builtin_popcount(n);
}


int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int ans = hammingWeight(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
