#include<iostream>
#include<vector>
using namespace std;

int alternatingMaxLength(vector<int>& arr) {
    int des=1,inc=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1])inc=des+1;
        else if(arr[i]<arr[i-1])des=inc+1;
    }
    return max(inc,des);
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    vector<int> arr= {1, 5, 4};
    int ans = alternatingMaxLength(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
