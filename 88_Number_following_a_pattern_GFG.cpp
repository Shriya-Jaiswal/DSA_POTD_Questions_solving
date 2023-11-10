#include<iostream>
#include<stack>
using namespace std;

string printMinNumberForPattern(string S){
     string ans="";
        stack<int> st;
        int n = S.length();
        for(int i=0;i<=n;i++){
            st.push(i+1);
            if(S[i]=='I' || i==n){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string s = "D";
    string ans = printMinNumberForPattern(s);
    cout << "ans is " << ans << endl;
    return 0;
}
