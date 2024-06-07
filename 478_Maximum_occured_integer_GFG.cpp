#include<iostream>
#include<vector>
using namespace std;

// l and r are input array
// maxx : maximum in r[]
// n: size of array
// arr[] : declared globally with size equal to maximum in l[] and r[]
// Function to find the maximum occurred integer in all ranges.
    
int maxOccured(int n, int l[], int r[], int maxx) {
    vector<int>arr(maxx+2,0);
    for(int i=0;i<n;i++){
        arr[l[i]]++;
        arr[r[i]+1]--;
    }
        
    int sum=0;
    for(int i=0;i<=maxx;i++){
        arr[i]+=sum;
        sum=arr[i];
    }
        
    int ans=0;
    for(int i=1;i<=maxx;i++){
        if(arr[i]>arr[ans]){
            ans=i;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n+maxx).
// 🛢️ Expected Auxiliary Space: O(maxx), maxx is maximum element in r[] 

int main()
{
    int n = 4;
    int l[] = {1,4,3,1};
    int r[] = {15,8,5,4};
    int maxx = 15;

    int ans = maxOccured(n,l,r,maxx);
    cout << "ans is : " << ans << endl; 
    return 0;
}
