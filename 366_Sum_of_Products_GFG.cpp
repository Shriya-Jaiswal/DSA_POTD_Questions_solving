#include<iostream>
using namespace std;

long long pairAndSum(int n, long long arr[]) {
    long long ans=0;
    for(int i=0;i<32;i++){
        long long count=0;
        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i)){
                count++;
            }
        }
        ans+= (1<<i)*(count*(count-1)/2);
    }
    return ans;
}

// ⏲️ Expected Time Complexity:O(n)
// 🛢️ Expected Auxillary Space:O(1)

int main(){
    int n = 3;
    long long arr[] = {5, 10, 15};
    long long ans = pairAndSum(n,arr);
    cout << "ans is :  " << ans << endl;
    return 0;
}
