#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> bracketNumbers(string str) {
    vector<int>ans;
    stack<int>st;
    int val=1;
    for(int i=0;i<str.length();i++){
            if(str[i]=='('){
            ans.push_back(val);
            st.push(val);
            val++;
        }
        else if(str[i]==')'){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

int main()
{
    string str = "(aa(bdc))p(dee)";
    vector<int> ans = bracketNumbers(str);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
