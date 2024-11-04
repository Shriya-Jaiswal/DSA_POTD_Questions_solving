#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : 

vector<vector<int>> findTriplets(vector<int> &arr) {
    vector<vector<int>> ans;
            for(int i=0; i<arr.size(); i++){
                for(int j=i+1; j<arr.size(); j++){
                    for(int k=j+1; k<arr.size(); k++){
                        if(arr[i]+arr[j]+arr[k] == 0){
                            ans.push_back({i, j, k});
                        }
                    }
                }
            }
            return ans;
}

int main()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> ans = findTriplets(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
