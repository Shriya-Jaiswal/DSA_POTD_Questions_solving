#include<iostream>
#include<vector>
using namespace std;

int findWinner(int n, int x, int y) {
    vector<int>arr(n+1,0);
        arr[1]=1;
    for(int i=2;i<=n;i++){
        int j=i-1;
        if(j>=0 && arr[j]==0){
            arr[i]=1;
        }
        j=i-x;
        if(j>=0 && arr[j]==0){
            arr[i]=1;
        }
        j=i-y;
        if(j>=0 && arr[j]==0){
            arr[i]=1;
        }
    }
    return arr[n];
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int n = 5;
    int x = 3;
    int y = 4;

    int ans = findWinner(n,x,y);
    cout << "ans is : " << ans << endl;
    return 0;
}
