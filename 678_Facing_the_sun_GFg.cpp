#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

int countBuildings(vector<int> &height) {
    int ans = 1, mx = height[0];
    for(auto x:height){
        if(x>mx){
            mx=x;
            ans++;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)


int main()
{
    vector<int>  height = {7, 4, 8, 2, 9};
    int ans = countBuildings(height);
    cout << "ans is : " << ans << endl;
    return 0;
}
