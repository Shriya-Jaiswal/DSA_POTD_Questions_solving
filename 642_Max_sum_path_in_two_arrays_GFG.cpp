#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon

int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
    int i=0,j=0,sum1=0,sum2=0,ans=0;
    while(i<arr1.size() and j<arr2.size()){
        if(arr1[i]<arr2[j])sum1+=arr1[i++];
        else if(arr1[i]>arr2[j])sum2+=arr2[j++];
        else{
            ans+=max(sum1,sum2)+arr1[i];
            i++;
            j++;
            sum1=0,sum2=0;
        }
    }
    while(i<arr1.size())sum1+=arr1[i++];
    while(j<arr2.size())sum2+=arr2[j++];
    return ans+max(sum1,sum2);
}

// ⏲️ Expected Time Complexity: O(m + n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int>  arr1 = {2, 3, 7, 10, 12}; 
    vector<int> arr2 = {1, 5, 7, 8};
    int ans = maxPathSum(arr1,arr2);
    cout << "ans is : " << ans << endl;
    return 0;
}
