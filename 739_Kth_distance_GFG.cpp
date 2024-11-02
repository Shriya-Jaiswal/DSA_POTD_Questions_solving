#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : Amazon

bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp[arr[i]]!=0) return true;
            
        if(i-k>=0) mp[arr[i-k]]--;
            
        mp[arr[i]]++;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 1, 2, 3, 4};
    int k = 3;
    bool ans = checkDuplicatesWithinK(arr,k);
    cout << "ans " << ans << endl;
    return 0;
}
