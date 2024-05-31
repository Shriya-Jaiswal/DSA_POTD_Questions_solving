#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Google ✯  

// ▶️ Approach (Optimal)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

vector<int> singleNumber(vector<int>& nums) {
    long long xor_r = 0;

    for(int &num : nums) {
        xor_r ^= num;
    }

    //mask -> right most set bit search 
    int mask = (xor_r) & (-xor_r);
    /*
        It works because if you take the two's complement negation of a number, first you complement it,
        setting all zeroes to the right of the lowest set bit to one and the lowest set bit to zero,
        then you add one, setting the bits on the right to zero and the lowest set bit becomes one again, ending the carry chain.
    */

    int groupa = 0;
    int groupb = 0;

    for(int &num : nums) {
        if(num & mask) {
            groupa ^= num;
        } else {
            groupb ^= num;
        }
    }

    return {groupa, groupb};
}

int main()
{
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = singleNumber(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
