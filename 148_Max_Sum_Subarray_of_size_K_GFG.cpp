#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : OYO Rooms

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    long  ans = 0, sum = 0;
    for(int i = 0; i < N; i++){
        if(i < K) 
            sum += Arr[i];
        else{
            ans = max(ans,sum);
            sum += Arr[i];
            sum -= Arr[i-K];
        }
    }
    ans = max(ans,sum);
    return ans; 
}

int main()
{
    int N = 4; 
    int K = 2;
    vector<int> arr = {100, 200, 300, 400};
    long ans = maximumSumSubarray(K,arr,N);
    cout << "ans is : " << ans << endl;
    return 0;
}
