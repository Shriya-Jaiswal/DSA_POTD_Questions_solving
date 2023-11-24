#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ➡️ Approach-1 (Using Greedy + 3 pointers)
// // ⏲️ Time Complexity : O(nlogn) - Sorting
// // 🛢️ Space Complexity : O(1)
// // ➡️ NOTE - we could also use q deque to push and pop from either side

// int maxCoins(vector<int>& piles) {
//     int n = piles.size(); 
//     sort(begin(piles), end(piles));    
//     int result = 0;
//     int Bob = 0, Me = n-2, Alice = n-1;
//     while(Me > Bob) { 
//         result += piles[Me];
//         Me    -= 2;    
//         Bob   += 1;
//         Alice -= 2; // 👉 (we can remove this becasue it's required. I Used it for the sake of completeness)
//     }    
//     return result;        
// }

// // ➡️ Approach-2 (Using Greedy without 3 pointers)
// // ⏲️ Time Complexity : O(nlogn) - Sorting
// // 🛢️ Space Complexity : O(1)

int maxCoins(vector<int>& piles) {
    int n = piles.size();
    sort(begin(piles), end(piles));
    int result = 0;
    for(int i = n/3; i <n; i+=2) {
        result += piles[i];
    }        
    return result;
}

int main()
{
    vector<int> piles = {2,4,1,2,7,8};
    int ans = maxCoins(piles);
    cout << "ans is : " << ans;
    
    return 0;
}
