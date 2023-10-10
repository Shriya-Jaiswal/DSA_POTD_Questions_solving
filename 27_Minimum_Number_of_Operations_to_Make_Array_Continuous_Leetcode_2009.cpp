#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<limits.h>
#include<algorithm>
using namespace std;

// int minOperations(vector<int>& nums) {
//     int n = nums.size();
//     // 👉 sort        
//     // 👉 unique element

//     set<int> st(begin(nums), end(nums));
//     vector<int> temp(begin(st),end(st));

//     int result = INT_MAX;

//     for(int i = 0; i < temp.size(); i++){
//         int L = temp[i];
//         int R = L + n - 1 ;
//         // 👉 R-L = n-1

//         // int operations = 0;
//         // unordered_set<int> used;

//         // for(int j = 0; j <n; j++){
//         //     if(nums[j] >= L && nums[j] <= R && used.find(nums[j]) == used.end()){
//         //         used.insert(nums[j]);
//         //         continue;
//         //     }
//         //     else{
//         //         operations++;
//         //     }
//         // }

//         // result = min(result,operations);


//         int j = upper_bound(begin(temp),end(temp),R) = begin(temp);

//         int withIn_range = j-i;
//         int out_of_range = n - withIn_range;

//         result = min(result, out_of_range);
//     }
//     return result;
// }


// ✅
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ans = n;
    set<int> s;
    for(int i : nums){
        s.insert(i);
    }
    vector<int> unique_element(s.begin(), s.end());
    int size = unique_element.size();
    for(int start =0 ; start < size; start ++){
        int end_index = upper_bound(unique_element.begin() + start, unique_element.end(), unique_element[start] + n-1) - unique_element.begin();
        ans = min(ans, n - (end_index - start));
    }
    return ans;
} 

int main()
{
    vector<int> nums {4,2,5,3};
    int ans = minOperations(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
