#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// ▶️ Ask by :  Google ✯   Affinity ✯  

// ▶️ Approach (Using stack)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

char solveOp(char op, vector<char>& values) {
    if (op == '!') 
        return values[0] == 't' ? 'f' : 't';
    
    if (op == '&') 
        return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
    
    if (op == '|') 
        return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';
    
    return 't'; // Unreachable
}

bool parseBoolExpr(string s) {
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == ',') continue;

        if (s[i] == ')') {
            vector<char> values;
            // Gather all values inside the parentheses
            while (st.top() != '(') {
                values.push_back(st.top());
                st.pop();
            }
            st.pop();  // Remove '('
            char op = st.top();
            st.pop();  // Remove the operator
            st.push(solveOp(op, values));
        } else {
            st.push(s[i]);
        }
    }
    return (st.top() == 't');
}

int main()
{
    string expression = "&(|(f))";
    bool ans = parseBoolExpr(expression);
    cout << "ans is : " << ans << endl;
    return 0;
}
