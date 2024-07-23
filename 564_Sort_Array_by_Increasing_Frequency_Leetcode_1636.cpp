#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Oracle ✯   Twilio ✯   Google ✯   C3 IoT ✯  

bool mycomp(pair<int,int> a, pair<int,int> b) {
    if(a.second < b.second) {
        return true;
    }
    else if(a.second > b.second) {
        return false;
    }
    else {
        return a.first >= b.first;
    }
}

vector<int> frequencySort(vector<int>& nums) {
    int n = nums.size();
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    vector<pair<int,int>> vp;
    for(auto it: mp) {
        vp.push_back({it.first,it.second});
    }
    sort(vp.begin(),vp.end(),mycomp);
    vector<int> ans;
    for(auto it: vp) {
        int x = it.first;
        int f = it.second;
        while(f--) {
            ans.push_back(x);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2,2,2,3};
    vector<int>ans = frequencySort(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
