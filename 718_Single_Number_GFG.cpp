#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

int getSingle(vector<int>& arr) {
    int ans = 0;
    for(int x:arr)ans^=x;
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2};
    int ans = getSingle(arr);
    cout << "ans is : "<< ans << endl;
    return 0;
}
