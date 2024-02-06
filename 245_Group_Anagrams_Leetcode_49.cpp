#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Microsoft ✯   Facebook ✯   Apple ✯   JPMorgan ✯   BlackRock   Google   Walmart Global Tech   eBay   Adobe   Affirm   Oracle   Uber   Salesforce   Twilio   Visa   ServiceNow   Yahoo   Goldman Sachs   VMware   Alation   IBM   Cisco   tiktok  

// // ▶️ Approach-1 (Using Sorting)
// // ⏲️ Time Complexity : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
// // 🛢️ Space Complexity : O(n*k)

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     unordered_map<string, vector<string>> mp;   
//     for(auto str:strs) {
//         string temp = str;
//         sort(temp.begin(), temp.end());
//         mp[temp].push_back(str);
//     }      
//     vector<vector<string>> result;
//     for(auto it : mp) {
//         result.push_back(it.second);
//     } 
//     return result;
// }



// ➡️ Approach-2
// ⏲️ Time Complexity : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
// 🛢️ Space Complexity : O(n*k)

string generate(string &s) {
    int count[26] = {0};
    for(char &ch : s) {
        count[ch-'a']++;
    }
    string new_s;
    for(int i = 0; i<26; i++) {       
        if(count[i] > 0) {
            new_s += string(count[i], i+'a');
        }
    }
    return new_s;
}
    
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
        
    for(string &s : strs) {
        string new_s = generate(s);
            
        mp[new_s].push_back(s);
    }   
    vector<vector<string>> result;
    for(auto &it : mp) {
        result.push_back(std::move(it.second));
    }
    return result;     
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(int i =0 ; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
