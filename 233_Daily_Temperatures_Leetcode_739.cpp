#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Microsoft ✯   C3 IoT ✯   Uber ✯   Salesforce  

// ⏲️ Time Complexity : O(n)  
// 🛢️ Space Complexity : O(n)

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> st;
    vector<int> result(n);
    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
            st.pop();
        }   
        if(st.empty()) {
            result[i] = 0;
        } else {
            result[i] = st.top() - i; //days
        }       
        st.push(i);
    }        
    return result;    
}

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
