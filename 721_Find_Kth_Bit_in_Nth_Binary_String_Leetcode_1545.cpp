#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Rupeek ✯  

// ▶️ Approach - Recursion
// ⏲️ Time Complexity : O(log(k))
// 🛢️ Space Complexity : O(log(k))) of system stack

char findKthBit(int n, int k) {
    if (n == 1) {
        return '0';
    }
        
    // Calculate the middle position of Sn
    int mid = (1 << (n - 1));  // 2^(n-1), which is the middle position
        
    if (k == mid) {
        return '1';  // The middle bit is always "1"
    } else if (k < mid) {
        // If k is in the left half, it's part of Sn-1
        return findKthBit(n - 1, k);
    } else {
        // If k is in the right half, find the corresponding bit in Sn-1
        // In the reverse(invert) part, we map it to the corresponding position in Sn-1
        int mirroredK = 2 * mid - k;
        char mirroredBit = findKthBit(n - 1, mirroredK);
            
        // Invert the bit
        return mirroredBit == '0' ? '1' : '0';
    }
}


int main()
{
    int n = 3;
    int k = 1;
    char ans = findKthBit(n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
