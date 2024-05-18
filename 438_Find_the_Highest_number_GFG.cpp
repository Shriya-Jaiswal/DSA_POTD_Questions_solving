#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

int findPeakElement(vector<int>& a) 
{
    int lo=0, hi=a.size()-1;
        
    int ans=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        ans=max(ans, a[mid]);
            
        if(mid==0) lo=mid+1;
        else if(mid==a.size()-1) hi=mid-1;
        else if(a[mid]<a[mid+1]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
        
    return ans;
}

// ⏲️ Expected Time Complexity: O(log(n))
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1,};
    int ans = findPeakElement(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
