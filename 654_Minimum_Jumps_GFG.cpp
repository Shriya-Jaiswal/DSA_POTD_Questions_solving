#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Moonfrog Labs | Flipkart | Amazon | Microsoft | Housing.com | Walmart | Adobe | Google

int minJumps(vector<int>& arr) {
    if(!arr[0])return -1;
    int ans = 1, jump = arr[0], mx = 0;
    for(int i=1;i<arr.size();i++){
        mx--;
        jump--;
        mx=max(mx,arr[i]);
        if(!jump and i!=arr.size()-1){
            if(mx<=0)return -1;
            jump=mx;
            mx=0;
            ans++;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int ans = minJumps(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
