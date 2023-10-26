#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int MOD = 1e9 + 7;

int numFactoredBinaryTrees(vector<int>& arr) {
    int n = arr.size();

    sort(begin(arr),end(arr));   
    unordered_map<int,long long> mp;
    mp[arr[0]] = 1;

    for(int i=1; i<n; i++){
        int root = arr[i];
        mp[root] = 1;

        for(int j=0; j<i; j++){ // 👉 Similar to Longest increasing subsequence
            int leftChild = arr[j];
            // 👉 RightChild = arr[i]/Leftchild
            if(root % leftChild == 0 && mp.find(arr[i]/leftChild) != mp.end()){
                mp[root] += mp[leftChild] * mp[arr[i]/leftChild];
            }
        }
    }     
    long result =0;
    // 👉 value = number of binary trees
    for(auto &it :mp){
        // 👉 it.first = value
        // 👉 it.second = ways
        result = (result + it.second) % MOD;
    }
    return result;
}

int main()
{
    vector<int> arr = {2,4};
    int ans = numFactoredBinaryTrees(arr);
    cout<< "ans is : " << ans << endl;
    return 0;
}
