#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon | TCS

long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<arr.size();i++){
        v.push_back({abs(arr[i]-brr[i]), {arr[i], brr[i]}});
    }
    sort(v.rbegin(), v.rend());
        
    long long ans=0;
    for(int i=0;i<v.size();i++){
        if(x==0){
            ans+=v[i].second.second;
        }
        else if(y==0){
            ans+=v[i].second.first;
        }
        else{
            if(v[i].second.first > v[i].second.second){
                x--;
                ans+=v[i].second.first;
            }
            else{
                y--;
                ans+=v[i].second.second;
            }
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*logn)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int  n = 5;
    int x = 3;
    int y = 3;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> brr = {5, 4, 3, 2, 1};
    long long ans = maxTip(n,x,y,arr,brr);
    cout << "ans is : " << ans << endl;
    return 0;
}
