#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  ByteDance ✯   Hulu ✯  

// // ▶️ Approach-1 (Simple Recursion - DFS) - MEMORY LIMIT EXCEEDE (MLE)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(d) of system stack and O(n) for storing numbers in result array

// void solve(int curr, int n, vector<int>& result) {
//     if(curr > n)
//         return;
        
//     result.push_back(curr);

//     for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
//         int nextnum = curr*10 + nextDigit;
            
//         if(nextnum > n)
//             return;
            
//         solve(nextnum, n, result);
//     }
// }

// int findKthNumber(int n, int k) {
//     vector<int> result;
//     for(int num = 1; num <= 9; num++)
//         solve(num, n, result);
        
//     return result[k-1];
// }


// // ▶️ Approach-2 (Simple Recursion - DFS without storing in result) - TIME LIMIT EXCEEDE (TLE)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(d) of system stack

// int count = 0;
// int result = 0;

// bool solve(long long curr, int n, int k) {
//     if (curr > n)
//         return false;
        
//     count++;
        
//     if (count == k) {
//         result = curr;
//         return true;
//     }
        
//     for (int nextDigit = 0; nextDigit <= 9; nextDigit++) {
//         long long nextnum = curr * 10 + nextDigit;
//         if (nextnum > n)
//             break;
            
//         if (solve(nextnum, n, k)) {
//             return true;
//         }
//     }
        
//     return false;
// }

// int findKthNumber(int n, int k) {
//     for (long long num = 1; num <= 9; num++) {
//         if (solve(num, n, k)) {
//             break;
//         }
//     }
//     return result;
// }


// ▶️ Approach-3 (Optimal) - ACCEPTED
// ⏲️ Time Complexity : O((logn)^2)
// 🛢️ Space Complexity : O(log(n)) system resursion stack

int Count(long curr, long next, int n) {
    int countNum = 0;
    while(curr <= n) {
        countNum += (next - curr);
        curr *= 10;
        next *= 10;

        next = min(next, long(n+1));
    }
    return countNum;
}

int findKthNumber(int n, int k) {
    int curr = 1;
    k -= 1; // 👉 Since we start from the first number (1), we need k-1 more numbers
    while(k > 0) {
        int count = Count(curr, curr+1, n);
        if(count  <= k) {
            curr++;
            k -= count; // 👉 skipping the elements under curr prefix tree
        } else {
            curr *= 10;
            k -= 1;
        }
    }
    return curr;
}


int main()
{
    int  n = 13;
    int k = 2;
    int ans = findKthNumber(n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
