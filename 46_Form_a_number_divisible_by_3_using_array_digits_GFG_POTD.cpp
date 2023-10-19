#include<iostream>
#include<vector>
using namespace std;

int isPossible(int N, int arr[]) {
    long long sum = 0;
    for(int i=0; i<N; i++){
        sum += arr[i];
    }
    return sum % 3 == 0;
}

// ⏲️ Time Complexity ---> Expected Time Complexity: O(N)
// 🛢️ space complexity ---> Expected Auxiliary Space: O(1)

int main()
{
    int N = 3;
    int arr[] = {40, 50, 90};
    int ans = isPossible(N,arr);
    cout<< "ans is : " << ans << endl;
    return 0;
}
