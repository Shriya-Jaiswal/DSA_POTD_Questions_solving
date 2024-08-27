#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

int findMaxDiff(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n),right(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() and st.top()>=arr[i])st.pop();
        if(!st.empty())left[i]=st.top();
        else left[i]=0;
        st.push(arr[i]);
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top()>=arr[i])st.pop();
        if(!st.empty())right[i]=st.top();
        else right[i]=0;
        st.push(arr[i]);
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,abs(left[i]-right[i]));
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(n)

int main()
{
    vector<int> arr = {2, 1, 8};
    int ans = findMaxDiff(arr);
    cout << "ans is : " << ans << endl; 
    return 0;
}
