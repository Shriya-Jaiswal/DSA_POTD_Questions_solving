#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

vector <int> search(string pat, string txt)
{
    vector<int>ans;
    int n=txt.size();
    int m=pat.size();
    if(n<m){
        return {-1};
    }
        for(int i=0;i<n-m+1;i++){
        if(txt[i]==pat[0]){
            if(txt.substr(i,m)==pat){
                ans.push_back(i+1);
                }
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(|txt|).
// 🛢️ Expected Auxiliary Space: O(|txt|).

int main()
{
    string txt = "geeksforgeeks";
    string pat = "geek";
    vector<int> ans = search(pat, txt);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }
    cout << endl;
    return 0;
}
