#include<iostream>
#include<vector>
using namespace std;


// ▶️ Ask by : Amazon | Microsoft | Goldman | SachsDirecti

 bool canPair(vector<int> nums, int k) {
    int n = nums.size();
    if(n % 2) return false;
    vector<int> mp(k + 1, 0); 
    for(auto x : nums){
        x %= k;
        mp[x]++;
        mp[k-x]--;
    } 
    for(int i = 1; i < k; i++) if(mp[i]>0) return false;
    return true;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity : O(n)

int main()
{
    vector<int> nums = {9, 5, 7, 3};
    int k = 6;
    bool ans = canPair(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
