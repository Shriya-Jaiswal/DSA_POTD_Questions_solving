#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Flipkart | Amazon | Microsoft | MakeMyTrip | Google | Streamoid Technologies | Media.net | Atlassian

string smallestWindow (string s, string p)
{
    if(p.length()>s.length())return "-1";
    int n=s.length(),m=p.length(),start=-1,end=-1,len=INT_MAX,c=0,c2=0,j=0;
    vector<int> forS(26,0),forP(26,0);
    for(int i=0;i<m;i++){
        forP[p[i]-'a']++;
        if(forP[p[i]-'a']==1)c++;
    }
    for(int i=0;i<n;i++){
        forS[s[i]-'a']++;
        if(forS[s[i]-'a']==forP[s[i]-'a'])c2++;
        if(c2==c){
            while(forS[s[j]-'a']>forP[s[j]-'a'])forS[s[j++]-'a']--;
            if(len>i-j+1){
                start=j;
                end=i;
                len=i-j+1;
            }
        }
    }
    if(start==-1)return "-1";
    return s.substr(start,len);
}

// ⏲️ Expected Time Complexity: O(|s|)
// 🛢️ Expected Auxiliary Space: O(n), n = len(p)

int main()
{
    string  s = "timetopractice";
    string  p = "toc";
    string ans = smallestWindow(s,p);
    cout << "ans is : " << ans << endl;
    return 0;
}
