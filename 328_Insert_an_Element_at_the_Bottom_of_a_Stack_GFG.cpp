#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> insertAtBottom(stack<int> st,int x){
    stack<int>aux;
    while(!st.empty()){
        aux.push(st.top());
        st.pop();
    }
        
    st.push(x);
        
    while(!aux.empty()){
        st.push(aux.top());
        aux.pop();
    }
    return st;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    // stack<int> st = {4,3,2,1,8};
    // int x = 2;
    // stack<int> ans = insertAtBottom(st,x);

    return 0;
}
