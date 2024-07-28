#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

string removeDups(string str) {
    string ans="";
    bool temp[26];
    for(auto x:str){
        if(!temp[x-'a']){
            ans+=x;
            temp[x-'a']=true;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string str = "zvvo";
    string ans = removeDups(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
