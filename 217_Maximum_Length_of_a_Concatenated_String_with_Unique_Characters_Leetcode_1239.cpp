#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ⏲️ Time Complexity : O(n*2^n)
// 🛢️ Space Complexity : O(n)
// ➡️ Approach-1 Using DP (Recur + Memo)

bool hasCommon(string &s1, string& s2) {
    int arr[26] = {0};  
    for(char &ch : s1) {
        if(arr[ch-'a'] > 0)
            return true;
        arr[ch-'a']++;
    }  
    for(char &ch : s2) {
        if(arr[ch-'a'] > 0)
            return true;
    }    
    return false;
}
    
unordered_map<string, int> mp;
    
int solve(int idx, vector<string>& arr, string temp, int n) {
    if(idx >= n)
        return temp.length();
    if(mp.find(temp) != mp.end())
        return mp[temp];  
    int include = 0;
    int exclude = 0;
    if(hasCommon(arr[idx], temp)) {
        exclude = solve(idx+1, arr, temp, n);
    } else {
        exclude = solve(idx+1, arr, temp, n);
        temp += arr[idx];
        include = solve(idx+1, arr, temp, n);
    }  
    return mp[temp] = max(include, exclude);
}
    
int maxLength(vector<string>& arr) {
    string temp = "";
    mp.clear();
    int n = arr.size();     
    return solve(0, arr, temp, n);
}

int main()
{
    vector<string> arr = {"un","iq","ue"};
    int ans = maxLength(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
