#include<iostream>
#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Salesforce

long long findSmallest(vector<int> &arr) {
    long long ans = 1;
    for(int x:arr){
        if(x>ans)return ans;
        ans+=x;
    }
    return ans;
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {1, 2, 3};
    long long ans = findSmallest(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
