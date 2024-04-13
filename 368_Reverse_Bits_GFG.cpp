#include<iostream>
#include<math.h>
using namespace std;

// ▶️ Ask by : Amazon | Cisco | Qualcomm | HCL | Nvidia

long long reversedBits(long long x) {
    string str="";
    for(int i=0;i<=31;i++){
        if(x & (1<<i)){
            str='1'+str;
        }
        else{
            str='0'+str;
        }
    }
        
    long long ans=0;
    for(int i=0;i<=31;i++){
        if(str[i]=='1'){
            ans+=pow(2,i);
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(log (x))
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    long long x = 1;
    long long ans = reversedBits(x);
    cout << "ans is :" << ans << endl;
    return 0;
}
