#include<iostream>
#include<unordered_map>
using namespace std;

int firstElementKTime(int n, int k, int a[]){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(mp[a[i]]==k){
            return a[i];
        }
    }
    return -1;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(n).

int main()
{
    int n = 7;
    int k = 2;
    int a[] = {1, 7, 4, 3, 4, 8, 7};
    int ans = firstElementKTime(n,k,a);
    cout << "ans is : " << ans << endl;
    return 0;
}
