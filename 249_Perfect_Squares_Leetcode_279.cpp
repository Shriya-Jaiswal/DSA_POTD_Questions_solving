#include<iostream>
#include<vector>
#include<limits.h>
#include<cstring>
using namespace std;

// // ▶️ Ask by :  Apple ✯   Amazon ✯   Google ✯   Microsoft ✯  

// // ➡️ Approach-1 (Recusrion + Memoization) - Using concept of "Minimum Coins" concept
// // ⏲️ Time Complexity : O(n*S) - Where n = total coins possible and S = target sum
// // 🛢️ Space Complexity : O(n*S)

// int minCoinsToGetS(vector<int>& coins, int n, int S, vector<vector<int>>& t) {
//     if(t[n][S] != -1)
//         return t[n][S];
        
//     if(n == 0)
//         return INT_MAX-1;
//     if(S == 0)
//             return 0;
//     if(n == 1) {
//         if(S % coins[0] == 0)
//             return t[n][S] = S/coins[0];
//          else
//             return t[n][S] = INT_MAX-1;
//     }
        
//     if(coins[n-1] <= S) {
//         return t[n][S] = min(1 + minCoinsToGetS(coins, n, S-coins[n-1], t), minCoinsToGetS(coins, n-1, S, t));
//     } else
//         return t[n][S] = minCoinsToGetS(coins, n-1, S, t);
// }
// int numSquares(int S) {
//     vector<int> coins;
//     for(int i = 1; i*i<=S; i++) {
//         coins.push_back(i*i);
//     }
//     int n = coins.size();
        
//     vector<vector<int>> t(n+1, vector<int>(S+1, -1));
//     return minCoinsToGetS(coins, n, S, t);
// }



// // ▶️ Approach-2 (Bottom Up DP) - Using concept of "Minimum Coins" concept
// // ⏲️ Time Complexity : O(n*S) - Where n = total coins possible and S = target sum
// // 🛢️ Space Complexity : O(n*S)

// int minSquares(vector<int> squares, int n, int S) {        
//     vector<vector<int>> t(n+1, vector<int>(S+1));
//     for(int j = 0; j<S+1; j++) {
//         t[0][j] = INT_MAX-1;
//     }
        
//     for(int i = 1; i<n+1; i++) {
//         t[i][0] = 0;
//     }
        
//     for(int j = 1; j<S+1; j++) {
//         if(j % squares[0] == 0)
//             t[1][j] = j/squares[0];
//         else
//             t[1][j] = INT_MAX-1;
//     }
        
//     for(int i = 2; i<n+1; i++) {
//         for(int j = 1; j<S+1; j++) {
//             if(squares[i-1] <= j)
//                 t[i][j] = min(1+t[i][j-squares[i-1]], t[i-1][j]);
//             else
//                 t[i][j] = t[i-1][j];
//         }
//     }
//     return t[n][S];
// }
// int numSquares(int S) {
//     if(S == 0 || S == 1)
//         return S;
//     vector<int> squares;
//     for(int i = 1; i*i<=S; i++) {
//         squares.push_back(i*i);
//     }
//     int n = squares.size();
//     return minSquares(squares, n, S);
// }


// // ▶️ Approach-3 (Recursion with Memoizatin without Coin Change concept)
// // ⏲️ Time Complexity : O(n * sqrt(n))
// // 🛢️ Space Complexity : O(n)

// int t[10001];
    
// int minSquares(int n) {
//     if(n == 0)
//         return 0;
        
//     if(t[n] != -1)
//         return t[n];
        
//     //we can select only those perfect squares which can contribute to sum up to n
//     int minCount = INT_MAX;
//     for(int i = 1; i*i<=n; i++) {
//         minCount = min(minCount, 1 + minSquares(n-i*i)); //1 is for selectcing one quare number
//     }
        
//     return t[n] = minCount;
// }
    
// int numSquares(int n) {
//     memset(t, -1, sizeof(t));  
//     return minSquares(n);
// }


// ▶️ Approach-4 (Bottom UP DP : O(n) space)

int numSquares(int n) {
    vector<int> t(n+1, INT_MAX);
    //t[i] = min number of perfect squares to get i
    t[0] = 0;
        
    for(int i = 1; i<=n; i++) {
            
        // For each i, it must be the sum of some number (i - j*j) and 
        // a perfect square number (j*j).
        for(int j = 1; j*j<=i; j++) {
            int remain = i-j*j;
                
            t[i] = min(t[i], 1 + t[remain]);
        }
    }
        
    return t[n];
}

int main()
{
    int n = 12;
    int ans =numSquares(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
