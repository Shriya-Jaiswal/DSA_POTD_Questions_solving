#include<iostream>
#include<math.h>
using namespace std;

// ▶️ Ask by : VMWare Oracle

string armstrongNumber(int n){
    int val=0;
    int y=n;
    while(y>0){
        val+=pow(y%10, 3);
        y/=10;
    }
    if(val==n){
        return "true";
    }
    else return "false";
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxiliary Space: O(1) 

int main()
{
    int n = 153;
    string ans = armstrongNumber(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
