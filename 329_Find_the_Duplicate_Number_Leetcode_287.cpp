#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Paytm ✯   Zoho ✯   Flipkart ✯   DE-Shaw ✯   Adobe   Bloomberg   Cisco   eBay   Expedia   Goldman Sachs   Nutanix   PayPal   Splunk   Uber   VMware   Yahoo   Capgemini   TCS   BNY Mellon   OLA   Housing.com   PegaSystems   Unthinkable Solution   Microsoft   HashedIn   Virtusa   Facebook   Uber   Apple   Google   Qualcomm  

// ⏲️ Time Complexity : O(n) Using "Hare & tortoise technique"
// 🛢️ Space Complexity : O(1)

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
        
    slow = nums[slow];
    fast = nums[nums[fast]];
        
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
        
    slow = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
        
    return slow;
}

int main()
{
    vector<int>  nums = {1,3,4,2,2};
    int ans = findDuplicate(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
