#include<iostream>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Amazon

int findSwapValues(int a[], int n, int b[], int m) {
    int suma=0, sumb=0;
    for(int i=0;i<n;i++) suma+=a[i];
    for(int i=0;i<m;i++) sumb+=b[i];
        
    if((suma-sumb)%2!=0) return -1;
    int target=(suma-sumb)/2;
    int i=0, j=0;
    sort(a, a+n);
    sort(b, b+m);
    while(i<n && j<m){
        int diff=a[i]-b[j];
        if(diff==target) return 1;
        else if(diff<target) i++;
        else j++;
    }
    return -1;
}

// ▶️ Expected Time Complexity: O(mlogm+nlogn).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 6;
    int m = 4;
    int a[] = {4, 1, 2, 1, 1, 2};
    int b[] = {3, 6, 3, 3};

    int ans = findSwapValues(a,n,b,m);
    cout << "ans is : " << ans << endl;
    return 0;
}
