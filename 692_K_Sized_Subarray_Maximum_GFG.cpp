#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// ▶️ Ask by : Flipkart | Amazon | Microsoft | Directi | Google

vector<int> max_of_subarrays(int k, vector<int> &arr) {
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<arr.size();i++){
        if(dq.size() and dq.front()==i-k)dq.pop_front();
        while(dq.size() and arr[dq.back()]<=arr[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)ans.push_back(arr[dq.front()]);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(k)

int main(int argc, char const *argv[])
{
    int k = 3;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = max_of_subarrays(k,arr);
    for(int i = 0 ; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
