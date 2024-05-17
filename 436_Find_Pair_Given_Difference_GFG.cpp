#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// ▶️ Ask by : Amazon | Visa

int findPair(int n, int x, vector<int> &arr) {
    if(x == 0){
    unordered_map<int,int> hash;
    for(auto & nums : arr){
        hash[nums] += 1;
    }
    for(auto & num : hash){
        if(num.second > 1)
            return 1;
    }
    return -1;
    }
    sort(arr.begin(),arr.end());
    int l = 0;
    int r = 1;
    while(r<n){
        int diff = abs(arr[r] - arr[l]);
        if(diff == x)
            return 1;
        else if(diff < x)
            r += 1;
        else
            l += 1;
    }
    return -1;
}

// ⏲️ Expected Time Complexity: O(n* Log(n)).
// 🛢️ Expected Auxiliary Space: O(1).

int main(){
    int n = 6;
    int x = 78;
    vector<int>arr = {5, 20, 3, 2, 5, 80};
    int ans = findPair(n,x,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
