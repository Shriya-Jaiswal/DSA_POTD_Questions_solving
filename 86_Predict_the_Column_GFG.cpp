#include<iostream>
#include<vector>
using namespace std;


int columnWithMaxZeros(vector<vector<int>>arr,int N){
     int ans = 0;
     int col = -1;    
     for(int i=0; i<N; i++){
        int count = 0;
        for(int j=0; j<N; j++){
            if(arr[j][i] == 0){
                count ++;
                if(count > ans){
                    ans=count;
                    col=i;
                }
            }
        }
     }
     return col;
}

// ⏲️ Time complexity : Expected Time Complexity: O(N * N)
// 🛢️ space complexity : Expected Auxiliary Space: O(1)

int main()
{
    int N = 3;
    vector<vector<int>> arr= {{0, 0, 0},
                            {1, 0, 1},
                            {0, 1, 1}};
    
    int ans = columnWithMaxZeros(arr,N);
    cout << "ans is : " << ans << endl;
    return 0;
}
