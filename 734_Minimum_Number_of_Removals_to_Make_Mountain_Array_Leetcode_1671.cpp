#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

class Solution {

 vector<int> LIS(vector<int>nums)
    {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>helper;
        helper.push_back(nums[0]);
        int ind=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>helper[ind]) {
                ind++;
                helper.push_back(nums[i]);
            }
            else {
                putproper(nums[i],helper,ind);
            }
            dp[i]=ind+1;
        }
        return dp;
    }
    void putproper(int val,vector<int>&arr,int lastind) //binary search to put element at correct position
    {
        int start=0;
        int end=lastind;
        int mid;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==val)
                return ;
            else if(arr[mid]>val)
                end=mid;
            else
                start=mid+1;
        }
        arr[start]=val;
        
    }
    
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int>inc=LIS(arr);
        reverse(arr.begin(),arr.end());
        vector<int>dec=LIS(arr);
        reverse(dec.begin(),dec.end());
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(inc[i]>1 and dec[i]>1)
                ans=min(ans,n-inc[i]-dec[i]+1);
        }
        return ans;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,1};
    int ans = s.minimumMountainRemovals(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
