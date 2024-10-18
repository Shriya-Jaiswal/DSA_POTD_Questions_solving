#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

// // ▶️ Approach-1 (Using simple recursion to find subsets)
// // ⏲️ Time Complexity : O(2^n)
// // 🛢️ Space Complexity : O(1)

// int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr) {
//     if(idx == nums.size()) {
//         if(currOr == maxOr)
//             return 1; //Found one subset
//         return 0;
//     }

//     //Take nums[idx]
//     int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

//     //Not taken nums[idx]
//     int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);

//     return takeCount + notTakeCount;
// }

// int countMaxOrSubsets(vector<int>& nums) {
//     int maxOr = 0;
//     for(int &num : nums) {
//         maxOr |= num;
//     }

//     int currOr = 0;
//     return countSubsets(0, currOr, nums, maxOr);
// }


// ▶️ Approach-2 (Memoizing to store subproblems result)
// ⏲️ Time Complexity : O(n*maxOr)
// 🛢️ Space Complexity : O(1)

int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& t) {
    if(idx == nums.size()) {
        if(currOr == maxOr)
            return t[idx][currOr] = 1; //Found one subset
        return t[idx][currOr] = 0;
    }

    if(t[idx][currOr] != -1) {
        return t[idx][currOr];
    }

    //Take nums[idx]
    int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr, t);

    //Not taken nums[idx]
    int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr, t);


    return t[idx][currOr] = takeCount + notTakeCount;

}

int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;
    for(int &num : nums) {
        maxOr |= num;
    }
    int n = nums.size();

    vector<vector<int>> t(n+1, vector<int>(maxOr+1, -1));
    int currOr = 0;
    return countSubsets(0, currOr, nums, maxOr, t);
}



int main()
{
    vector<int>  nums = {3,1};
    int ans = countMaxOrSubsets(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
