#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// ▶️ Ask by : 

// // ▶️ Approach-1 (Using sorting)
// // ⏲️ Time Complexity : O(nlogn) 
// // 🛢️ Space Complexity : O(1)

// int maxProductDifference(vector<int>& nums) {
//     int n = nums.size();
//     sort(begin(nums), end(nums));
        
//     return (nums[n-1] * nums[n-2]) - (nums[1] * nums[0]);
// }


// ▶️ Approach-2 (Without sorting)
// ⏲️ Time Complexity : O(n) 
// 🛢️ Space Complexity : O(1)

int maxProductDifference(vector<int>& nums) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for(int &num : nums) {
        if(num > largest) {
            secondLargest = largest;
            largest = num;
        } else {
            secondLargest = max(secondLargest, num);
        }   
        if(num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else {
            secondSmallest = min(secondSmallest, num);
        }       
    }
    return (largest * secondLargest) - (secondSmallest * smallest);        
}


int main()
{
    vector<int> nums = {5,6,2,7,4};
    int ans = maxProductDifference(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
