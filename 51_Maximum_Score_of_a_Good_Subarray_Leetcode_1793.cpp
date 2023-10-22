#include<iostream>
#include<vector>
using namespace std;

int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();

    int i = k;
    int j = k;
    int currMin = nums[k];
    int result = nums[k];

    while(i > 0 || j < n-1){
        int leftValue =(i>0) ? nums[i-1] : 0;
        int rightValue = (j< n-1) ? nums[j+1] : 0;

        if(leftValue < rightValue){
            j++;
            currMin = min(currMin, nums[j]);
        }
        else{
            // 👉 move in left side
            i--;
            currMin= min(currMin, nums[i]);
        }

        result = max(result, currMin*(j-i+1));
    }        
    return result;
}

int main()
{
    vector<int> nums {1,4,3,7,4,5};
    int k = 3;
    int ans = maximumScore(nums,k);
    cout<< "ans is : " << ans << endl;
    return 0;
}
