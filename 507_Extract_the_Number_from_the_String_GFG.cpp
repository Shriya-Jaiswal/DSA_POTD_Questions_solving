#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : TCS

long long ExtractNumber(string s) {
    long long ans=-1;
    long long curr=0;
    int i=0, n=s.length();
    while(i<n){
        curr=0;
        bool flag=true;
        while(i<n && s[i]!=' '){
            if(flag && s[i]>='0' && s[i]<='8'){
                curr=curr*10+(s[i]-'0');
            }
            else{
                flag=false;
            }
            i++;
        }
        i++;
        if(flag){
            ans=max(ans, curr);
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxillary Space: O(n)

int main()
{
    string sentence="This is alpha 5057 and 97";
    long long ans = ExtractNumber(sentence);
    cout << "ans is : " << ans << endl;
    return 0;
}
