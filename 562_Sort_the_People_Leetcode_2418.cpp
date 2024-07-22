#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Apple ✯   Adobe ✯   Infosys ✯  

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<string> result;
    map<int,string> mp;        
    for(int i=0; i< names.size(); i++){
        mp[heights[i]] = names[i];
    }  

    for(const auto & i : mp){
        result.push_back(i.second);
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> ans = sortPeople(names,heights);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
