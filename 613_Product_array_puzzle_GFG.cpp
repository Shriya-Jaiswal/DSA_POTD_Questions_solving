#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | D-E-Shaw | Intuit | Opera

vector<long long int> productExceptSelf(vector<long long int>& nums) {

    // code here
    long long int temp = 1, c = 0, index = -1, n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i])temp*=nums[i];
        else{
            c++;
            index=i;
        }
    }
    vector<long long int> ans(n,0);
    if(c>1)return ans;
    if(c==1){
        ans[index]=temp;
        return ans;
    }
    for(int i=0;i<n;i++){
        ans[i]=temp/nums[i];
    }
    return ans;
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    vector<long long int> nums = {10, 3, 5, 6, 2};
    vector<long long int> ans = productExceptSelf(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
