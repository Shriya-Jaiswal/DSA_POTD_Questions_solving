#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// ▶️ Ask by : Zoho | Amazon | Microsoft | Qualcomm

int isValid(string s) {
    int n=s.length();
    int count=0;
    for(int i=0;i<n;i++)
    if(s[i]=='.') count++;
    if(count!=3) return 0;
            
    unordered_set<string> st;
    for(int i=0;i<=255;i++)
    st.insert(to_string(i));
    count=0;
            
    string temp="";
    for(int i=0;i<n;i++){
        if(s[i]!='.')
        temp=temp+s[i];
        else{
            if(st.count(temp)!=0) count++;
            temp="";
        }
    }
    if(st.count(temp)!=0) count++;
    if(count!=4) return 0;
            
    return 1; 
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string str = "222.111.111.111";
    int ans = isValid(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
