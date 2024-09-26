#include<iostream>
#include<vector>
using namespace std;

int maxStep(vector<int>& arr) {
    int ans = 0, increaseCount = 0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1])increaseCount++;
        else{
            ans=max(ans,increaseCount);
            increaseCount=0;
        }
    }
    ans=max(ans,increaseCount);
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr= {1, 2, 2, 3, 2};
    int ans = maxStep(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
