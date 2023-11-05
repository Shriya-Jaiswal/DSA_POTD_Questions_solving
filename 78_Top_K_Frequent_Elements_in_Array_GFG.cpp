#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

static bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second > b.second){
        return true;
    }
    if(a.second == b.second){
        return a.first > b.first;
    }
    return false;
}

vector<int> topK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(auto i : nums){
        mp[i]++;
    }
    vector<pair<int,int> > freq;
    for(auto it : mp){
        freq.push_back({it.first, it.second});
    }

    sort(freq.begin(), freq.end(),comp);

    vector<int> ans;
    for(int i=0; i<k; i++){
        ans.push_back(freq[i].first);
    }
    return ans;
}

int main()
{
    vector<int> nums {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topK(nums,k);
    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << " "; 
    }
    cout << endl;
    return 0;
}
