#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

vector<int> findSplit(vector<int>& arr) {
    int n = arr.size(), sum=0;
    for(int x:arr)sum+=x;
    if(sum%3)return {-1,-1};
    int requiredSum=sum/3;
    vector<int> ans;
    sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==requiredSum){
            ans.push_back(i);
            if(ans.size()==2)break;
            sum=0;
        }
    }
    if(ans.size()==2)return ans;
    return {-1,-1};
}


int main()
{
    vector<int> arr = {1, 3, 4, 0, 4};
    vector<int> ans = findSplit(arr);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " "; 
    }
    cout << endl;

    return 0;
}
