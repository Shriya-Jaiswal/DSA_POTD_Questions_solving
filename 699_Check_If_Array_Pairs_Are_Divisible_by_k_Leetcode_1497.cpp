#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Quble ✯  

// ▶️ Approach-(simple remainder maths)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(k)

bool canArrange(vector<int>& arr, int k) {
    vector<int> mp(k, 0); //O(K)
    //mp[r] = x
    //remainder r has frequency x

    for(int &num : arr) {
        int rem = (num%k + k) % k; //handling negative remainders
        mp[rem]++;
    }

    if(mp[0] % 2 != 0) {
        return false;
    }

    for(int rem = 1; rem <= k/2; rem++) {
        int counterHalf = k - rem;
        if(mp[counterHalf] != mp[rem]) {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    bool ans = canArrange(arr,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
