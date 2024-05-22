#include<iostream>
#include<vector>
using namespace std;

bool check(double mid, vector<int>&arr, int k){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n;i++){
        int dist=arr[i]-arr[i-1];
        if(dist<=mid){
            continue;
        }
        else{
            count+=int(dist/mid);
        }
    }
    return count<=k;
}
  
double findSmallestMaxDist(vector<int> &stations, int k) {
    // Code here
    int n=stations.size();
    double lo=0.0;
    double hi=0.0;
    for(int i=1;i<n;i++){
        if(hi<stations[i]-stations[i-1]){
            hi=stations[i]-stations[i-1];
        }
    }
    double ans=hi;
    while(hi-lo>1e-9){
        double mid= (hi-lo)/2.0 + lo;
        if(check(mid, stations, k)){
            ans=mid;
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*log k)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    double ans = findSmallestMaxDist(stations,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
