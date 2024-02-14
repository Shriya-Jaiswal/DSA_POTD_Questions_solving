#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) for result


vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int pi = 0; //positive index
    int ni = 1; //negative index
    vector<int> result(n);   
    for(int &num : nums) {
        if(num > 0) {
            result[pi] = num;
            pi +=2;
        } else {
            result[ni] = num;
            ni += 2;
        }
    }   
    return result;   
}

int main()
{
    vector<int>  nums = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeArray(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
