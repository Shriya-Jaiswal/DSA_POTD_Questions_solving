#include<iostream>
#include<vector>
using namespace std;

int count_set_bits(int n){
    int cnt =0;
    while(n>0){
        cnt += (n&1);
        n =n/2; // 👉 n = n>>2
    }
    return cnt;
}

int is_bleak(int n)
{
	for(int i = n-30; i<=n; i++){
        if(i+count_set_bits(i)==n){
            return 0;
        }
    }
    return 1;
}

// ⏲️ Time complexity :  Expected Time Complexity: O(log(n) * log(n))
// 🛢️ space complexity :  Expected Space Complexity: O(1)

int main()
{
    int n =4;
    int ans = is_bleak(n);
    cout<< "ans is : " << ans << endl;
    return 0;
}
