#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// ◀️ Approach (Usingh stack to reverse efficiently)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(k)

queue<int> modifyQueue(queue<int> q, int k) {
    int remaining = q.size() - k; //2
    stack<int> st;
    while(k--) {
        st.push(q.front());
        q.pop();
    }
        
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
        
    while(remaining--) {
        q.push(q.front());
        q.pop();
    }
        
    return q;
}

// ⏲️ Expected Time Complexity : O(N)
// 🛢️ Expected Auxiliary Space : O(K)

int main()
{
    // int k = 3;
    // queue<int> q = {1,2,3,4,5};
    // queue<int> modifyQueue(q,k);
    return 0;
}
