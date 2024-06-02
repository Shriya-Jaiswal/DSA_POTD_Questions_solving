#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | Google

vector<int> constructList(int q, vector<vector<int>> &arr) {
    vector<int>ans;
    int x=0;
        
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i][0]==0){
            ans.push_back(x^arr[i][1]);
        }
        else{
            x^=arr[i][1];
        }
    }
    ans.push_back(0^x);
    sort(ans.begin(), ans.end());
    return ans;
}

// ⏲️ Expected Time Complexity: O(q*log(q))
// 🛢️ Expected Auxiliary Space: O(l), where l is only used for output-specific requirements.

int main()
{
    int q = 5;
    vector<vector<int>> queries = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}};
    vector<int> ans = constructList(q,queries);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
