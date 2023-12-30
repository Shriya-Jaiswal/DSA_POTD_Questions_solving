#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include <cstring>
using namespace std;

// ➡️ Ask by :  Amazon ✯   Tiktok ✯   Uber ✯   SAP Labs ✯   Swiggy ✯  

// // ➡️ Approach - 1 (Recursion + Memoization)
// // ⏲️ T.C : O(n^2*d)
// // 🛢️ S.C : O(301*11) ~= O(1)

// int t[301][11];
//     int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        
//         // If you have only 1 day, then you will do all the remaining jobs
//         // and select the max difficulty as the answer
//         if (d == 1) {
//             return *max_element(begin(jobDifficulty) + idx, end(jobDifficulty));
//         }
        
//         if (t[idx][d] != -1)
//             return t[idx][d];
    
//         int Max = INT_MIN;
//         int result = INT_MAX;
        
//         // Try one by one with all possibilities
//         /*
//             Take 1 job in one day
//             Take 2 jobs in one day
//             Take 3 jobs in one day
//             and so on
            
//             Then find the optimal one among all the results
//         */
//         for (int i = idx; i <= n - d; i++) {
//             Max = max(Max, jobDifficulty[i]);
//             result = min(result, Max + solve(jobDifficulty, n, i + 1, d - 1));
//         }
        
//         return t[idx][d] = result;
//     }

//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();
        
//         if (n < d)
//             return -1;

//         memset(t, -1, sizeof(t));
        
//         return solve(jobDifficulty, n, 0, d);
//     }


// ➡️ Approach - 2 (Bottom UP)
// ⏲️ T.C : O(n^2 * d)
// 🛢️ S.C : O(n*d)


    int minDifficulty(vector<int>& jobDifficulty, int d) {
         int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> t(n+1, vector<int>(d+1, -1));
        //t[i][j] = minimum diffculty of doing job from index i to n-1 in j days.

        // Base case: if there is only one day - Do all jobs on that day
        for (int i = 0; i < n; i++) {
            t[i][1] = *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        // Build the DP table bottom-up
        for (int days = 2; days <= d; days++) {
            for (int i = 0; i <= n - days; i++) {
                int maxDifficulty = INT_MIN;
                int result        = INT_MAX;

                for (int j = i; j <= n - days; j++) {
                    maxDifficulty   = max(maxDifficulty, jobDifficulty[j]);
                    result          = min(result, maxDifficulty + t[j + 1][days - 1]);
                }

                t[i][days] = result;
            }
        }

        return t[0][d];
    }

int main()
{
    vector<int> jobDifficulty {6,5,4,3,2,1};
    int d = 2;
    int ans = minDifficulty(jobDifficulty,d);
    cout << "ans is : " << ans << endl;
    return 0;
}
