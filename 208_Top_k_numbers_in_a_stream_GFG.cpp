#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// ▶️ Ask by : Accolite | Amazon | Media.net

vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
    vector<int> top(K + 1,0);
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[arr[i]]++;
        top[K] = arr[i];
        auto it = find(top.begin(), top.end() - 1, arr[i]);
        int index = it - top.begin() - 1;
        for (int j = index ; j >= 0; --j) {
            if (mp[top[j]] < mp[top[j + 1]])
                swap(top[j], top[j + 1]);
            else if ((mp[top[j]] == mp[top[j + 1]]) && (top[j] > top[j+1]))
                swap(top[j], top[j + 1]);
            else
                break;
        }
        vector<int>temp;
        for (int i = 0; i < K && top[i] != 0; ++i)
            temp.push_back(top[i]);
        ans.push_back(temp);
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N*K).
// 🛢️ Expected Auxiliary Space: O(N).

int main()
{
    int N=5;
    int K=4;
    vector<int> arr = {5, 2, 1, 3, 2} ;
    vector<vector<int>> ans = kTop(arr,N,K);
    for(int i=0; i< ans.size(); i++){
        for(int j= 0 ; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
