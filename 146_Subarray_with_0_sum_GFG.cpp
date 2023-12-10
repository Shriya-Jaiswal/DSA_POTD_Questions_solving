#include<iostream>
#include<unordered_set>
using namespace std;

// ▶️ Ask by : Paytm | Adobe

bool subArrayExists(int arr[], int n)
{
    unordered_set<int>s;
    int sum=0;
    for(int i=0;i<n;i++){
    sum=sum+arr[i];
    if(sum==0)
    return true;
    if(s.find(sum)!=s.end())
    return true;
    s.insert(sum);
    }
    return false;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
   int n = 5;
    int arr[] = {4,2,0,1,6};
    bool ans = subArrayExists(arr,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
