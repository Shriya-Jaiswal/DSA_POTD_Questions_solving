#include<iostream>
#include<vector>
using namespace std;


// ▶️ Approach (Better than brute force)
// ⏲️ T.C : O(n^2)
// 🛢️ S.C : O(n)

int countTriplets(vector<int>& arr) {
    vector<int> prefixXor(begin(arr), end(arr));
    prefixXor.insert(prefixXor.begin(), 0); //initially the xor cumulative will be 0
    int n = prefixXor.size();
    for(int i = 1; i < n; i++) {
        prefixXor[i] ^= prefixXor[i-1];
    }
    int triplets = 0;
    for(int i = 0; i < n; i++) {
        for(int k = i+1; k < n; k++) {
            if(prefixXor[k] == prefixXor[i]) {
                triplets += k-i-1;
            }
        }
    }
    return triplets;
}

int main()
{
    vector<int>  arr = {2,3,1,6,7};
    int ans = countTriplets(arr) ;
    cout << "ans is : " << ans << endl;
    return 0;
}
