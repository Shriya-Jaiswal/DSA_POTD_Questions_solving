#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by Google

bool areIsomorphic(string str1, string str2){
        int n=str1.length();
        if(str2.length()!=n) return false;
        vector<int> f(26,-1);
        unordered_map<char,char>mp;
        for(int i=0;i<n;i++){
            if(mp.find(str1[i])!=mp.end()){
                if(mp[str1[i]]!=str2[i]) return false;
            }
            else{
                if(f[str2[i]-'a']!=-1 ) return false;
                else{
                    mp[str1[i]]=str2[i];
                    f[str2[i]-'a']=1;
                }
            }
        }
        return true;
}

// ⏲️ Time complexity : Expected Time Complexity: O(|str1|+|str2|)
// 🛢️ Space complexity : Expected Auxiliary Space: O(Number of different characters).
// 👉 Note: |s| represents the length of string s.

int main()
{
    string str1 = "aab";
    string str2 = "xxy";
    bool ans = areIsomorphic(str1,str2);
    cout << "ans is : " << ans << endl;
    return 0;
}
