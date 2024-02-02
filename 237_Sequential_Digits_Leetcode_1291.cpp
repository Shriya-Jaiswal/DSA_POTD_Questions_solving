#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Apple ✯  

// // ▶️ Approach-1 (Using simple BFS)
// // ⏲️ Time Complexity : O(N), where N is the number of valid sequential digits in the specified range.
// // 🛢️ Space Complexity : O(N), where N is the number of valid sequential digits in the specified range. (queue size)

// vector<int> sequentialDigits(int low, int high) {
//     queue<int> que;
//     for(int i = 1; i <= 8; i++) {
//         que.push(i);
//     }
//     vector<int> result;     
//     while(!que.empty()) {
//         int temp = que.front();
//         que.pop();    
//         if(temp >= low && temp <= high) {
//             result.push_back(temp);
//         }   
//         int last_digit = temp%10;
//         if(last_digit + 1 <= 9) {
//             que.push(temp * 10 +(last_digit + 1));
//         }
//     }
//     return result;
// }


// ➡️ Approach-2 (Using workaround)
// ⏲️ Time Complexity : O(1)
// 🛢️ Space Complexity : O(1)


vector<int> sequentialDigits(int low, int high) {
    vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456, 567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789};
        
    vector<int> result;
        
    int n = allPossible.size();
        
    for (int i = 0; i < n; i++) {
        if (allPossible[i] < low) continue;
            
        if (allPossible[i] > high) break;
            
        result.push_back(allPossible[i]);
    }
    return result;
}

int main()
{
    int low = 100;
    int high = 300;
    vector<int> ans = sequentialDigits(low,high);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }
    cout << endl;
    return 0;
}
