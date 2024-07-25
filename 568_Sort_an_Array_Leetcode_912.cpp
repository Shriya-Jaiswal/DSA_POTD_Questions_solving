#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Bloomberg ✯  Microsoft, Goldman Sachs, Cisco

// 👉 solving using Counting Sort (O(n+k))

vector<int> sortArray(vector<int>& nums) {
    int minE = *min_element(begin(nums), end(nums));
    int maxE = *max_element(begin(nums), end(nums));
    unordered_map<int, int> mp;
    for(int &num : nums)
        mp[num]++;
        
    int i = 0;
    for(int num = minE; num <= maxE; num++) {
        while(mp[num] > 0) {
            nums[i] = num;
            i++;
            mp[num]--;
        }       
    }   
    return nums;
}

int main()
{
    vector<int>  nums = {5,2,3,1};
    vector<int> ans = sortArray(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
