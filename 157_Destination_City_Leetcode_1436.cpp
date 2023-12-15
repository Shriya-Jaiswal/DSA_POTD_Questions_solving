#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : Yelp 5 | Google 2


// ▶️ Approach-1 (Using HashMap) - Count Outdegrees
// ⏲️ Timw Complexity : O(n)
// 🛢️ Space Complexity : O(n)


string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> mp;
        
    for(auto &path : paths) {
        string source = path[0]; //outdegree
        mp[source]++;
    }
        
    for(auto &path : paths) {
        string dest = path[1];
            
        if(mp[dest] == 0) {
            return dest;
        }
    }
        
    return "";
}


int main()
{
    vector<vector<string>>  paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string ans = destCity(paths);
    cout << "ans is : " << ans << endl;
    return 0;
}
