#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Facebook

bool canSplit(vector<int>& arr) {
    int sum = 0, firstSum = 0;
    for(auto x:arr)sum+=x;
    for(auto x:arr){
        sum-=x;
        firstSum+=x;
        if(sum==firstSum)return true;
    }
    return false;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5};
    bool ans = canSplit(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
