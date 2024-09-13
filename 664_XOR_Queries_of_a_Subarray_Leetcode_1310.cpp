#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Airtel ✯  

// ▶️ Approach (Simple XOR Property & Cumulative Xor)
// ⏲️ Time Complexity : O(n+q)
// 🛢️ Space Complexity : O(n)

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();

    vector<int> cumXor(n, 0); // 👉 space : O(n)

    cumXor[0] = arr[0];
    for(int i = 1; i < n; i++) { // 👉 O(n)
        cumXor[i] = cumXor[i-1] ^ arr[i];
    }

    vector<int> result;
    for(vector<int>& query : queries) { // 👉 O(q)
        int L = query[0];
        int R = query[1];

        int xor_val = cumXor[R] ^ (L == 0 ? 0 : cumXor[L-1]);

        result.push_back(xor_val);
    }

    return result;
}

int main()
{
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int> ans =  xorQueries(arr,queries);
    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
