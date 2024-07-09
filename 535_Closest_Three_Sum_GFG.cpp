#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | Google | Apple

int threeSumClosest(vector<int> arr, int target) {
    int diff = INT_MAX;
    int ans = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++){
        int j=i+1,k=arr.size()-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            int d = abs(sum-target);
            if(d<diff){
                diff=d;
                ans=sum;
            }
            else if(d==diff){
                ans=max(ans,sum);
            }
            if(sum<target)j++;
            else if(sum==target)return sum;
            else k--;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {-7, 9, 8, 3, 1, 1};
    int target = 2;
    int ans = threeSumClosest(arr,target);
    cout << "ans is : " << ans << endl;
    return 0;
}
