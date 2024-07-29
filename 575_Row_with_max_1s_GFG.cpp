#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | Snapdeal

int rowWithMax1s(vector<vector<int> > arr) {
    int ans=-1;
    int n=arr.size();
    int m=arr[0].size();
    int i=0;
    int j=m-1;
    while(i<n && j>=0){
        if(arr[i][j]==1){
            ans=i;
            j--;
        }
        else{
            i++;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n+m)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1},
                                {0, 0, 1, 1},
                                {1, 1, 1, 1},
                                {0, 0, 0, 0}};

    int ans = rowWithMax1s(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
