#include<iostream>
#include<vector>
using namespace std;

// // ▶️  Adobe ✯  

// // ▶️ Approach-1 (Using shift)
// // ⏲️ Time Complexity : O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
// // 🛢️ Space Complexity : O(1)

// int rangeBitwiseAnd(int left, int right) {
//     int shiftCount = 0;     
//     while(left != right) {
//         left >>= 1;
//         right >>= 1;
//         shiftCount++;
//     }    
//     return left << shiftCount;
// }


// ▶️ Approach-2 (Using AND property)
// ⏲️ Time Complexity : O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
// 🛢️ Space Complexity : O(1)

int rangeBitwiseAnd(int left, int right) {
    while(right > left) {
        right = right & (right-1);
    }   
    return right;
}

int main()
{
    int left = 5;
    int right = 7;
    int ans = rangeBitwiseAnd(left,right);
    cout << "ans is : " << ans << endl;
    return 0;
}
