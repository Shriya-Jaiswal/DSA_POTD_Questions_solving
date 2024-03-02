#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ▶️ Ask by  :  Facebook ✯   Amazon ✯   Google ✯   Microsoft ✯   Paypal ✯  

// // ▶️ Approach-1
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)


//  vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i = 0; i < n; i++) {
//             nums[i] = nums[i]*nums[i];
//         }
        
//         sort(begin(nums), end(nums)); //O(nlogn)
//         return nums;
//     }


// ▶️ Approach-2 (Follow Up, without sorting nlogn)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) - (Not considering the space takent to store the result)


vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
        
    vector<int> result(n);
        
    int i = 0, j = n-1;
    int k = n-1;
        
    while(k >= 0) {
        int a = nums[i]*nums[i];
        int b = nums[j]*nums[j];
            
        if(a > b) {
            result[k] = a;
            i++;
        } else {
            result[k] = b;
            j--;
        }
        k--;
    }
    return result;
}


int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans =sortedSquares(nums);
    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
