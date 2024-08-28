#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Oracle | Zycus

static bool func(pair<int,int> &a,pair<int,int> &b){
    if(a.second>b.second)return true;
    else if(a.second<b.second)return false;
    else return a.first<b.first;
}
// 👉 Complete this function
// 👉 Function to sort the array according to frequency of elements.
vector<int> sortByFreq(vector<int>& arr) {
    unordered_map<int,int> mm;
    vector<pair<int,int>> vec;
    vector<int> ans;
    for(auto x:arr)mm[x]++;
    for(auto x:arr)vec.push_back({x,mm[x]});
    sort(vec.begin(),vec.end(),func);
    for(auto x:vec)ans.push_back(x.first);
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*logn)
// 🛢️ Expected Space Complexity: O(n)

int main()
{
    vector<int>  arr = {5, 5, 4, 6, 4};
    vector<int> ans = sortByFreq(arr);
    for(int i = 0 ; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
