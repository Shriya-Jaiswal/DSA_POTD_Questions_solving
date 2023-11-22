#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Google ✯  

// // ➡️ Approach-1 (Using map)
// // ⏲️ Time Complexity : O(n) where n = all elements in grid
// // 🛢️ Space Complexity : O(n) We took map to store all elements

// vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//     unordered_map<int, vector<int>> mp;
//     for(int row = nums.size()-1; row >= 0; row--) {
//         for(int col = 0; col < nums[row].size(); col++) { 
//             mp[row+col].push_back(nums[row][col]);       
//         }
//     }
//     vector<int> result;
//     int diagonal = 0;
//     while(mp.find(diagonal) != mp.end()) {  
//         for(int &num : mp[diagonal]) {
//             result.push_back(num);
//         }
//         diagonal++;
//     }
//     return result;
// }

// ➡️ Approach-2 (Usign BFS)
// ⏲️ Time Complexity : O(n) visiting all elements
// 🛢️ Space Compplexity : O(sqrt(n)) -> See my youtube video above for explanation

 vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    queue<pair<int, int>> que;
    que.push({0, 0});
    vector<int> result;
    while (!que.empty()) {
        auto [row, col] = que.front();
        que.pop();
        result.push_back(nums[row][col]);
        if (col == 0 && row + 1 < nums.size()) {
            que.push({row + 1, col});
        }  
        if (col + 1 < nums[row].size()) {
            que.push({row, col + 1});
        }
    }    
    return result;
}

int main()
{
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(nums);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}
