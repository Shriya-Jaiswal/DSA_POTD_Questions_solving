#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

// // ▶️ Approach-1 - Simulation (TLE)
// // ⏲️ Time Complexity : O(k/sum * n)
// // 🛢️ Space Complexity : O(1)

// int chalkReplacer(vector<int>& chalk, int k) {
//     while(true) {
//         for(int i = 0; i < chalk.size(); i++) {
//             if(k < chalk[i]) {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// ▶️ Approach-2 (Making use of remainder)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long long totalChalkSum = 0; // 👉 Total chalks required in one iteration
    for(int &chalkReq : chalk) { // 👉 O(n)
        totalChalkSum += chalkReq;
    }
    // 👉 Number of full iteration possible = k/totalChalkSum
    int remainChalk = k%totalChalkSum;
    for(int i = 0; i < n; i++) { // 👉 O(n)
        if(remainChalk < chalk[i]) {
            return i;
        }
        remainChalk -= chalk[i];
    }
    return -1;
}

int main()
{
    vector<int> chalk = {5,1,5};
    int k = 22;
    int ans = chalkReplacer(chalk,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
