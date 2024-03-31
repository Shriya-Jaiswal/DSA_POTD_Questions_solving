#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Google ✯  Microsoft

// ▶️ Approach-1 (Brute Force)
// Find all subarrays and check if min is minK and max is maxK

// ▶️ Approach-2 (Optimal O(n)) - Sliding Window

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;       
    int minPosition = -1;
    int maxPosition = -1;
    int leftBound   = -1;    
    for(int i = 0; i < nums.size(); i++) {   
        if(nums[i] < minK || nums[i] > maxK)
            leftBound = i;
            
        if(nums[i] == minK)
            minPosition = i;
        if(nums[i] == maxK)
            maxPosition = i;

        int count = min(maxPosition, minPosition) - leftBound;    
        ans += (count <= 0) ? 0 : count;      
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1;
    int maxK = 5;

    long long ans = countSubarrays(nums,minK,maxK);
    cout << "ans is : " << ans << endl;
    return 0;
}
