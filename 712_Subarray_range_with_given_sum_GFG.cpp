#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subArraySum(vector<int>& arr, int tar) {
    unordered_map<int,int> mm;
    int ans=0,sum=0;
    for(int x:arr){
        sum+=x;
        if(sum==tar)ans++;
        if(mm.find(sum - tar) != mm.end())ans+=mm[sum-tar];
        mm[sum]++;
    }
    return ans;
}

// ⏲  Expected Time Complexity: O(n)
// 🛢️ Expected Auxilary Space: O(n)


int main()
{
    vector<int> arr = {10, 2, -2, -20, 10};
    int tar = -10;
    int ans = subArraySum(arr,tar);
    cout << "ans is : " << ans << endl;
    return 0;
}
