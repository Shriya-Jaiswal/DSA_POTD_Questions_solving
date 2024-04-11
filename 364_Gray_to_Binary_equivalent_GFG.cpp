#include<iostream>
using namespace std;

int grayToBinary(int n){
    string st="";
    for(int i=0;i<=31;i++){
        if(n & (1<<i)){
            st='1'+st;
        }
        else{
            st='0'+st;
        }
    }
    int idx=0;
    for(int i=0;i<=31;i++){
        if(st[i]=='1'){
            idx=i;
            break;
        }
    }
    st=st.substr(idx, 32-idx);   
    string g="";
    g+=st[0];
    int a=st[0]-'0';
    for(int i=1;i<st.length();i++){
        int x=st[i]-'0';
        if(a^x){
            g=g+'1';
            a=1;
        }
        else{
            g=g+'0';
            a=0;
        }
    }
    int ans=0;
    for(int i=0;i<g.length();i++){
        ans=ans*2 + (g[i]-'0');
    }
    return ans;
}

// ▶️ Expected Time Complexity: O(log (n)).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 4;
    int ans = grayToBinary(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
