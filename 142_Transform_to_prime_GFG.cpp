#include<iostream>
#include<math.h>
using namespace std;


bool isPrime(int x){
    if(x==1) return false;
    if(x==2) return true;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}

int minNumber(int arr[],int N){
    int sum=0;
    for(int i=0;i<N;i++) sum+=arr[i];
    if(isPrime(sum)) return 0;
    for(int i=sum+1;i<=2*sum;i++){
        if(isPrime(i)) return i-sum;
    }
    return 0;
}

// ⏲️ Expected Time Complexity: O(N log(log N))
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int N=5;
    int arr[] = {2, 4, 6, 8, 12};
    int ans = minNumber(arr,N);
    cout << "ans is : " << ans << endl;
    return 0;
}
