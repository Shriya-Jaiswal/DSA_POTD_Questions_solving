#include<iostream>
#include<map>
using namespace std;


int kSubstrConcat (int n, string s, int k)
{
	if(n%k)
    return 0;
        
    map<string,int>mpp;
    string temp="";
    temp+=s[0];
        
    for(int i=1;i<n;i++){
        if(i%k==0){
            mpp[temp]++;
            temp="";
         }
        temp+=s[i];
    }
    mpp[temp]++;
        
    if(mpp.size()>2)
     return 0;
        
    // for cases like k=2 & s=bbccbbcc.
    int count=0;
    for(auto it:mpp){
        if(it.second>1)
            count++;
    }
        
    if(count>1)
        return 0;        
    return 1;
}


// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    int n = 4;
    int k = 2;
    string s = "bdac";
    int ans = kSubstrConcat(n,s,k);
    cout << "ans is : " << ans << endl;

    return 0;
}
