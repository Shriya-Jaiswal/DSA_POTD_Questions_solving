#include<iostream>
using namespace std;

int posOfRightMostDiffBit(int m, int n)
{
    if(m==n) return -1;
        int ans=1;
        // while( m >0 || n>0){
        //     if( (m&1) != (n&1) ){
        //         return ans;
        //     }
        //     m=m>>1;
        //     n=n>>1;
        //     ans++;
        // }
        
        int num=m^n;
        while(num>0){
            if(num&1) return ans;
            num=num>>1;
            ans++;
        }
        
        return ans;
}

// ⏲️ Expected Time Complexity: O(max(log M, log N)).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int M = 11;
    int N = 9;
    int ans = posOfRightMostDiffBit(M,N);
    cout << "ans is : " << ans << endl;
    return 0;
}
