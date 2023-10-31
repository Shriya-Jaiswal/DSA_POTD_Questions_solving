#include<iostream>
#include<vector>
using namespace std;

// 👉 Bit manipulation ----> Leetcode 2333 ---> medium
// ▶️ Ask by Microsoft


// ➡️ XOR
// 👉 Associative properties => (a^b)^c = a^(b^c)
// 👉 commutative properties => (a^b)=(b^a)
// 👉 1^1 = 0
// 👉 1^0 = 1
// 👉 0^1 = 1
// 👉 0^0 = 0

vector<int> findArray(vector<int>& pref) {
    int n = pref.size();

    vector<int> arr;

    arr.push_back(pref[0]);

    for(int i=1; i<n; i++){
        arr.push_back(pref[i] ^ pref[i-1]);
    }
    return arr;
}
// ⏲️ Time complexity : O(n)


vector<int> findArray_Approach_2(vector<int>& pref) {
    int n = pref.size();
     for(int i=n-1; i>0; i--){
        pref[i] = pref[i]^pref[i-1];
    }
    return pref;
}

int main()
{
    vector<int> pref {5,2,0,3,1};
    vector<int> ans = findArray(pref);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;

    // // ➡️ approach 2
    // vector<int> ans1 = findArray_Approach_2(pref);
    // for(int i=0; i<ans1.size(); i++){
    //     cout<< ans1[i] << " ";
    // }
    // cout<< endl;


    return 0;
}
